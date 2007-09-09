/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;

public class nsieveBits {

	static int main(string[] args) {
		
		int n = (args.length > 0)?args[1].to_int():2;
		
		int m = (1<<n)*10000;
		ByteArray flags = new ByteArray.sized(true,false,1,
		
		return 0;
	}
}
