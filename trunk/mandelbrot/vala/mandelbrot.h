/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

G_BEGIN_DECLS


#define TYPE_MANDELBROT (mandelbrot_get_type ())
#define MANDELBROT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MANDELBROT, Mandelbrot))
#define MANDELBROT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MANDELBROT, MandelbrotClass))
#define IS_MANDELBROT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MANDELBROT))
#define IS_MANDELBROT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MANDELBROT))
#define MANDELBROT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MANDELBROT, MandelbrotClass))

typedef struct _Mandelbrot Mandelbrot;
typedef struct _MandelbrotClass MandelbrotClass;
typedef struct _MandelbrotPrivate MandelbrotPrivate;

struct _Mandelbrot {
	GObject parent;
	MandelbrotPrivate * priv;
};
struct _MandelbrotClass {
	GObjectClass parent;
};

gint mandelbrot_main (int args_length1, char** args);
GType mandelbrot_get_type (void);

G_END_DECLS

#endif
