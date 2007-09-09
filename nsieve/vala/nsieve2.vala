/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;

public class NSieve {
	
	public static int main(string[] args) {
		
		int n = (args.length > 0)?args[1].to_int():2;	
		
		int m = (1<<n)*10000;
		bool[] flags = new bool[m+1];
		stdout.printf("Primes up to %8u %8u\n", m, nsieve(m,flags));

		m = (1<<n-1)*10000;		
		stdout.printf("Primes up to %8u %8u\n", m, nsieve(m,flags));
		
		m = (1<<n-2)*10000;		
		stdout.printf("Primes up to %8u %8u\n", m, nsieve(m,flags));
		
		return 0;
	}
	
	public static int nsieve( int m, bool[] isPrime ) {
	
		for (int i=2; i <= m; i++) isPrime[i] = true;	
		int count = 0;
		
		for( int i=2; i<=m; i++) {
			if( isPrime[i] ) {
				for (int k=i+i; k <= m; k+=i) isPrime[k] = false;
				++count;	
			}
		}
		
		return count;
	}
}
