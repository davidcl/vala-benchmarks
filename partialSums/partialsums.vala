/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;
using Math;

public class PartialSums {
	
	const double twothirds = 2.0/3.0;
	
	public static int main(string[] args)
	{
		int n = args[1].to_int();
		
		double a1 = 0.0, a2 = 0.0, a3 = 0.0, a4 = 0.0, a5 = 0.0;
		double a6 = 0.0, a7 = 0.0, a8 = 0.0, a9 = 0.0, alt = -1.0;
		
		for(int k=1; k<= n; k++)
		{
			double k2 = Math.pow(twothirds, k-1), k3 = k2*k;
			double sk = Math.sin(k), ck = Math.cos(k);
			alt = -alt;
			
			a1 += Math.pow(twothirds,k-1);
			a2 += Math.pow(k,-0.5);
			a3 += 1.0/(k*(k+1.0));
			a4 += 1.0/(k3 * sk*sk);
			a5 += 1.0/(k3 * ck*ck);
			a6 += 1.0/k;
			a7 += 1.0/k2;
			a8 += alt/k;
			a9 += alt/(2.0*k -1.0);
		}
		stdout.printf("%.9f\t(2/3)^k\n", a1);
		stdout.printf("%.9f\tk^-0.5\n", a2);
		stdout.printf("%.9f\t1/k(k+1)\n", a3);
		stdout.printf("%.9f\tFlint Hills\n", a4);
		stdout.printf("%.9f\tCookson Hills\n", a5);
		stdout.printf("%.9f\tHarmonic\n", a6);
		stdout.printf("%.9f\tRiemann Zeta\n", a7);
		stdout.printf("%.9f\tAlternating Harmonic\n", a8);
		stdout.printf("%.9f\tGregory\n", a9);
	}	
}
