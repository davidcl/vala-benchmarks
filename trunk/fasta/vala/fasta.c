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
typedef struct _FastaFrequencyClass FastaFrequencyClass;
typedef struct _FastaFrequencyPrivate FastaFrequencyPrivate;
enum  {
	FASTA_DUMMY_PROPERTY
};
static gint fasta_seed = 42;
static char* fasta_ALU;
static FastaFrequency** fasta_IUB;
static FastaFrequency** fasta_HomoSapiens;
static gint fasta_index = 0;
static gchar* fasta_buf;
static const gint FASTA_IM = 139968;
static const gint FASTA_IA = 3877;
static const gint FASTA_IC = 29573;
static const gint FASTA_LineLength = 60;
static gint fasta_main (int args_length1, char** args);
static double fasta_random (double max);
static void fasta_MakeCumulative (int a_length1, FastaFrequency** a);
static gchar fasta_SelectRandom (int a_length1, FastaFrequency** a);
static void fasta_MakeRandomFasta (const char* id, const char* desc, int a_length1, FastaFrequency** a, gint n);
static void fasta_MakeRepeatFasta (const char* id, const char* desc, int alu_length1, gchar* alu, gint n);

#define FASTA_TYPE_FREQUENCY (fasta_frequency_get_type ())
#define FASTA_FREQUENCY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FASTA_TYPE_FREQUENCY, FastaFrequency))
#define FASTA_FREQUENCY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FASTA_TYPE_FREQUENCY, FastaFrequencyClass))
#define FASTA_IS_FREQUENCY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FASTA_TYPE_FREQUENCY))
#define FASTA_IS_FREQUENCY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FASTA_TYPE_FREQUENCY))
#define FASTA_FREQUENCY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FASTA_TYPE_FREQUENCY, FastaFrequencyClass))

struct _FastaFrequency {
	GObject parent;
	FastaFrequencyPrivate * priv;
};
struct _FastaFrequencyClass {
	GObjectClass parent;
};
struct _FastaFrequencyPrivate {
	gchar _c;
	double _p;
};
#define FASTA_FREQUENCY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FASTA_TYPE_FREQUENCY, FastaFrequencyPrivate))
enum  {
	FASTA_FREQUENCY_DUMMY_PROPERTY,
	FASTA_FREQUENCY_C,
	FASTA_FREQUENCY_P
};
static FastaFrequency* fasta_frequency_new (gchar c, double p);
static gchar fasta_frequency_get_c (FastaFrequency* self);
static void fasta_frequency_set_c (FastaFrequency* self, gchar value);
static double fasta_frequency_get_p (FastaFrequency* self);
static void fasta_frequency_set_p (FastaFrequency* self, double value);
static gpointer fasta_frequency_parent_class = NULL;
static void fasta_frequency_dispose (GObject * obj);
static GType fasta_frequency_get_type (void);
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


static void fasta_MakeCumulative (int a_length1, FastaFrequency** a) {
	double cp;
	cp = 0.0;
	{
		gint i;
		i = 0;
		for (i = 0; i < a_length1; i++) {
			cp = cp + (fasta_frequency_get_p (a[i]));
			fasta_frequency_set_p (a[i], cp);
		}
	}
}


static gchar fasta_SelectRandom (int a_length1, FastaFrequency** a) {
	double r;
	r = fasta_random (1.0);
	{
		gint i;
		i = 0;
		for (i = 0; i < a_length1; i++) {
			if (r < fasta_frequency_get_p (a[i])) {
				return fasta_frequency_get_c (a[i]);
			}
		}
	}
	return fasta_frequency_get_c (a[a_length1 - 1]);
}


