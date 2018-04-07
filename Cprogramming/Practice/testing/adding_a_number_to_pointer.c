#include <stdio.h>
#include <conio.h>
 
int main()
{
    int i=4, *j,*p;
    float k=10.8,l=87.9;
    char c = 'a';
    j=&i;
    p=j-3;
    *p=90;
    
    printf("c     = %d\n", &c);
    printf("k     = %d\n", &k);
    printf("l     = %d\n", &l);
    printf("j     = %d\n", j);
    printf("j + 1 = %d\n", j+1);
    printf("j + 5 = %d\n", j+5);
    printf("p     = %d\n", *p);
    
    getch();
    return 0;
}

