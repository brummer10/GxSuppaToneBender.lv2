// generated from file './/vstb_p1.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace vstb_p1 {

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
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec2[2];
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fVec0[2];
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fRec4[2];
	double 	fRec3[4];
	double 	fVec1[2];
	double 	fConst28;
	double 	fRec1[2];
	double 	fRec0[3];
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;

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
	for (int i=0; i<4; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
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
	fConst2 = (3.86926254292528e-10 * fConst1);
	fConst3 = (0.000493239810103676 + (fConst1 * (fConst2 - 2.25059729791483e-06)));
	fConst4 = faustpower<2>(fConst1);
	fConst5 = (0.000986479620207351 - (7.73852508585056e-10 * fConst4));
	fConst6 = (1.0 / (0.000493239810103676 + (fConst1 * (2.25059729791483e-06 + fConst2))));
	fConst7 = (4.50637775095333e-15 * fConst1);
	fConst8 = (0 - (6.77786767851286e-12 + fConst7));
	fConst9 = (4.15046128373515e-15 * fConst1);
	fConst10 = (8.46680048007635e-12 + fConst9);
	fConst11 = (7.67178566962075e-15 * fConst1);
	fConst12 = (1.00879990793734e-08 + (fConst1 * (1.74623910300109e-11 + fConst11)));
	fConst13 = (fConst7 - 6.77786767851286e-12);
	fConst14 = (8.46680048007635e-12 - fConst9);
	fConst15 = ((fConst1 * (1.74623910300109e-11 - fConst11)) - 1.00879990793734e-08);
	fConst16 = (1.351913325286e-14 * fConst1);
	fConst17 = (6.77786767851286e-12 - fConst16);
	fConst18 = (1.24513838512054e-14 * fConst1);
	fConst19 = (fConst18 - 8.46680048007635e-12);
	fConst20 = (2.30153570088622e-14 * fConst1);
	fConst21 = ((fConst1 * (fConst20 - 1.74623910300109e-11)) - 1.00879990793734e-08);
	fConst22 = (6.77786767851286e-12 + fConst16);
	fConst23 = (0 - (8.46680048007635e-12 + fConst18));
	fConst24 = (1.00879990793734e-08 + (fConst1 * (0 - (1.74623910300109e-11 + fConst20))));
	fConst25 = (491.77839701345533 / fConst0);
	fConst26 = (1 - fConst25);
	fConst27 = (1.0 / (1 + fConst25));
	fConst28 = faustpower<3>(fConst1);
	fConst29 = (1.98269861157228e-11 * fConst1);
	fConst30 = (3.85497374759958e-05 + fConst29);
	fConst31 = (fConst29 - 3.85497374759958e-05);
	fConst32 = (0 - (3.96539722314456e-11 * fConst4));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
	double 	fSlow0 = (4.748558434412966e-05 * (exp((5 * double(fslider0))) - 1));
	for (int i=0; i<count; i++) {
		fRec2[0] = (fSlow0 + (0.993 * fRec2[1]));
		double fTemp0 = (1.69446691962822e-06 + (fConst1 * (fConst12 + (fRec2[0] * (3.38893383925643e-09 + (fConst1 * (fConst10 + (fConst8 * fRec2[0]))))))));
		double fTemp1 = (5.91454523813446e-15 + (5.91454523813446e-14 * fRec2[0]));
		double fTemp2 = (double)input0[i];
		fVec0[0] = fTemp2;
		fRec4[0] = (fConst27 * ((fVec0[0] + (fConst26 * fRec4[1])) - fVec0[1]));
		fRec3[0] = (fRec4[0] - ((((fRec3[1] * (5.08340075888465e-06 + (fConst1 * (fConst24 + (fRec2[0] * (3.38893383925643e-09 + (fConst1 * (fConst23 + (fConst22 * fRec2[0]))))))))) + (fRec3[2] * (5.08340075888465e-06 + (fConst1 * (fConst21 + (fRec2[0] * ((fConst1 * (fConst19 + (fConst17 * fRec2[0]))) - 3.38893383925643e-09))))))) + (fRec3[3] * (1.69446691962822e-06 + (fConst1 * (fConst15 + (fRec2[0] * ((fConst1 * (fConst14 + (fConst13 * fRec2[0]))) - 3.38893383925643e-09))))))) / fTemp0));
		double fTemp3 = (1.77436357144034e-14 + (1.77436357144034e-13 * fRec2[0]));
		double fTemp4 = ((((fRec3[1] * (0 - fTemp3)) + ((fRec3[0] * fTemp1) + (fRec3[2] * fTemp3))) + (fRec3[3] * (0 - fTemp1))) / fTemp0);
		fVec1[0] = fTemp4;
		fRec1[0] = (fConst27 * ((fConst26 * fRec1[1]) + (fConst28 * (fVec1[0] - fVec1[1]))));
		fRec0[0] = (fRec1[0] - (fConst6 * ((fConst5 * fRec0[1]) + (fConst3 * fRec0[2]))));
		output0[i] = (FAUSTFLOAT)(fConst6 * ((fConst32 * fRec0[1]) + (fConst1 * ((fConst31 * fRec0[0]) + (fConst30 * fRec0[2])))));
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fVec1[1] = fVec1[0];
		for (int i=3; i>0; i--) fRec3[i] = fRec3[i-1];
		fRec4[1] = fRec4[0];
		fVec0[1] = fVec0[0];
		fRec2[1] = fRec2[0];
	}
#undef fslider0
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case FUZZ: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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
   FUZZ, 
} PortIndex;
*/

} // end namespace vstb_p1
