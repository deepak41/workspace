#include <stdio.h>
#include <conio.h>
 
int main()
{
    int vkmh, vmax=50;
    
      do
      {
        scanf("%f", &vkmh);
        if (vkmh <= vmax)
        {
        }           
        else if (vkmh < 0)
        {
            printf("Error, speed must be positive.\n");
        }
        else if (vkmh > vmax)
        {
            printf("Error, the max speed of this vehicle is listed as %.fkm/h.\nIt cannot exceed that value. Please enter a value under %.f.\n", vmax, vmax);
        }
        else if (vkmh != getchar())
        {
            printf("Error in input. Please only use numbers\n");
        }
    }
    while(vkmh > vmax || vkmh < 0 || vkmh != getchar());


    
    
    getch();
    return 0;
}

