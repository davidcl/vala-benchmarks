/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;

public class NSieve {
	
	public static int main(string[] args) {
		
		int m = (args.length > 0)?args[1].to_int():2;	
		
		for (int i = 0; i < 3; i++)
        	nsieve(10000 << (m-i));
		
		return 0;
	}
	
	public static void nsieve( int m ) {
	
		bool[] flags = new bool[m+1];
		
		for (int i=2; i <= m; i++) flags[i] = true;	
		int count = 0;
		
		for( int i=2; i<=m; i++) {
			if( flags[i] ) {
				for (int k=i+i; k <= m; k+=i) flags[k] = false;
				++count;	
			}
		}
		
		stdout.printf("Primes up to %8u %8u\n", m, count);
	}
}
