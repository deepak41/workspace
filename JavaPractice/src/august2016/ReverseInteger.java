package august2016;

public class ReverseInteger {
	
	public static void main(String args[]) {
		
		int number = 1234567;
		int result = 0;
		
		while (number > 0) {
			int digit = number % 10;
			result = result*10 + digit;
			
			number = number / 10;
		}
		
		System.out.println(result);
		
	}

}
