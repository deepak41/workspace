/* Fibonacci Series c language */
#include<stdio.h>
 
int main()
{
   int n, first = 0, second = 1, next, c, r1,r2;
 
   printf("Enter r1\n");
   scanf("%d",&r1);
   
   printf("Enter r2\n");
   scanf("%d",&r2);
 
   
 
   for ( c = 0 ; c < 100 ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      //printf("%d\n",next);
      
      if(next>=r1 && next<=r2 && next%4==0)
      {
          printf("%d", next);
          break;
      }
   }
 
   
   getch();
   return 0;
}
