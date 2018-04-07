// Insertion sort algo
#include <stdio.h>
#include <conio.h>

void insertion_sort(int [], int);


int main()
{
    int arr[10] = {67, 93, 36, 21, 453, 34, 1211, 175, 54, 29};   // This is the array to be sorted
    int i, size = 10;   // size is the no. of elements in the array
    
    insertion_sort(arr, size);

    // This prints the elements of the sorted array
    printf("After sorting the array is: ");
    for(i=0; i<size; i++)
        printf(" %d", arr[i]);

    getch();
    return 0;
}


void insertion_sort(int a[], int n)
{
    int i, j, temp;
    
    // Total no. of iterations required is n-1
    // Iteration starts with 1st element i.e a[1] and ends with the last element i.e a[n-1]
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i-1;
        
        // temp is one by one compared with all the elements which are at LHS to a[i]
        while((a[j] > temp) && (j >= 0))
        {
            a[j+1] = a[j];   // the value of a[j] is copied to the just next element
            j--;
        }
        a[j+1] = temp;   // Here, j will be either -1 or the index in which value is not greater than temp
    }
}
