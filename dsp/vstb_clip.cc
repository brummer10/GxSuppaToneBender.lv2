// generated from file './/vstb_clip.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace vstb_clip {

template <int tab_size>
struct table1d_imp { // 1-dimensional clipping table
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
};

static table1d_imp<100> clip __rt_data = {
	0.005,0.795235013262,101.97,100, {
	0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,
	0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,
	0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,
	0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,
	0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,
	0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,
	0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,
	0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,
	0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,
	0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,
	0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,
	0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,
	0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,
	0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,
	0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,
	0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,
	0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,
	0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,
	0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,
	0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262
	}
};

#define MAX_UPSAMPLE 8

class SimpleResampler
{
private:
  Resampler r_up, r_down;
  int32_t m_fact;
  int32_t ratio_a;
  int32_t ratio_b;
  static uint32_t gcd (int32_t a, int32_t b);
public:
  SimpleResampler(): r_up(), r_down(), m_fact() {}
  void setup(int32_t sampleRate, uint32_t fact);
  int32_t up(int32_t count, float *input, float *output);
  void down(int32_t count, float *input, float *output);
  int32_t get_max_out_size(int32_t i_size)
  {
    return (i_size * ratio_b) / ratio_a + 1;
  }
};

uint32_t SimpleResampler::gcd (int32_t a, int32_t b)
{
  if (a == 0) return b;
  if (b == 0) return a;
  while (1)
    {
      if (a > b)
        {
          a = a % b;
          if (a == 0) return b;
          if (a == 1) return 1;
        }
      else
        {
          b = b % a;
          if (b == 0) return a;
          if (b == 1) return 1;
        }
    }
  return 1;
}

void SimpleResampler::setup(int32_t sampleRate, uint32_t factum)
{
  int32_t fact = static_cast<int32_t>(factum);
  int32_t d = gcd(sampleRate, sampleRate*fact);
  ratio_a = sampleRate / d;
  ratio_b = (sampleRate*fact) / d;

  assert(fact <= MAX_UPSAMPLE);
  m_fact = fact;
  const int32_t qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
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
  // std::cout<<"SimpleResampler::setup "<<sampleRate<<" "<<fact<<std::endl;
}

int32_t SimpleResampler::up(int32_t count, float *input, float *output)
{
  r_up.inp_count = count;
  r_up.inp_data = input;
  int m = get_max_out_size(count);
  r_up.out_count = m;
  r_up.out_data = output;
  r_up.process();
  assert(r_up.inp_count == 0);
  assert(r_up.out_count <= 1);
  r_down.inp_count = m - r_up.out_count;
  return r_down.inp_count;
}

void SimpleResampler::down(int32_t count, float *input, float *output)
{
  r_down.inp_count = count * m_fact;
  r_down.inp_data = input;
  r_down.out_count = count+1; // +1 == trick to drain input
  r_down.out_data = output;
  r_down.process();
  assert(r_down.inp_count == 0);
  assert(r_down.out_count == 1);
}

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	SimpleResampler res;

	void connect(uint32_t port,void* data);
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static double symclip(double x);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "vstb";
	name = N_("Vox Suppa Tonebender");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = 0;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
    res.setup(samplingFreq,4);
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

double always_inline Dsp::symclip(double x) {
    double f = fabs(x);
    f = (f - clip.low) * clip.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = clip.data[0];
    } else if (i >= clip.size-1) {
        f = clip.data[clip.size-1];
    } else {
	f -= i;
	f = clip.data[i]*(1-f) + clip.data[i+1]*f;
    }
    return copysign(f, -x);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
    int rescount = res.get_max_out_size(count);
    float buf[rescount];
    res.up(count,input0,buf);
	for (int i=0; i<rescount; i++) {
        double fTemp0 = buf[i];
		buf[i] = symclip(fTemp0);
	}
    res.down(count,buf,output0);
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
} PortIndex;
*/

} // end namespace vstb_clip
