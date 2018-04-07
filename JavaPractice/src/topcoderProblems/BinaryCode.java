package topcoderProblems;

public class BinaryCode
{
	public String[] decode(String message)
	{
		int len = message.length();
		String[] result = new String[2]; //The two decoded strings will be stored in this array.
		if(len>0 && len<=50)             //This statement is to ensure the length of message is between 0 & 50.
		{
			boolean c = false;
			for(int i=0; i<len; i++)   //This loop is to check if the digits consist 0,1,2,3 only. 
			{
				int a = Character.getNumericValue(message.charAt(i));
				if(a==0 || a==1 || a==2 || a==3)
				{
					c=true;
				}
				else
					c=false;
			}
			if(c)
			{
				if(len==1)     //This if statement checks if the message is of 1 character.
				{
					System.out.println("INVALID NUMBER! Number must be atleast 2 digit.");
					return result;
				}
				else                          //When every constraints are met this else block is executed.
				{                
					int[] coded = new int[len];     //message is stored in this array
					int[] orgnl = new int[len];     //the decoded message is stored here
					for(int i=0; i<len; i++)            //This loop stores the message as int array form
					{
						coded[i] = Character.getNumericValue(message.charAt(i));
					}
					for(int z=0; z<=1; z++)           //this loop is for storing decoded strings in result[]
					{
						if(z==0)                                //the logic for decoding starts here
							orgnl[0]=0;
						else
							orgnl[0]=1;
						for(int i=0; i<len; i++)
						{
							if(i==0)
							{
								orgnl[i+1]=coded[i]-orgnl[i];
							}
							else if(i==len-1)
							{
								orgnl[i]=coded[i]-orgnl[i-1];
							}
							else
							{
								orgnl[i+1]=coded[i]-orgnl[i-1]-orgnl[i];
							}
						}                                             //the logic for decoding stops here
						boolean flag=true;
						for(int i=0; i<len; i++)       //this loop block checks if decoded nos. are binary
						{
							if(orgnl[i]==0 || orgnl[i]==1)
								flag=true;
							else
							{
								flag=false;
								break;
							}
						}  
						if(flag)       //in this if block the decoded number is stored in a string
						{
							String r = "";
							for (int i=0; i<orgnl.length; i++) 
							{
								r = r + orgnl[i];
							}
							result[z] = r;
						}
						else
							result[z]="NONE";
					}
			        return result;
				}
			}
			else
			{
				System.out.println("INVALID NUMBER! Number must be made of 0, 1, 2 and 3 only.");
				return result;
			}
		}
		else
		{
			System.out.println("INVALID NUMBER! Number must be between 1 & 50.");
			return result;
		}
	}
	public static void main(String[] args)
	{
		BinaryCode bc = new BinaryCode();
		bc.decode("vvv");
	}
}