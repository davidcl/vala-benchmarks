/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#include "sumcol.h"
#include <stdio.h>

enum  {
	SUM_COL_DUMMY_PROPERTY
};
static gpointer sum_col_parent_class = NULL;


gint sum_col_main (int args_length1, char** args) {
	gint MAXLINELEN;
	gint sum;
	GString* line;
	MAXLINELEN = 128;
	sum = 0;
	line = g_string_sized_new (MAXLINELEN);
	while (fgets (line->str, MAXLINELEN, stdin) != NULL) {
		sum = sum + (atoi (line->str));
	}
	fprintf (stdout, "%d\n", sum);
	(line == NULL ? NULL : (line = (g_string_free (line, TRUE), NULL)));
}


int main (int argc, char ** argv) {
	g_type_init ();
	return sum_col_main (argc, argv);
}


static void sum_col_class_init (SumColClass * klass) {
	sum_col_parent_class = g_type_class_peek_parent (klass);
}


static void sum_col_init (SumCol * self) {
}


GType sum_col_get_type (void) {
	static GType sum_col_type_id = 0;
	if (G_UNLIKELY (sum_col_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (SumColClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sum_col_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SumCol), 0, (GInstanceInitFunc) sum_col_init };
		sum_col_type_id = g_type_register_static (G_TYPE_OBJECT, "SumCol", &g_define_type_info, 0);
	}
	return sum_col_type_id;
}




