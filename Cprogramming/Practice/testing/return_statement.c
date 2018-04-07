#include <stdio.h>
#include <conio.h>
 
int main()
{
    int a[]={53, 45, 34, 45, 4556,4534,242,4543};
    int needle=4556,i;
    
    for (i=0; i < 7; i++) 
    {
        printf("%d\n", a[i]);
        if (a[i] == needle) 
        {
           getch();
           return 0;
        }
    }
    
    getch();
    return 0;
}



