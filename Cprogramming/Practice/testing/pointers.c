#include<conio.h>
#include<stdio.h>

int main()
{
    int* n, a;
    
    int k=10;
    // a=&k;
    //*a=87;
    
    n = &k;

    printf("%d\n", *n);
    printf("%u", n);
    
    getch();
    return 0;    
}
