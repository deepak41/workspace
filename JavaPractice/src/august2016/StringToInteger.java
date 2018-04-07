package august2016;

public class StringToInteger {
	
	public static void main(String args[]) {

		String input = "7863723";
		int result = 0;
		int len = input.length();
		
		for(int i=0; i<len; i++) {
			int asciiValue = (int) input.charAt(i);
			int numValue = Character.getNumericValue(asciiValue);

			result = result + (numValue * (int)Math.pow(10, len-1-i));
		}
		
		System.out.println("***output = " + result);
	}
}
