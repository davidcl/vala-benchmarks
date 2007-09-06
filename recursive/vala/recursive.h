/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#ifndef __RECURSIVE_H__
#define __RECURSIVE_H__

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>

G_BEGIN_DECLS


#define TYPE_RECURSIVE (recursive_get_type ())
#define RECURSIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_RECURSIVE, Recursive))
#define RECURSIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_RECURSIVE, RecursiveClass))
#define IS_RECURSIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_RECURSIVE))
#define IS_RECURSIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_RECURSIVE))
#define RECURSIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_RECURSIVE, RecursiveClass))

typedef struct _Recursive Recursive;
typedef struct _RecursiveClass RecursiveClass;
typedef struct _RecursivePrivate RecursivePrivate;

struct _Recursive {
	GObject parent;
	RecursivePrivate * priv;
};
struct _RecursiveClass {
	GObjectClass parent;
};

gint recursive_ack (gint m, gint n);
gint recursive_fib (gint n);
gint recursive_tak (gint x, gint y, gint z);
double recursive_fibFP (double n);
double recursive_takFP (double x, double y, double z);
GType recursive_get_type (void);

G_END_DECLS

#endif
