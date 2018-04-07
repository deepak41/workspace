#include <stdio.h>
#include <conio.h>
 
int main()
{
    int ivar = 100;
    char cvar = 'a';
    float fvar = 10.10;

    printf("%d\n", sizeof(ivar));
    printf("%d\n", sizeof(cvar));
    printf("%d\n", sizeof(fvar));
    
    getch();
    return 0;
}

