/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#include "recursive.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum  {
	RECURSIVE_DUMMY_PROPERTY
};
static gint recursive_main (int args_length1, char** args);
static gpointer recursive_parent_class = NULL;


static gint recursive_main (int args_length1, char** args) {
	gint n;
	n = atoi (args[1]);
	fprintf (stdout, "Ack(3,%d): %d\n", n, recursive_ack (3, n));
	fprintf (stdout, "Fib(%.1f): %.1f\n", 27.0 + n, recursive_fibFP (27.0 + n));
	n--;
	fprintf (stdout, "Tak(%d,%d,%d): %d\n", 3 * n, 2 * n, n, recursive_tak (3 * n, 2 * n, n));
	fprintf (stdout, "Fib(3): %d\n", recursive_fib (3));
	fprintf (stdout, "Tak(3.0,2.0,1.0): %.1f\n", recursive_takFP (3.0, 2.0, 1.0));
	return 0;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return recursive_main (argc, argv);
}


gint recursive_ack (gint m, gint n) {
	if (m == 0) {
		return n + 1;
	}
	if (n == 0) {
		return recursive_ack (m - 1, 1);
	} else {
		return recursive_ack (m - 1, recursive_ack (m, n - 1));
	}
}


gint recursive_fib (gint n) {
	if (n < 2) {
		return 1;
	} else {
		return recursive_fib (n - 2) + recursive_fib (n - 1);
	}
}


gint recursive_tak (gint x, gint y, gint z) {
	if (y < x) {
		return recursive_tak (recursive_tak (x - 1, y, z), recursive_tak (y - 1, z, x), recursive_tak (z - 1, x, y));
	} else {
		return z;
	}
}


double recursive_fibFP (double n) {
	if (n < 2.0) {
		return 1.0;
	} else {
		return recursive_fibFP (n - 2.0) + recursive_fibFP (n - 1.0);
	}
}


double recursive_takFP (double x, double y, double z) {
	if (y < x) {
		return recursive_takFP (recursive_takFP (x - 1.0, y, z), recursive_takFP (y - 1.0, z, x), recursive_takFP (z - 1.0, x, y));
	} else {
		return z;
	}
}


static void recursive_class_init (RecursiveClass * klass) {
	recursive_parent_class = g_type_class_peek_parent (klass);
}


static void recursive_init (Recursive * self) {
}


GType recursive_get_type (void) {
	static GType recursive_type_id = 0;
	if (G_UNLIKELY (recursive_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (RecursiveClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) recursive_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Recursive), 0, (GInstanceInitFunc) recursive_init };
		recursive_type_id = g_type_register_static (G_TYPE_OBJECT, "Recursive", &g_define_type_info, 0);
	}
	return recursive_type_id;
}




