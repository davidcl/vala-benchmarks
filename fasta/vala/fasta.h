/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/

#ifndef __FASTA_H__
#define __FASTA_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS


#define TYPE_FASTA (fasta_get_type ())
#define FASTA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FASTA, Fasta))
#define FASTA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FASTA, FastaClass))
#define IS_FASTA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FASTA))
#define IS_FASTA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FASTA))
#define FASTA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FASTA, FastaClass))

typedef struct _Fasta Fasta;
typedef struct _FastaClass FastaClass;
typedef struct _FastaPrivate FastaPrivate;

struct _Fasta {
	GObject parent;
	FastaPrivate * priv;
};
struct _FastaClass {
	GObjectClass parent;
};

GType fasta_get_type (void);

G_END_DECLS

#endif
