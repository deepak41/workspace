#include <stdio.h>
#include <conio.h>
 
int main()
{
    int i=39088;
    int *j;
    int **k;
    
    j=&i;
    k=&j;
    
    printf("address of i = %u \n", &i);
    printf("value of j = %d \n", j);
    printf("address of j = %d \n", &j);
    printf("value of k = %d \n", k);
    getch();
    return 0;
}


