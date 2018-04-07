package august2016;

public class FindSubstring {
	
	public static void main(String args[]) {
		
		String input = "LeonardoDaVinci";
		String result = "";
		
		int low = 3, high = 9;

		for(int i=low; i<high; i++) {
			char ch = input.charAt(i);
			result = result + ch;
		}
		
		System.out.println("result = " + result);
	}
}
