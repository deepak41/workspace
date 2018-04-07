#include <stdio.h>

void binary_search(int list[], int lo, int hi, int key);
 
int main()
{
   int arr[] = {4, 35, 42, 67, 81, 103, 119, 126};     // the array must be sorted
   int item, size = 8;
   int lo = 0, hi = size-1; 
   
   item = 103;
   
   binary_search(arr, lo, hi, item);
   
   getch();
   return 0;
}


void binary_search(int a[], int lo, int hi, int key)
{
    int mid;
 
    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    
    mid = (lo + hi) / 2;
    
    if (a[mid] == key)
    {
        printf("Key found\n");
    }
    else if (key < a[mid])
    {
        binary_search(a, lo, mid - 1, key);
    }
    else if (key > a[mid])
    {
        binary_search(a, mid + 1, hi, key);
    }
}
