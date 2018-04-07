// Selection sort algo
#include <stdio.h>
#include <conio.h>

void selection_sort(int [], int);


int main()
{
    int arr[10] = {67, 93, 36, 21, 453, 34, 1211, 175, 54, 29};   // This is the array to be sorted
    int i, size = 10;   // size is the no. of elements in the array
    
    selection_sort(arr, size);
    
    // This prints the elements of the sorted array
    printf("After sorting the array is: ");
    for(i=0; i<size; i++)
        printf(" %d", arr[i]);

    getch();
    return 0;
}


void selection_sort(int a[], int n)
{
    int i, j, temp;
    
    // Total no. of iterations required is n-1
    // Iteration starts with 0th element i.e a[0] and ends with the 2nd last element i.e a[n-2]
    for(i=0; i<=n-2; i++)
    {
        // The element a[i] is compared with all the elements to its RHS one by one
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                //Swapping operation between a[i] & a[j]
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
