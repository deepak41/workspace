/* Fibonacci Series c language */
#include<stdio.h>
 
int main()
{
   int first = 0, second = 1, next, c=0, r1, r2, flag=1;
 
   printf("Enter r1\n");
   scanf("%d",&r1);
   
   printf("Enter r2\n");
   scanf("%d",&r2);
 
   while(flag)
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      
      if(next>=r1 && next<=r2 && next%4==0)
      {
          printf("%d", next);
          flag=0;
      }
      c++;
   } 
   
   getch();
   return 0;
}

