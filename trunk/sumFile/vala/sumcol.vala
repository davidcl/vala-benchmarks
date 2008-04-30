/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;

public class SumCol : Object
{
	public static int main(string [] args)
	{
		int MAXLINELEN = 128;
		
		int sum = 0;
		StringBuilder line = new StringBuilder.sized(MAXLINELEN);
		
		while(stdin.gets(line.str,MAXLINELEN) != null)
		{
			sum += line.str.to_int();
		}
		
		stdout.printf("%d\n",sum);
		return 0;
	}
}
