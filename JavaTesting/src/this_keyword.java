class Frog{
	
	String name;
	
	public void setName(String name){
		this.name = name;
		System.out.println(this);
	}
	
}

public class this_keyword {
	
	public static void main(String[] args) {
		
		Frog frog1 = new Frog();
		frog1.setName("hello");
	}
}