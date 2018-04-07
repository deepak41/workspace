#include <stdio.h>
#include <conio.h>
 
int main()
{
    int i=54;
    float a=3.14;
    char *ii, *aa;
    
    ii=(char *)&i;
    aa=(char *)&a;
    
    printf("address in ii = %u \n", ii);
    printf("address in aa = %u \n", aa);
    printf("value at address contained in ii = %d", *aa);
    
    getch();
    return 0;
}


