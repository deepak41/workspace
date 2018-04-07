#include <stdio.h>
#include <conio.h>
 
int main()
{
    char *p="hello";
    *p='h';
    
    printf("%d\n",p);
    p="ghgh";
    printf("%d",p);
    
    getch();
    return 0;
}

