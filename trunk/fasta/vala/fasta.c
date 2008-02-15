/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#include "fasta.h"
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

typedef struct _FastaFrequency FastaFrequency;
enum  {
	FASTA_DUMMY_PROPERTY
};
static gint fasta_seed = 42;
static char* fasta_ALU;
static FastaFrequency* fasta_IUB;
static FastaFrequency* fasta_HomoSapiens;
static gint fasta_index = 0;
static gchar* fasta_buf;
static const gint FASTA_IM = 139968;
static const gint FASTA_IA = 3877;
static const gint FASTA_IC = 29573;
static const gint FASTA_LineLength = 60;
static gint fasta_main (int args_length1, char** args);
static double fasta_random (double max);
static void fasta_MakeCumulative (int a_length1, FastaFrequency* a);
static gchar fasta_SelectRandom (int a_length1, FastaFrequency* a);
static void fasta_MakeRandomFasta (const char* id, const char* desc, int a_length1, FastaFrequency* a, gint n);
static void fasta_MakeRepeatFasta (const char* id, const char* desc, int alu_length1, gchar* alu, gint n);
struct _FastaFrequency {
	gchar c;
	double p;
};
static gpointer fasta_parent_class = NULL;
static void fasta_dispose (GObject * obj);


static gint fasta_main (int args_length1, char** args) {
	gint n;
	fasta_MakeCumulative (HomoSapiens_length1, fasta_HomoSapiens);
	fasta_MakeCumulative (IUB_length1, fasta_IUB);
	n = ((args_length1 > 0) ? atoi (args[1]) : 1000);
	fasta_MakeRepeatFasta ("ONE", "Homo sapiens alu", skip_length1, g_utf8_skip, n * 2);
	fasta_MakeRandomFasta ("TWO", "IUB ambiguity codes", IUB_length1, fasta_IUB, n * 3);
	fasta_MakeRandomFasta ("THREE", "Homo sapiens frequency", HomoSapiens_length1, fasta_HomoSapiens, n * 5);
	return 0;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return fasta_main (argc, argv);
}


static double fasta_random (double max) {
	return max * ((fasta_seed = (fasta_seed * FASTA_IA + FASTA_IC) % FASTA_IM) * (1.0 / FASTA_IM));
}


static void fasta_MakeCumulative (int a_length1, FastaFrequency* a) {
	double cp;
	cp = 0.0;
	{
		gint i;
		i = 0;
		for (i = 0; i < a_length1; i++) {
			cp = cp + (a[i].p);
			a[i].p = cp;
		}
	}
}


static gchar fasta_SelectRandom (int a_length1, FastaFrequency* a) {
	double r;
	r = fasta_random (1.0);
	{
		gint i;
		i = 0;
		for (i = 0; i < a_length1; i++) {
			if (r < a[i].p) {
				return a[i].c;
			}
		}
	}
	return a[a_length1 - 1].c;
}


static void fasta_MakeRandomFasta (const char* id, const char* desc, int a_length1, FastaFrequency* a, gint n) {
	gint m;
	char* _tmp2;
	char* _tmp1;
	char* _tmp0;
	char* _tmp3;
	char* descStr;
	fasta_index = 0;
	m = 0;
	_tmp2 = NULL;
	_tmp1 = NULL;
	_tmp0 = NULL;
	_tmp3 = NULL;
	descStr = (_tmp3 = g_strconcat ((_tmp2 = g_strconcat ((_tmp1 = g_strconcat ((_tmp0 = g_strconcat (">", id, NULL)), " ", NULL)), desc, NULL)), "\n", NULL), (_tmp2 = (g_free (_tmp2), NULL)), (_tmp1 = (g_free (_tmp1), NULL)), (_tmp0 = (g_free (_tmp0), NULL)), _tmp3);
	fputs (descStr, stdout);
	while (n > 0) {
		m = (n < FASTA_LineLength ? n : FASTA_LineLength);
		if (buf_length1 - fasta_index < m) {
			char* _tmp5;
			char* _tmp4;
			/* FIXME : Change the index to index +1 or index -1*/
			_tmp5 = NULL;
			_tmp4 = NULL;
			fputs ((_tmp5 = g_utf8_offset_to_pointer ((((char*) fasta_buf)), 0), g_strndup (_tmp5, g_utf8_offset_to_pointer (_tmp5, fasta_index) - _tmp5)), stdout);
			(_tmp4 = (g_free (_tmp4), NULL));
			fasta_index = 0;
		}
		{
			gint i;
			i = 0;
			for (i = 0; i < m; i++) {
				fasta_buf[fasta_index++] = fasta_SelectRandom (a_length1, a);
			}
		}
		fasta_buf[fasta_index++] = ((gchar) '\n');
		n = n - (FASTA_LineLength);
	}
	if (fasta_index != 0) {
		char* _tmp7;
		char* _tmp6;
		_tmp7 = NULL;
		_tmp6 = NULL;
		fputs ((_tmp7 = g_utf8_offset_to_pointer ((((char*) fasta_buf)), 0), g_strndup (_tmp7, g_utf8_offset_to_pointer (_tmp7, fasta_index) - _tmp7)), stdout);
		(_tmp6 = (g_free (_tmp6), NULL));
	}
	(descStr = (g_free (descStr), NULL));
}


