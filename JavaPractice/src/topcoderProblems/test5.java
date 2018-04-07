package TopcoderProblems;


class t
{
	int n = 45;
	int n2 = 87;
	void msg()
	{
		System.out.println("Hello");
	}
}

class test5 extends t
{  
	public static void main(String[] args)
	{
		t t1 = new t();
		System.out.println(t1.n2);
		
		test5 tt = new test5();
		System.out.println(tt.n2);
	}
} 

