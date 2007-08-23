/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Clément David
*/
using GLib;

public class SumCol
{
	public static int main(string [] args)
	{
		int MAXLINELEN = 128;
		
		int sum = 0;
		String line = new String.sized(MAXLINELEN);
		
		while(stdin.gets(line.str,MAXLINELEN) != null)
		{
			sum += line.str.to_int();
		}
		
		stdout.printf("%d\n",sum);
	}
}