static void fasta_MakeRandomFasta (const char* id, const char* desc, int a_length1, FastaFrequency** a, gint n) {
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


static FastaFrequency* fasta_frequency_new (gchar c, double p) {
	GParameter * __params;
	GParameter * __params_it;
	FastaFrequency * self;
	__params = g_new0 (GParameter, 2);
	__params_it = __params;
	(__params_it->name = "c", g_value_init (&__params_it->value, G_TYPE_CHAR), g_value_set_char (&__params_it->value, c), __params_it++);
	(__params_it->name = "p", g_value_init (&__params_it->value, G_TYPE_DOUBLE), g_value_set_double (&__params_it->value, p), __params_it++);
	self = g_object_newv (FASTA_TYPE_FREQUENCY, __params_it - __params, __params);
	while (__params_it > __params) {
		--__params_it;
		g_value_unset (&__params_it->value);
	}
	g_free (__params);
	return self;
}


static gchar fasta_frequency_get_c (FastaFrequency* self) {
	g_return_val_if_fail (FASTA_IS_FREQUENCY (self), '\0');
	return self->priv->_c;
}


static void fasta_frequency_set_c (FastaFrequency* self, gchar value) {
	g_return_if_fail (FASTA_IS_FREQUENCY (self));
	self->priv->_c = value;
}


static double fasta_frequency_get_p (FastaFrequency* self) {
	g_return_val_if_fail (FASTA_IS_FREQUENCY (self), 0.0);
	return self->priv->_p;
}


static void fasta_frequency_set_p (FastaFrequency* self, double value) {
	g_return_if_fail (FASTA_IS_FREQUENCY (self));
	self->priv->_p = value;
}


static void fasta_frequency_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	FastaFrequency * self;
	self = FASTA_FREQUENCY (object);
	switch (property_id) {
		case FASTA_FREQUENCY_C:
		g_value_set_char (value, fasta_frequency_get_c (self));
		break;
		case FASTA_FREQUENCY_P:
		g_value_set_double (value, fasta_frequency_get_p (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void fasta_frequency_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	FastaFrequency * self;
	self = FASTA_FREQUENCY (object);
	switch (property_id) {
		case FASTA_FREQUENCY_C:
		fasta_frequency_set_c (self, g_value_get_char (value));
		break;
		case FASTA_FREQUENCY_P:
		fasta_frequency_set_p (self, g_value_get_double (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void fasta_frequency_class_init (FastaFrequencyClass * klass) {
	fasta_frequency_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FastaFrequencyPrivate));
	G_OBJECT_CLASS (klass)->get_property = fasta_frequency_get_property;
	G_OBJECT_CLASS (klass)->set_property = fasta_frequency_set_property;
	G_OBJECT_CLASS (klass)->dispose = fasta_frequency_dispose;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FASTA_FREQUENCY_C, g_param_spec_pointer ("c", "foo", "bar", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FASTA_FREQUENCY_P, g_param_spec_double ("p", "foo", "bar", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void fasta_frequency_init (FastaFrequency * self) {
	self->priv = FASTA_FREQUENCY_GET_PRIVATE (self);
}


static void fasta_frequency_dispose (GObject * obj) {
	FastaFrequency * self;
	FastaFrequencyClass * klass;
	GObjectClass * parent_class;
	self = FASTA_FREQUENCY (obj);
	klass = FASTA_FREQUENCY_CLASS (g_type_class_peek (FASTA_TYPE_FREQUENCY));
	parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
	parent_class->dispose (obj);
}


static GType fasta_frequency_get_type (void) {
	static GType fasta_frequency_type_id = 0;
	if (G_UNLIKELY (fasta_frequency_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (FastaFrequencyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fasta_frequency_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FastaFrequency), 0, (GInstanceInitFunc) fasta_frequency_init };
		fasta_frequency_type_id = g_type_register_static (G_TYPE_OBJECT, "FastaFrequency", &g_define_type_info, 0);
	}
	return fasta_frequency_type_id;
}


static void fasta_class_init (FastaClass * klass) {
	fasta_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->dispose = fasta_dispose;
	fasta_ALU = g_strconcat (g_strconcat (g_strconcat (g_strconcat (g_strconcat ("GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG", "GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA", NULL), "CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT", NULL), "ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA", NULL), "GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG", NULL), "AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC", NULL) + "AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";
	fasta_IUB = {fasta_frequency_new ('a', 0.27), fasta_frequency_new ('c', 0.12), fasta_frequency_new ('g', 0.12), fasta_frequency_new ('t', 0.27), fasta_frequency_new ('B', 0.02), fasta_frequency_new ('D', 0.02), fasta_frequency_new ('H', 0.02), fasta_frequency_new ('K', 0.02), fasta_frequency_new ('M', 0.02), fasta_frequency_new ('N', 0.02), fasta_frequency_new ('R', 0.02), fasta_frequency_new ('S', 0.02), fasta_frequency_new ('V', 0.02), fasta_frequency_new ('W', 0.02), fasta_frequency_new ('Y', 0.02)};
	fasta_HomoSapiens = {fasta_frequency_new ('a', 0.3029549426680), fasta_frequency_new ('c', 0.1979883004921), fasta_frequency_new ('g', 0.1975473066391), fasta_frequency_new ('t', 0.3015094502008)};
	fasta_buf = g_new0 (gchar, 1024);
}


static void fasta_init (Fasta * self) {
}


static void fasta_dispose (GObject * obj) {
	Fasta * self;
	FastaClass * klass;
	GObjectClass * parent_class;
	self = FASTA (obj);
	klass = FASTA_CLASS (g_type_class_peek (TYPE_FASTA));
	parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
	parent_class->dispose (obj);
}


GType fasta_get_type (void) {
	static GType fasta_type_id = 0;
	if (G_UNLIKELY (fasta_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (FastaClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fasta_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Fasta), 0, (GInstanceInitFunc) fasta_init };
		fasta_type_id = g_type_register_static (G_TYPE_OBJECT, "Fasta", &g_define_type_info, 0);
	}
	return fasta_type_id;
}




