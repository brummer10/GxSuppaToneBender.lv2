// generated from file './/vstb.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace vstb {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		static double 	fWave0[100];
		int 	idxfWave0;
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			idxfWave0 = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				output[i] = fWave0[idxfWave0];
				// post processing
				idxfWave0 = (idxfWave0 + 1) % 100;
			}
		}
	};
			FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec2[2];
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
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec5[2];
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fRec6[4];
	double 	fConst37;
	double 	fRec4[3];
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	static double 	ftbl0[100];
	double 	fRec3[3];
	double 	fConst42;
	double 	fConst43;
	double 	fRec1[3];
	double 	fConst44;
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


double Dsp::ftbl0[100];

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
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<4; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	SIG0 sig0;
	sig0.init(samplingFreq);
	sig0.fill(100,ftbl0);
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (4.33446443970093e-10 * fConst0);
	fConst2 = (6.64102771877882e-08 + (fConst0 * (fConst1 - 2.79026392214162e-08)));
	fConst3 = faustpower<2>(fConst0);
	fConst4 = (1.32820554375576e-07 - (8.66892887940187e-10 * fConst3));
	fConst5 = (6.64102771877882e-08 + (fConst0 * (2.79026392214162e-08 + fConst1)));
	fConst6 = (1.0 / fConst5);
	fConst7 = (1.96649636991755e-06 * fConst0);
	fConst8 = (0.00766496738758086 - fConst7);
	fConst9 = ((3.57544794530464e-10 * fConst3) - 0.00576313337412095);
	fConst10 = (3.57544794530464e-10 * fConst0);
	fConst11 = (0.00824128072499296 + (fConst0 * (fConst10 - 3.49948984743372e-06)));
	fConst12 = (7.15089589060927e-10 * fConst3);
	fConst13 = (0.0164825614499859 - fConst12);
	fConst14 = (1.0 / (0.00824128072499296 + (fConst0 * (3.49948984743372e-06 + fConst10))));
	fConst15 = (3.86926254292528e-10 * fConst0);
	fConst16 = (0.000493239810103676 + (fConst0 * (fConst15 - 2.25059729791483e-06)));
	fConst17 = (0.000986479620207351 - (7.73852508585056e-10 * fConst3));
	fConst18 = (1.0 / (0.000493239810103676 + (fConst0 * (2.25059729791483e-06 + fConst15))));
	fConst19 = (7.67178566962075e-15 * fConst0);
	fConst20 = (1.00879990793734e-08 + (fConst0 * (1.74623910300109e-11 + fConst19)));
	fConst21 = (4.50637775095333e-15 * fConst0);
	fConst22 = (fConst0 * (0 - (6.77786767851286e-12 + fConst21)));
	fConst23 = (4.15046128373515e-15 * fConst0);
	fConst24 = (3.38893383925643e-09 + (fConst0 * (8.46680048007635e-12 + fConst23)));
	fConst25 = ((fConst0 * (1.74623910300109e-11 - fConst19)) - 1.00879990793734e-08);
	fConst26 = (fConst0 * (fConst21 - 6.77786767851286e-12));
	fConst27 = ((fConst0 * (8.46680048007635e-12 - fConst23)) - 3.38893383925643e-09);
	fConst28 = (1.351913325286e-14 * fConst0);
	fConst29 = (fConst0 * (6.77786767851286e-12 - fConst28));
	fConst30 = (1.24513838512054e-14 * fConst0);
	fConst31 = ((fConst0 * (fConst30 - 8.46680048007635e-12)) - 3.38893383925643e-09);
	fConst32 = (2.30153570088622e-14 * fConst0);
	fConst33 = ((fConst0 * (fConst32 - 1.74623910300109e-11)) - 1.00879990793734e-08);
	fConst34 = (1.00879990793734e-08 + (fConst0 * (0 - (1.74623910300109e-11 + fConst32))));
	fConst35 = (fConst0 * (6.77786767851286e-12 + fConst28));
	fConst36 = (3.38893383925643e-09 + (fConst0 * (0 - (8.46680048007635e-12 + fConst30))));
	fConst37 = faustpower<3>(fConst0);
	fConst38 = (1.98269861157228e-11 * fConst0);
	fConst39 = (fConst0 * (3.85497374759958e-05 + fConst38));
	fConst40 = (0 - (3.96539722314456e-11 * fConst3));
	fConst41 = (fConst0 * (fConst38 - 3.85497374759958e-05));
	fConst42 = (0 - (0.0115262667482419 + fConst12));
	fConst43 = (0.00766496738758086 + fConst7);
	fConst44 = (fConst3 / fConst5);
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
#define fslider2 (*fslider2_)
	double 	fSlow0 = (4.748558434412966e-05 * (exp((5 * double(fslider0))) - 1));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (4.748558434412966e-05 * (exp((5 * double(fslider2))) - 1));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = (0 - (7.80658988459958e-10 * fRec0[0]));
		fRec2[0] = ((0.993 * fRec2[1]) + fSlow1);
		double fTemp1 = (fConst9 * fRec2[0]);
		fRec5[0] = ((0.993 * fRec5[1]) + fSlow2);
		double fTemp2 = (1.69446691962822e-06 + (fConst0 * ((fRec5[0] * (fConst24 + (fConst22 * fRec5[0]))) + fConst20)));
		double fTemp3 = (5.91454523813446e-14 * fRec5[0]);
		fRec6[0] = ((double)input0[i] - ((((fRec6[1] * (5.08340075888465e-06 + (fConst0 * ((fRec5[0] * (fConst36 + (fConst35 * fRec5[0]))) + fConst34)))) + (fRec6[2] * (5.08340075888465e-06 + (fConst0 * (fConst33 + (fRec5[0] * (fConst31 + (fConst29 * fRec5[0])))))))) + (fRec6[3] * (1.69446691962822e-06 + (fConst0 * ((fRec5[0] * (fConst27 + (fConst26 * fRec5[0]))) + fConst25))))) / fTemp2));
		double fTemp4 = (1.77436357144034e-13 * fRec5[0]);
		fRec4[0] = ((fConst37 * (((((fRec6[0] * (5.91454523813446e-15 + fTemp3)) + (fRec6[1] * ((0 - fTemp4) - 1.77436357144034e-14))) + (fRec6[2] * (1.77436357144034e-14 + fTemp4))) + (fRec6[3] * ((0 - fTemp3) - 5.91454523813446e-15))) / fTemp2)) - (fConst18 * ((fConst17 * fRec4[1]) + (fConst16 * fRec4[2]))));
		double fTemp5 = (fConst18 * (((fConst41 * fRec4[0]) + (fConst40 * fRec4[1])) + (fConst39 * fRec4[2])));
		double fTemp6 = fabs(fTemp5);
		double fTemp7 = (101.97 * ((fTemp6 / (3.0 + fTemp6)) - 0.005));
		double fTemp8 = max((double)0, min((double)99, floor(fTemp7)));
		double fTemp9 = ((int((0 < fTemp8)))?0:((int((fTemp8 < 99)))?(fTemp7 - fTemp8):99));
		fRec3[0] = ((fabs(((ftbl0[int(fTemp8)] * (1 - fTemp9)) + (fTemp9 * ftbl0[int((1 + fTemp8))]))) * ((int(((fTemp6 * ((int((fTemp5 < 0)))?1:-1)) < 0)))?-1:1)) - (fConst14 * ((fConst13 * fRec3[1]) + (fConst11 * fRec3[2]))));
		fRec1[0] = ((fConst14 * (((fRec3[0] * (fTemp1 + fConst43)) + (fRec3[1] * (0.0153299347751617 + (fConst42 * fRec2[0])))) + (fRec3[2] * (fTemp1 + fConst8)))) - (fConst6 * ((fConst4 * fRec1[1]) + (fConst2 * fRec1[2]))));
		output0[i] = (FAUSTFLOAT)(fConst44 * (((fRec1[0] * fTemp0) + (1.56131797691992e-09 * (fRec0[0] * fRec1[1]))) + (fRec1[2] * fTemp0)));
		// post processing
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		for (int i=3; i>0; i--) fRec6[i] = fRec6[i-1];
		fRec5[1] = fRec5[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
}
	
	
	double 	Dsp::SIG0::fWave0[100] = {
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
	};

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case FUZZ: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TONE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
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
   TONE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace vstb
