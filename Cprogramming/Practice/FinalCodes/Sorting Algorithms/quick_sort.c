// Quick sort algo
#include <stdio.h>

void quicksort(int [], int, int);


int main()
{   
    int arr[] = {545, 12, 87, 23, 5, 56, 53, 1};     // this is the array to be sorted
    int i, size = 8;     // size is the no. of elements in the array

    quicksort(arr, 0, size-1);

    // This prints the elements of sorted array
    printf("Sorted elements: ");
    for(i=0; i<size; i++)
        printf(" %d", arr[i]);

    getch();
    return 0;
}


void quicksort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;

        while(i < j)
        {
            // Searching the no. greater than a[pivot]
            // After this loop is terminated, i = index of the element having value greater than a[pivot]
            while(a[i] <= a[pivot] && i < high)
                i++;
            
            // searching the no. less than or equal to a[pivot]
            // After this loop is terminated, j = index of the element having value less than or equal to a[pivot]
            while(a[j] > a[pivot])
                j--;
            
            if(i < j)
            {
                // swapping a[i] and a[j]
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        // swapping a[pivot] and a[j]
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}
