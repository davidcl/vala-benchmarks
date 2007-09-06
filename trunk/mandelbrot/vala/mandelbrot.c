/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#include "mandelbrot.h"
#include <float.h>
#include <math.h>
#include <stdio.h>

enum  {
	MANDELBROT_DUMMY_PROPERTY
};
static gpointer mandelbrot_parent_class = NULL;


gint mandelbrot_main (int args_length1, char** args) {
	gint width;
	gint height;
	gint i;
	gint m;
	gint bits;
	gint bitnum;
	gboolean isOverLimit;
	double Zr;
	double Zi;
	double Cr;
	double Ci;
	double Tr;
	double Ti;
	double limit2;
	width = ((args_length1 > 0) ? atoi (args[1]) : 100);
	height = width;
	i = 0;
	m = 50;
	bits = 0;
	bitnum = 0;
	isOverLimit = FALSE;
	Zr = 0.0;
	Zi = 0.0;
	Cr = 0.0;
	Ci = 0.0;
	Tr = 0.0;
	Ti = 0.0;
	limit2 = 4.0;
	fprintf (stdout, "P4\n%d %d\n", width, height);
	{
		gint y;
		y = 0;
		for (y = 0; y < height; y++) {
			{
				gint x;
				x = 0;
				for (x = 0; x < width; x++) {
					Zr = 0.0;
					Zi = 0.0;
					Tr = 0.0;
					Ti = 0.0;
					Cr = 2.0 * x / width - 1.5;
					Ci = 2.0 * y / height - 1.0;
					i = 0;
					do {
						Tr = Zr * Zr - Zi * Zi + Cr;
						Ti = 2.0 * Zr * Zi + Ci;
						Zr = Tr;
						Zi = Ti;
						isOverLimit = Zr * Zr + Zi * Zi > limit2;
					} while (!isOverLimit && ((i = i + 1) < m));
					bits = bits << 1;
					if (!isOverLimit) {
						bits++;
					}
					bitnum++;
					if (x == width - 1) {
						bits = bits << (8 - bitnum);
						bitnum = 8;
					}
					if (bitnum == 8) {
						fputc (((gchar) bits), stdout);
						bits = ((guint8) 0);
						bitnum = 0;
					}
				}
			}
		}
	}
	return 0;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return mandelbrot_main (argc, argv);
}


static void mandelbrot_class_init (MandelbrotClass * klass) {
	mandelbrot_parent_class = g_type_class_peek_parent (klass);
}


static void mandelbrot_init (Mandelbrot * self) {
}


GType mandelbrot_get_type (void) {
	static GType mandelbrot_type_id = 0;
	if (G_UNLIKELY (mandelbrot_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (MandelbrotClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) mandelbrot_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Mandelbrot), 0, (GInstanceInitFunc) mandelbrot_init };
		mandelbrot_type_id = g_type_register_static (G_TYPE_OBJECT, "Mandelbrot", &g_define_type_info, 0);
	}
	return mandelbrot_type_id;
}




