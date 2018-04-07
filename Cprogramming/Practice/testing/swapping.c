#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a[]={10, 50};
    
    swap(&a[0], &a[1]);
    
    printf("%d\n", a[0]);
    printf("%d", a[1]);

    getch();
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp; 
}
