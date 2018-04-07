package august2016;

public class IntegerToString {
	
	public static void main(String args[]) {

		int number = 232362;

		while (number > 0) {
			
			int digit = number % 10;
			number = number / 10;
		}
		
		int asciiValue = 68; 
		char c = (char) asciiValue;
		
		System.out.println("MMMMMMMMMMMM  "+c);
		System.out.println((int) 8);
	}

}
