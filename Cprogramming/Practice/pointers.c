#include <stdio.h>
#include <conio.h>
 
int main()
{
    int i=39088;
    printf("address of i = %u \n", &i);
    printf("value of i = %d \n", *(&i));
    getch();
    return 0;
}

