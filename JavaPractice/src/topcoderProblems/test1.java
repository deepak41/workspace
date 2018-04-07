package TopcoderProblems;

import java.util.*;

public class test1 {

	public static void main(String args[]) {
		// Creating an empty array list
		ArrayList<String> list = new ArrayList<String>();

		// Adding items to arrayList
		list.add("Item1");
		list.add("Item2");
		list.add(2, "Item3"); // it will add Item3 to the third position of
								// array list
		list.add("Item4");

		// Display the contents of the array list
		System.out.println("The arraylist contains the following elements: "
				+ list);

		

	

		// Getting the size of the list
		int size = list.size();
		System.out.println("The size of the list is: " + size);

		

		// Replacing an element
		list.set(1, "NewItem");
		System.out.println("The arraylist after the replacement is: " + list);

		// Removing items
		// removing the item in index 0
		list.remove(0);

		// removing the first occurrence of item "Item3"
		list.remove("Item3");

		System.out.println("The final contents of the arraylist are: " + list);

		// Converting ArrayList to Array
		String[] simpleArray = list.toArray(new String[list.size()]);
		System.out
				.println("The array created after the conversion of our arraylist is: "
						+ Arrays.toString(simpleArray));
	}
}
