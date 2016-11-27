// generated from file './/vstb.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace vstb {

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

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	float 	fRec0[2];
	int 	iConst0;
	float 	fConst1;
	float 	fConst2;
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fConst9;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	float 	fRec3[2];
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	float 	fRec8[2];
	float 	fConst24;
	float 	fConst25;
	float 	fConst26;
	float 	fConst27;
	float 	fConst28;
	float 	fConst29;
	float 	fConst30;
	float 	fConst31;
	float 	fConst32;
	float 	fConst33;
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	float 	fVec0[2];
	float 	fConst40;
	float 	fRec10[2];
	float 	fRec9[4];
	float 	fVec1[2];
	float 	fConst41;
	float 	fRec7[2];
	float 	fRec6[3];
	float 	fConst42;
	float 	fConst43;
	float 	fConst44;
	float 	fConst45;
	float 	fVec2[2];
	float 	fRec5[2];
	float 	fRec4[3];
	float 	fConst46;
	float 	fConst47;
	float 	fVec3[2];
	float 	fRec2[2];
	float 	fRec1[3];
	float 	fConst48;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
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
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<4; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = float(iConst0);
	fConst2 = (4.33446443970093e-10f * fConst1);
	fConst3 = (6.64102771877882e-08f + (fConst1 * (fConst2 - 2.79026392214162e-08f)));
	fConst4 = faustpower<2>(fConst1);
	fConst5 = (1.32820554375576e-07f - (8.66892887940187e-10f * fConst4));
	fConst6 = (6.64102771877882e-08f + (fConst1 * (2.79026392214162e-08f + fConst2)));
	fConst7 = (1.0f / fConst6);
	fConst8 = (1.96649636991755e-06f * fConst1);
	fConst9 = (0.00766496738758086f - fConst8);
	fConst10 = ((3.57544794530464e-10f * fConst4) - 0.00576313337412095f);
	fConst11 = (3.57544794530464e-10f * fConst1);
	fConst12 = (0.00824128072499296f + (fConst1 * (fConst11 - 3.49948984743372e-06f)));
	fConst13 = (7.15089589060927e-10f * fConst4);
	fConst14 = (0.0164825614499859f - fConst13);
	fConst15 = (1.0f / (0.00824128072499296f + (fConst1 * (3.49948984743372e-06f + fConst11))));
	fConst16 = (491.77839701345533f / float(iConst0));
	fConst17 = (1 - fConst16);
	fConst18 = (3.86926254292528e-10f * fConst1);
	fConst19 = (0.000493239810103676f + (fConst1 * (fConst18 - 2.25059729791483e-06f)));
	fConst20 = (0.000986479620207351f - (7.73852508585056e-10f * fConst4));
	fConst21 = (1.0f / (0.000493239810103676f + (fConst1 * (2.25059729791483e-06f + fConst18))));
	fConst22 = (7.67178566962075e-15f * fConst1);
	fConst23 = (1.00879990793734e-08f + (fConst1 * (1.74623910300109e-11f + fConst22)));
	fConst24 = (4.50637775095333e-15f * fConst1);
	fConst25 = (fConst1 * (0 - (6.77786767851286e-12f + fConst24)));
	fConst26 = (4.15046128373515e-15f * fConst1);
	fConst27 = (3.38893383925643e-09f + (fConst1 * (8.46680048007635e-12f + fConst26)));
	fConst28 = ((fConst1 * (1.74623910300109e-11f - fConst22)) - 1.00879990793734e-08f);
	fConst29 = (fConst1 * (fConst24 - 6.77786767851286e-12f));
	fConst30 = ((fConst1 * (8.46680048007635e-12f - fConst26)) - 3.38893383925643e-09f);
	fConst31 = (1.351913325286e-14f * fConst1);
	fConst32 = (fConst1 * (6.77786767851286e-12f - fConst31));
	fConst33 = (1.24513838512054e-14f * fConst1);
	fConst34 = ((fConst1 * (fConst33 - 8.46680048007635e-12f)) - 3.38893383925643e-09f);
	fConst35 = (2.30153570088622e-14f * fConst1);
	fConst36 = ((fConst1 * (fConst35 - 1.74623910300109e-11f)) - 1.00879990793734e-08f);
	fConst37 = (1.00879990793734e-08f + (fConst1 * (0 - (1.74623910300109e-11f + fConst35))));
	fConst38 = (fConst1 * (6.77786767851286e-12f + fConst31));
	fConst39 = (3.38893383925643e-09f + (fConst1 * (0 - (8.46680048007635e-12f + fConst33))));
	fConst40 = (1.0f / (1 + fConst16));
	fConst41 = faustpower<3>(fConst1);
	fConst42 = (1.98269861157228e-11f * fConst1);
	fConst43 = (fConst1 * (3.85497374759958e-05f + fConst42));
	fConst44 = (0 - (3.96539722314456e-11f * fConst4));
	fConst45 = (fConst1 * (fConst42 - 3.85497374759958e-05f));
	fConst46 = (0 - (0.0115262667482419f + fConst13));
	fConst47 = (0.00766496738758086f + fConst8);
	fConst48 = (fConst4 / fConst6);
	clear_state_f();
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
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
	float 	fSlow0 = (4.748558434412966e-05f * (expf((5 * float(fslider0))) - 1));
	float 	fSlow1 = (0.007000000000000006f * float(fslider1));
	float 	fSlow2 = (4.748558434412966e-05f * (expf((5 * float(fslider2))) - 1));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993f * fRec0[1]) + fSlow0);
		float fTemp0 = (0 - (7.80658988459958e-10f * fRec0[0]));
		fRec3[0] = ((0.993f * fRec3[1]) + fSlow1);
		float fTemp1 = (fConst10 * fRec3[0]);
		fRec8[0] = ((0.993f * fRec8[1]) + fSlow2);
		float fTemp2 = (1.69446691962822e-06f + (fConst1 * ((fRec8[0] * (fConst27 + (fConst25 * fRec8[0]))) + fConst23)));
		float fTemp3 = (5.91454523813446e-14f * fRec8[0]);
		float fTemp4 = (float)input0[i];
		fVec0[0] = fTemp4;
		fRec10[0] = (fConst40 * ((fVec0[0] - fVec0[1]) + (fConst17 * fRec10[1])));
		fRec9[0] = (fRec10[0] - ((((fRec9[1] * (5.08340075888465e-06f + (fConst1 * ((fRec8[0] * (fConst39 + (fConst38 * fRec8[0]))) + fConst37)))) + (fRec9[2] * (5.08340075888465e-06f + (fConst1 * (fConst36 + (fRec8[0] * (fConst34 + (fConst32 * fRec8[0])))))))) + (fRec9[3] * (1.69446691962822e-06f + (fConst1 * ((fRec8[0] * (fConst30 + (fConst29 * fRec8[0]))) + fConst28))))) / fTemp2));
		float fTemp5 = (1.77436357144034e-13f * fRec8[0]);
		float fTemp6 = (((((fRec9[0] * (5.91454523813446e-15f + fTemp3)) + (fRec9[1] * ((0 - fTemp5) - 1.77436357144034e-14f))) + (fRec9[2] * (1.77436357144034e-14f + fTemp5))) + (fRec9[3] * ((0 - fTemp3) - 5.91454523813446e-15f))) / fTemp2);
		fVec1[0] = fTemp6;
		fRec7[0] = (fConst40 * ((fConst17 * fRec7[1]) + (fConst41 * (fVec1[0] - fVec1[1]))));
		fRec6[0] = (fRec7[0] - (fConst21 * ((fConst20 * fRec6[1]) + (fConst19 * fRec6[2]))));
		float fTemp7 = symclip((fConst21 * (((fConst45 * fRec6[0]) + (fConst44 * fRec6[1])) + (fConst43 * fRec6[2]))));
		fVec2[0] = fTemp7;
		fRec5[0] = (fConst40 * ((fVec2[0] - fVec2[1]) + (fConst17 * fRec5[1])));
		fRec4[0] = (fRec5[0] - (fConst15 * ((fConst14 * fRec4[1]) + (fConst12 * fRec4[2]))));
		float fTemp8 = (((fRec4[0] * (fTemp1 + fConst47)) + (fRec4[1] * (0.0153299347751617f + (fConst46 * fRec3[0])))) + (fRec4[2] * (fTemp1 + fConst9)));
		fVec3[0] = fTemp8;
		fRec2[0] = (fConst40 * ((fConst17 * fRec2[1]) + (fConst15 * (fVec3[0] - fVec3[1]))));
		fRec1[0] = (fRec2[0] - (fConst7 * ((fConst5 * fRec1[1]) + (fConst3 * fRec1[2]))));
		output0[i] = (FAUSTFLOAT)(fConst48 * (((fRec1[0] * fTemp0) + (1.56131797691992e-09f * (fRec0[0] * fRec1[1]))) + (fRec1[2] * fTemp0)));
		// post processing
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fVec3[1] = fVec3[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		fVec2[1] = fVec2[0];
		fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
		fRec7[1] = fRec7[0];
		fVec1[1] = fVec1[0];
		for (int i=3; i>0; i--) fRec9[i] = fRec9[i-1];
		fRec10[1] = fRec10[0];
		fVec0[1] = fVec0[0];
		fRec8[1] = fRec8[0];
		fRec3[1] = fRec3[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
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
		fslider2_ = (float*)data; // , 0.5f, 0.0f, 1.0f, 0.01f 
		break;
	case TONE: 
		fslider1_ = (float*)data; // , 0.5f, 0.0f, 1.0f, 0.01f 
		break;
	case VOLUME: 
		fslider0_ = (float*)data; // , 0.5f, 0.0f, 1.0f, 0.01f 
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
