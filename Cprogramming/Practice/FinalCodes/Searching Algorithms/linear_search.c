#include <stdio.h>

void linear_search(int [], int, int);
 
int main()
{
   int arr[] = {545, 12, 87, 23, 5, 56, 53, 1};
   int item, size = 8;
   
   item = 23;
   
   linear_search(arr, size, item);
   
   getch();
   return 0;
}

void linear_search(int a[], int size, int item)
{
    int i;
    
    // Linear search begins
    for (i = 0; i < size; i++)
    {
      if (a[i] == item)     // if required element found
      {
         printf("%d is present at location %d.\n", item, i+1);
         break;
      }
    }
    
    if (i == size)     // if required element not found
      printf("%d is not present in array.\n", item);     
}
