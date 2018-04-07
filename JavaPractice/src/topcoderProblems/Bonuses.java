package TopcoderProblems;

import java.util.*;

public class Bonuses 
{
	public int[] getDivision(int[] points)
	{
		int len = points.length;
		int[] bonus = new int[len];
		int totalp=0,totalbon=0;
		for(int i=0; i<len; i++)
		{
			totalp = totalp + points[i];
		}
		for(int i=0; i<len; i++)
		{
			bonus[i] = (points[i]*100)/totalp;
			totalbon = totalbon + bonus[i];
		}
		if(totalbon != 100)
		{
			
		}
		return bonus;
	}
	public static void main(String[] args)
	{
		int[] p = {1,2,3,4,5};
		Bonuses a = new Bonuses();
		System.out.println(Arrays.toString(a.getDivision(p)));
	}
}
