#include<stdio.h>
 
void mergesort(int [], int, int );
void merge(int [], int, int, int, int);
 

int main()
{
    int i, n=8;
    int a[] = {545, 12, 87, 23, 5, 56, 53, 1};
    
    mergesort(a, 0, n-1);
    
    printf("\nSorted array is :");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    
    getch();    
    return 0;
}
 

void mergesort(int a[], int low, int high)
{
    int mid;
        
    if(low < high)
    {
        mid = (low + high)/2;
        
        mergesort(a, low, mid);        //left recursion
        mergesort(a, mid+1, high);    //right recursion
        merge(a, low, mid, mid+1, high);    //merging of two sorted sub-arrays
    }
}
 

void merge(int a[], int low1, int high1, int low2, int high2)
{
    int temp[50];    //array used for merging
    int i, j, k;
    i = low1;    //beginning of the first list
    j = low2;    //beginning of the second list
    k = 0;
    
    while(i <= high1 && j <= high2)    //while elements in both lists
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while(i <= high1)    //copy remaining elements of the first list
        temp[k++] = a[i++];
        
    while(j <= high2)    //copy remaining elements of the second list
        temp[k++] = a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=low1, j=0; i<=high2; i++, j++)
        a[i] = temp[j];
}
