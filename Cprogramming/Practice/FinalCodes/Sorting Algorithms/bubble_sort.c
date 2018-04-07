// Bubble sort algo
#include <stdio.h>
#include <conio.h>

void bubble_sort(int [], int);


int main()
{
    int arr[10] = {67, 93, 36, 21, 453, 34, 1211, 175, 54, 29};     // This is the array to be sorted
    int i, size = 10;     // size is the no. of elements in the array
    
    bubble_sort(arr, size);
    
    // This prints the elements of the sorted array
    printf("After sorting the array is: ");
    for(i=0; i<size; i++)
        printf(" %d", arr[i]);

    getch();
    return 0;
}


void bubble_sort(int a[], int n)
{
    int i, step, temp;
    
    for(step=0; step<n; step++)
    {
        for(i=0; i<(n-1)-step; i++)
        {
            if(a[i] > a[i+1])     // comparision between adjacent elements
            {
                // swapping operation
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            } 
        }
    }
}
