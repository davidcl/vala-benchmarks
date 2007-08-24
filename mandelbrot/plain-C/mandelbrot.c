/* The Computer Language Shootout
   http://shootout.alioth.debian.org/

   copyright Greg Buchholz
   revised by Clément David (removing SSE)
*/

#include<stdio.h>
#include<math.h>

int
main (int argc, char **argv)
{
  int w, h;
  int i;
  int m = 50;
  int bits = 0;
  int bitnum = 0;

  int isOverLimit = 0;
  double Zr = 0.0;
  double Zi = 0.0;
  double Cr;
  double Ci;
  double Tr;
  double Ti;
  double limit2 = 4.0;

  w = h = atoi (argv[1]);

  printf ("P4\n%d %d\n", w, h);

  int y;
  for (y = 0; y < h; y++)
    {
      int x;
      for (x = 0; x < w; x++)
	{

	  Zr = 0.0;
	  Zi = 0.0;
	  Cr = 2.0 * x / w - 1.5;
	  Ci = 2.0 * y / h - 1.0;

	  i = 0;
	  do
	    {
	      Tr = Zr * Zr - Zi * Zi + Cr;
	      Ti = 2.0 * Zr * Zi + Ci;
	      Zr = Tr;
	      Zi = Ti;
	      isOverLimit = Zr * Zr + Zi * Zi > limit2;
	    }
	  while (!isOverLimit && (++i < m));

	  bits = bits << 1;
	  if (!isOverLimit)
	    bits++;
	  bitnum++;

	  if (x == w - 1)
	    {
	      bits = bits << (8 - bitnum);
	      bitnum = 8;
	    }

	  if (bitnum == 8)
	    {
	      putc ((char) bits, stdout);
	      bits = 0;
	      bitnum = 0;
	    }
	}
    }
}
