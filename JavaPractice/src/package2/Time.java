package Package2;

public class Time 
{
	public String whatTime(int seconds)
	{
		int sec = seconds;
		String result = "";
		if(sec >= 0 && sec <= 86399)
		{
			int h,m,s;
			if(sec>=3600)
			{
				h = sec/3600;
				int rem = sec%3600;
				if(rem>=60)
				{
					m = rem/60;
					s = rem%60;
				}
				else
				{
					m = 0;
					s = rem;
				}
			}
			else
			{
				h = 0;
				m = sec/60;
				s = sec%60;
			}
			result = h+":"+m+":"+s;
			return result;
		}
		else
			return result;
	}
	
	public static void main(String args[])
	{
		Time a = new Time();
		String s = a.whatTime(4639);
		System.out.println(s);
	}
}
