/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#ifndef __PARTIALSUMS_H__
#define __PARTIALSUMS_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

G_BEGIN_DECLS


#define TYPE_PARTIAL_SUMS (partial_sums_get_type ())
#define PARTIAL_SUMS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PARTIAL_SUMS, PartialSums))
#define PARTIAL_SUMS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PARTIAL_SUMS, PartialSumsClass))
#define IS_PARTIAL_SUMS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PARTIAL_SUMS))
#define IS_PARTIAL_SUMS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PARTIAL_SUMS))
#define PARTIAL_SUMS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PARTIAL_SUMS, PartialSumsClass))

typedef struct _PartialSums PartialSums;
typedef struct _PartialSumsClass PartialSumsClass;
typedef struct _PartialSumsPrivate PartialSumsPrivate;

struct _PartialSums {
	GObject parent;
	PartialSumsPrivate * priv;
};
struct _PartialSumsClass {
	GObjectClass parent;
};

gint partial_sums_main (int args_length1, char** args);
GType partial_sums_get_type (void);

G_END_DECLS

#endif
