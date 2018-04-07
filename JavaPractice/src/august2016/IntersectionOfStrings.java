package august2016;

import java.util.ArrayList;
import java.util.List;

public class IntersectionOfStrings {
	
	public static void main(String args[]) {
		
		String Str1[] = {"Poland","England", "Italy", "Romania","Germany","Turkey","Belgium","Austria","Netherlands","Netherlands","Croatia"};
		String Str2[] ={"Ukraine","Croatia","Netherlands", "Netherlands", "France","Spain","Italy","Portugal","Serbia","Belgium","England"};
		List<String> result = new ArrayList<String>();
		
		for(String s1 : Str1) {
			for(String s2 : Str2) {
				if(s1.equals(s2)) {
					result.add(s1);
					break;
				}
			}
		}
		
		System.out.println("Result = "+result);
	}
}
