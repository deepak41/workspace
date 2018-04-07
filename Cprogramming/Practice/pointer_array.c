#include <stdio.h>
#include <conio.h>
 
int main()
{
    int a[]={9,1,2,3,4};
    int *p[]={a,a+1,a+2,a+3,a+4};
    
    printf("%d\t%d\n",p,&p[0]);
    printf("%d\n",*p);
    printf("%d\n",*(*p));
    
    getch();
    return 0;
}


