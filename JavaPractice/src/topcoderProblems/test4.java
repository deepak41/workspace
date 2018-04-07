package TopcoderProblems;

class test4
{  
    int id;  
      
    test4(int i)
    {  
    	id = i;  
    
    }  
    void display()
    {
    	System.out.println(id);
    }  
   
    public static void main(String args[])
    {  
    	test4 s1 = new test4(111); 
    	test4 s2 = s1;  
    	s1.display();  
    	s2.display();  
   }  
}  