package august2016;

public class ReverseString {
	
	public static void main(String args[]) {
		
		String input = "LeonardoDaVinci";
		String result = "";
		
		int len = input.length();
		
		for(int i=len-1; i>=0; i--) {
			char ch = input.charAt(i);
			result = result + ch;
		}
		
		System.out.println("result = " + result);
	}
}
