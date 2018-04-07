package Package1;

import java.util.Arrays;

class test2 
{
	public static void main(String[] args)
	{
		stopwatch.start();
		
		BinaryCode a = new BinaryCode();
		String[] s = a.decode("8");
		System.out.println(Arrays.toString(s));
		
		stopwatch.stop();
		
	}
}