static void fasta_MakeRepeatFasta (const char* id, const char* desc, int alu_length1, gchar* alu, gint n) {
	gint m;
	gint k;
	gint kn;
	char* _tmp2;
	char* _tmp1;
	char* _tmp0;
	char* _tmp3;
	char* descStr;
	fasta_index = 0;
	m = 0;
	k = 0;
	kn = alu_length1;
	_tmp2 = NULL;
	_tmp1 = NULL;
	_tmp0 = NULL;
	_tmp3 = NULL;
	descStr = (_tmp3 = g_strconcat ((_tmp2 = g_strconcat ((_tmp1 = g_strconcat ((_tmp0 = g_strconcat (">", id, NULL)), " ", NULL)), desc, NULL)), "\n", NULL), (_tmp2 = (g_free (_tmp2), NULL)), (_tmp1 = (g_free (_tmp1), NULL)), (_tmp0 = (g_free (_tmp0), NULL)), _tmp3);
	fputs (descStr, stdout);
	while (n > 0) {
		m = (n < FASTA_LineLength ? n : FASTA_LineLength);
		if (buf_length1 - fasta_index < m) {
			char* _tmp5;
			char* _tmp4;
			/* FIXME : Change the index to index +1 or index -1*/
			_tmp5 = NULL;
			_tmp4 = NULL;
			fputs ((_tmp5 = g_utf8_offset_to_pointer ((((char*) fasta_buf)), 0), g_strndup (_tmp5, g_utf8_offset_to_pointer (_tmp5, fasta_index) - _tmp5)), stdout);
			(_tmp4 = (g_free (_tmp4), NULL));
			fasta_index = 0;
		}
		{
			gint i;
			i = 0;
			for (i = 0; i < m; i++) {
				if (k == kn) {
					k = 0;
				}
				fasta_buf[fasta_index++] = alu[k];
				k++;
			}
		}
		fasta_buf[fasta_index++] = ((gchar) '\n');
		n = n - (FASTA_LineLength);
	}
	if (fasta_index != 0) {
		char* _tmp7;
		char* _tmp6;
		_tmp7 = NULL;
		_tmp6 = NULL;
		fputs ((_tmp7 = g_utf8_offset_to_pointer ((((char*) fasta_buf)), 0), g_strndup (_tmp7, g_utf8_offset_to_pointer (_tmp7, fasta_index) - _tmp7)), stdout);
		(_tmp6 = (g_free (_tmp6), NULL));
	}
	(descStr = (g_free (descStr), NULL));
}


Fasta* fasta_new (void) {
	Fasta * self;
	self = g_object_newv (TYPE_FASTA, 0, NULL);
	return self;
}


static void fasta_class_init (FastaClass * klass) {
	fasta_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->dispose = fasta_dispose;
	fasta_ALU = g_strconcat (g_strconcat (g_strconcat (g_strconcat (g_strconcat ("GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG", "GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA", NULL), "CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT", NULL), "ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA", NULL), "GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG", NULL), "AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC", NULL) + "AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";
	fasta_IUB = {{'a', 0.27}, {'c', 0.12}, {'g', 0.12}, {'t', 0.27}, {'B', 0.02}, {'D', 0.02}, {'H', 0.02}, {'K', 0.02}, {'M', 0.02}, {'N', 0.02}, {'R', 0.02}, {'S', 0.02}, {'V', 0.02}, {'W', 0.02}, {'Y', 0.02}};
	fasta_HomoSapiens = {{'a', 0.3029549426680}, {'c', 0.1979883004921}, {'g', 0.1975473066391}, {'t', 0.3015094502008}};
	fasta_buf = g_new0 (gchar, 1024);
}


static void fasta_init (Fasta * self) {
}


static void fasta_dispose (GObject * obj) {
	Fasta * self;
	self = FASTA (obj);
	G_OBJECT_CLASS (fasta_parent_class)->dispose (obj);
}


GType fasta_get_type (void) {
	static GType fasta_type_id = 0;
	if (G_UNLIKELY (fasta_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (FastaClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fasta_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Fasta), 0, (GInstanceInitFunc) fasta_init };
		fasta_type_id = g_type_register_static (G_TYPE_OBJECT, "Fasta", &g_define_type_info, 0);
	}
	return fasta_type_id;
}




