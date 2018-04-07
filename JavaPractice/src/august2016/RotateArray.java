package august2016;

import java.util.Arrays;


public class RotateArray {
	
	public static void main(String args[]) {
		
		String str1[] = {"Poland","England", "Italy", "Romania","Germany","Turkey","Belgium","Austria","Netherlands","Croatia", "France"};
		
		int mid = str1.length/2;
		int count=0;
		
		mid--;
		
		for(int i=mid; i>=0; i--) {
			int k;
			
			if(str1.length%2 == 0) {
				k=1+2*count;
			}
			else{
				k=2+2*count;
			}
			
			String temp = str1[i];
			str1[i] = str1[i + k];
			str1[i + k] = temp;
			
			count++;
		}
		
		System.out.println(Arrays.toString(str1));
	}
}
