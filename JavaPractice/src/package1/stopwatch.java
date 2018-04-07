package Package1;

class stopwatch 
{
	static long startTime, endTime;
	public static void start()
	{
		startTime = System.currentTimeMillis();
	}
	public static void stop()
	{
		endTime = System.currentTimeMillis();
	    System.out.println("Total execution time: " + (endTime - startTime) );
	}
}
