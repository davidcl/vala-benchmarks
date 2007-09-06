/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#ifndef __SUMCOL_H__
#define __SUMCOL_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

G_BEGIN_DECLS


#define TYPE_SUM_COL (sum_col_get_type ())
#define SUM_COL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SUM_COL, SumCol))
#define SUM_COL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SUM_COL, SumColClass))
#define IS_SUM_COL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SUM_COL))
#define IS_SUM_COL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SUM_COL))
#define SUM_COL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SUM_COL, SumColClass))

typedef struct _SumCol SumCol;
typedef struct _SumColClass SumColClass;
typedef struct _SumColPrivate SumColPrivate;

struct _SumCol {
	GObject parent;
	SumColPrivate * priv;
};
struct _SumColClass {
	GObjectClass parent;
};

gint sum_col_main (int args_length1, char** args);
GType sum_col_get_type (void);

G_END_DECLS

#endif
