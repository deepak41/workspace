package Package1;

class selectionsort
{
	public static void main(String args[])
	{
		int n[]={78,34,56,16,49};
		for(int i=0;i<5;i++)
		{
			for(int j=i+1;j<5;j++)
			{
				if(n[i]>n[j])
				{
					int temp=n[i];
					n[i]=n[j];
					n[j]=temp;
				}
			}
		}
		mytools.printArray(n);
	}
}
