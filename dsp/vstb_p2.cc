// generated from file './/vstb_p2.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace vstb_p2 {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec2[2];
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fVec0[2];
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fRec4[2];
	double 	fRec3[3];
	double 	fConst19;
	double 	fConst20;
	double 	fVec1[2];
	double 	fRec1[2];
	double 	fRec0[3];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec5[2];
	double 	fConst21;

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
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
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = min(1.92e+05, max(1.0, (double)fSamplingFreq));
	fConst1 = double(fConst0);
	fConst2 = (4.33446443970093e-10 * fConst1);
	fConst3 = (6.64102771877882e-08 + (fConst1 * (fConst2 - 2.79026392214162e-08)));
	fConst4 = faustpower<2>(fConst1);
	fConst5 = (1.32820554375576e-07 - (8.66892887940187e-10 * fConst4));
	fConst6 = (6.64102771877882e-08 + (fConst1 * (2.79026392214162e-08 + fConst2)));
	fConst7 = (1.0 / fConst6);
	fConst8 = ((3.57544794530464e-10 * fConst4) - 0.00576313337412095);
	fConst9 = (1.96649636991755e-06 * fConst1);
	fConst10 = (0.00766496738758086 - fConst9);
	fConst11 = (3.57544794530464e-10 * fConst1);
	fConst12 = (0.00824128072499296 + (fConst1 * (fConst11 - 3.49948984743372e-06)));
	fConst13 = (7.15089589060927e-10 * fConst4);
	fConst14 = (0.0164825614499859 - fConst13);
	fConst15 = (1.0 / (0.00824128072499296 + (fConst1 * (3.49948984743372e-06 + fConst11))));
	fConst16 = (491.77839701345533 / fConst0);
	fConst17 = (1 - fConst16);
	fConst18 = (1.0 / (1 + fConst16));
	fConst19 = (0.00766496738758086 + fConst9);
	fConst20 = (0 - (0.0115262667482419 + fConst13));
	fConst21 = (fConst4 / fConst6);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (4.748558434412966e-05 * (exp((5 * double(fslider1))) - 1));
	for (int i=0; i<count; i++) {
		fRec2[0] = (fSlow0 + (0.993 * fRec2[1]));
		double fTemp0 = (fConst8 * fRec2[0]);
		double fTemp1 = (double)input0[i];
		fVec0[0] = fTemp1;
		fRec4[0] = (fConst18 * ((fVec0[0] + (fConst17 * fRec4[1])) - fVec0[1]));
		fRec3[0] = (fRec4[0] - (fConst15 * ((fConst14 * fRec3[1]) + (fConst12 * fRec3[2]))));
		double fTemp2 = (((fRec3[1] * (0.0153299347751617 + (fConst20 * fRec2[0]))) + (fRec3[0] * (fConst19 + fTemp0))) + (fRec3[2] * (fConst10 + fTemp0)));
		fVec1[0] = fTemp2;
		fRec1[0] = (fConst18 * ((fConst17 * fRec1[1]) + (fConst15 * (fVec1[0] - fVec1[1]))));
		fRec0[0] = (fRec1[0] - (fConst7 * ((fConst5 * fRec0[1]) + (fConst3 * fRec0[2]))));
		fRec5[0] = (fSlow1 + (0.993 * fRec5[1]));
		output0[i] = (FAUSTFLOAT)(fConst21 * ((1.56131797691992e-09 * (fRec0[1] * fRec5[0])) + ((0 - (7.80658988459958e-10 * fRec5[0])) * (fRec0[2] + fRec0[0]))));
		// post processing
		fRec5[1] = fRec5[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fVec1[1] = fVec1[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fVec0[1] = fVec0[0];
		fRec2[1] = fRec2[0];
	}
#undef fslider0
#undef fslider1
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case TONE: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
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
   TONE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace vstb_p2
