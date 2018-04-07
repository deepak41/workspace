package Package1;

class bubblesort 
{
	public static void main(String args[])
    {
		int n[] = {78, 34, 56, 16, 48};
		boolean flag;
		do
		{
			flag = false;
			for(int i=0; i<4; i++)
			{
				if(n[i] > n[i+1])
				{
					int temp = n[i];
					n[i] = n[i+1];
					n[i+1] = temp;
					flag = true;
				}
			}
		}while(flag == true);
		
		mytools.printArray(n);
	}
}