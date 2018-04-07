package Package1;

class insertionsort 
{
	public static void main(String args[])
	{
		int n[]={78,34,56,16,48};
		for(int i=1;i<5;i++)
		{
			int temp=n[i];
			int j;
			for(j=i-1;j>=0 && temp>n[j];j--)
			{
				n[j+1]=n[j];
			}
			n[j+1]=temp;
		}
		
		mytools.printArray(n);
	}
}

