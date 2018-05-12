/*
 * Copyright (C) 2014 Guitarix project MOD project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cassert>
#include <unistd.h>

///////////////////////// MACRO SUPPORT ////////////////////////////////

#define __rt_func __attribute__((section(".rt.text")))
#define __rt_data __attribute__((section(".rt.data")))

///////////////////////// FAUST SUPPORT ////////////////////////////////

#define FAUSTFLOAT float
#ifndef N_
#define N_(String) (String)
#endif
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

#define always_inline inline __attribute__((always_inline))

template <int32_t N> inline float faustpower(float x)
{
  return powf(x, N);
}
template <int32_t N> inline double faustpower(double x)
{
  return pow(x, N);
}
template <int32_t N> inline int32_t faustpower(int32_t x)
{
  return faustpower<N/2>(x) * faustpower<N-N/2>(x);
}
template <>      inline int32_t faustpower<0>(int32_t x)
{
  return 1;
}
template <>      inline int32_t faustpower<1>(int32_t x)
{
  return x;
}

////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_vstb.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "resampler.cc"   // define struct PluginLV2
#include "resampler-table.cc"   // define struct PluginLV2
#include "zita-resampler/resampler.h"
#include "vstb_p1.cc"    // dsp class generated by faust -> dsp2cc
#include "vstb_clip.cc"    // dsp class generated by faust -> dsp2cc
#include "vstb_p2.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace vstb {

class SimpleResampler {
 private:
    Resampler r_up, r_down;
    int m_fact;
 public:
    SimpleResampler(): r_up(), r_down(), m_fact() {}
    void setup(int sampleRate, unsigned int fact);
    void up(int count, float *input, float *output);
    void down(int count, float *input, float *output);
};

void SimpleResampler::setup(int sampleRate, unsigned int fact)
{
	m_fact = fact;
	const int qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
	// upsampler
	r_up.setup(sampleRate, sampleRate*fact, 1, qual);
	// k == inpsize() == 2 * qual
	// pre-fill with k-1 zeros
	r_up.inp_count = r_up.inpsize() - 1;
	r_up.out_count = 1;
	r_up.inp_data = r_up.out_data = 0;
	r_up.process();
	// downsampler
	r_down.setup(sampleRate*fact, sampleRate, 1, qual);
	// k == inpsize() == 2 * qual * fact
	// pre-fill with k-1 zeros
	r_down.inp_count = r_down.inpsize() - 1;
	r_down.out_count = 1;
	r_down.inp_data = r_down.out_data = 0;
	r_down.process();
}

void SimpleResampler::up(int count, float *input, float *output)
{
	r_up.inp_count = count;
	r_up.inp_data = input;
	r_up.out_count = count * m_fact;
	r_up.out_data = output;
	r_up.process();
	assert(r_up.inp_count == 0);
	assert(r_up.out_count == 0);
}

void SimpleResampler::down(int count, float *input, float *output)
{
	r_down.inp_count = count * m_fact;
	r_down.inp_data = input;
	r_down.out_count = count+1; // +1 == trick to drain input
	r_down.out_data = output;
	r_down.process();
	assert(r_down.inp_count == 0);
	assert(r_down.out_count == 1);
}

class Gx_vstb_
{
private:
  // pointer to buffer
  float*      output;
  float*      input;
  // pointer to dsp class
  PluginLV2*  vstb_p1;
  PluginLV2*  vstb_clip;
  PluginLV2*  vstb_p2;
  uint32_t fSamplingFreq;
  SimpleResampler smp;
  unsigned int fact;
  // private functions
  inline void run_dsp_(uint32_t n_samples);
  inline void connect_(uint32_t port,void* data);
  inline void init_dsp_(uint32_t rate);
  inline void connect_all__ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();

public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  Gx_vstb_();
  ~Gx_vstb_();
};

// constructor
Gx_vstb_::Gx_vstb_() :
  output(NULL),
  input(NULL),
  vstb_p1(vstb_p1::plugin()),
  vstb_clip(vstb_clip::plugin()),
  vstb_p2(vstb_p2::plugin()) {};

// destructor
Gx_vstb_::~Gx_vstb_()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (vstb_p1->activate_plugin !=0)
    vstb_p1->activate_plugin(false, vstb_p1);
  // delete DSP class
  vstb_p1->delete_instance(vstb_p1);
  if (vstb_clip->activate_plugin !=0)
    vstb_clip->activate_plugin(false, vstb_clip);
  // delete DSP class
  vstb_clip->delete_instance(vstb_clip);
  if (vstb_p2->activate_plugin !=0)
    vstb_p2->activate_plugin(false, vstb_p2);
  // delete DSP class
  vstb_p2->delete_instance(vstb_p2);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Gx_vstb_::init_dsp_(uint32_t rate)
{
  fSamplingFreq = rate;
  // samplerate check
  fact = fSamplingFreq/48000;
  if (fact>1) {
    smp.setup(fSamplingFreq, fact);
    fSamplingFreq = 48000;
  }
  vstb_p1->set_samplerate(fSamplingFreq, vstb_p1); // init the DSP class
  vstb_clip->set_samplerate(fSamplingFreq, vstb_clip); // init the DSP class
  vstb_p2->set_samplerate(fSamplingFreq, vstb_p2); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_vstb_::connect_(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_vstb_::activate_f()
{
  // allocate the internal DSP mem
  if (vstb_p1->activate_plugin !=0)
    vstb_p1->activate_plugin(true, vstb_p1);
  if (vstb_clip->activate_plugin !=0)
    vstb_clip->activate_plugin(true, vstb_clip);
  if (vstb_p2->activate_plugin !=0)
    vstb_p2->activate_plugin(true, vstb_p2);
}

void Gx_vstb_::clean_up()
{
  // delete the internal DSP mem
  if (vstb_p1->activate_plugin !=0)
    vstb_p1->activate_plugin(false, vstb_p1);
  if (vstb_clip->activate_plugin !=0)
    vstb_clip->activate_plugin(false, vstb_clip);
  if (vstb_p2->activate_plugin !=0)
    vstb_p2->activate_plugin(false, vstb_p2);
}

void Gx_vstb_::deactivate_f()
{
  // delete the internal DSP mem
  if (vstb_p1->activate_plugin !=0)
    vstb_p1->activate_plugin(false, vstb_p1);
  if (vstb_clip->activate_plugin !=0)
    vstb_clip->activate_plugin(false, vstb_clip);
  if (vstb_p2->activate_plugin !=0)
    vstb_p2->activate_plugin(false, vstb_p2);
}

void Gx_vstb_::run_dsp_(uint32_t n_samples)
{
  uint32_t ReCount = n_samples;
  if (fact>1) {
    ReCount = n_samples/fact ;
  }
  FAUSTFLOAT buf[ReCount];
  if (fact>1) {
     smp.down(ReCount, input, buf);
  } else {
    memcpy(buf, input, n_samples*sizeof(float));
  }
  vstb_p1->mono_audio(static_cast<int>(ReCount), buf, buf, vstb_p1);
  vstb_clip->mono_audio(static_cast<int>(ReCount), buf, buf, vstb_clip);
  vstb_p2->mono_audio(static_cast<int>(ReCount), buf, buf, vstb_p2);
  if (fact>1) {
    smp.up(ReCount, buf, output);
  } else {
    memcpy(output, buf, n_samples*sizeof(float));
  }
}

void Gx_vstb_::connect_all__ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_(port,data); 
  // connect the Ports used by the DSP class
  vstb_p1->connect_ports(port,  data, vstb_p1);
  vstb_clip->connect_ports(port,  data, vstb_clip);
  vstb_p2->connect_ports(port,  data, vstb_p2);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Gx_vstb_::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_vstb_ *self = new Gx_vstb_();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_vstb_::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<Gx_vstb_*>(instance)->connect_all__ports(port, data);
}

void Gx_vstb_::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_vstb_*>(instance)->activate_f();
}

void Gx_vstb_::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_vstb_*>(instance)->run_dsp_(n_samples);
}

void Gx_vstb_::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_vstb_*>(instance)->deactivate_f();
}

void Gx_vstb_::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_vstb_* self = static_cast<Gx_vstb_*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gx_vstb_::descriptor =
{
  GXPLUGIN_URI "#_vstb_",
  Gx_vstb_::instantiate,
  Gx_vstb_::connect_port,
  Gx_vstb_::activate,
  Gx_vstb_::run,
  Gx_vstb_::deactivate,
  Gx_vstb_::cleanup,
  NULL
};


} // end namespace vstb

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &vstb::Gx_vstb_::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
