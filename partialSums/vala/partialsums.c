/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#include "partialsums.h"
#include <float.h>
#include <math.h>
#include <stdio.h>

enum  {
	PARTIAL_SUMS_DUMMY_PROPERTY
};
static const double PARTIAL_SUMS_twothirds = 2.0 / 3.0;
static gpointer partial_sums_parent_class = NULL;


gint partial_sums_main (int args_length1, char** args) {
	gint n;
	gint k;
	double sum;
	double a;
	n = atoi (args[1]);
	k = 0;
	sum = 0.0;
	a = 0.0;
	sum = 0.0;
	for (k = 0; k <= n; k++) {
		sum = sum + (pow (PARTIAL_SUMS_twothirds, (((double) k))));
	}
	fprintf (stdout, "%.9f\t(2/3)^k\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		sum = sum + (1 / sqrt ((((double) k))));
	}
	/* aka pow(((double)k), -0.5) */
	fprintf (stdout, "%.9f\tk^-0.5\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		sum = sum + (1.0 / ((((double) k)) * ((((double) k)) + 1.0)));
	}
	fprintf (stdout, "%.9f\t1/k(k+1)\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		double sk;
		sk = sin ((((double) k)));
		sum = sum + (1.0 / ((((double) k)) * (((double) k)) * (((double) k)) * sk * sk));
	}
	fprintf (stdout, "%.9f\tFlint Hills\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		double ck;
		ck = cos ((((double) k)));
		sum = sum + (1.0 / ((((double) k)) * (((double) k)) * (((double) k)) * ck * ck));
	}
	fprintf (stdout, "%.9f\tCookson Hills\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		sum = sum + (1.0 / (((double) k)));
	}
	fprintf (stdout, "%.9f\tHarmonic\n", sum);
	sum = 0.0;
	for (k = 1; k <= n; k++) {
		sum = sum + (1.0 / ((((double) k)) * (((double) k))));
	}
	fprintf (stdout, "%.9f\tRiemann Zeta\n", sum);
	sum = 0.0;
	a = -1.0;
	for (k = 1; k <= n; k++) {
		sum = sum + ((a = -a) / (((double) k)));
	}
	fprintf (stdout, "%.9f\tAlternating Harmonic\n", sum);
	sum = 0.0;
	a = -1.0;
	for (k = 1; k <= n; k++) {
		sum = sum + ((a = -a) / (2.0 * (((double) k)) - 1.0));
	}
	fprintf (stdout, "%.9f\tGregory\n", sum);
	return 0;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return partial_sums_main (argc, argv);
}


static void partial_sums_class_init (PartialSumsClass * klass) {
	partial_sums_parent_class = g_type_class_peek_parent (klass);
}


static void partial_sums_init (PartialSums * self) {
}


GType partial_sums_get_type (void) {
	static GType partial_sums_type_id = 0;
	if (G_UNLIKELY (partial_sums_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (PartialSumsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) partial_sums_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PartialSums), 0, (GInstanceInitFunc) partial_sums_init };
		partial_sums_type_id = g_type_register_static (G_TYPE_OBJECT, "PartialSums", &g_define_type_info, 0);
	}
	return partial_sums_type_id;
}




