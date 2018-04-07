#include <stdio.h>

int recurse ( int count ) /* Each call gets its own copy of count */
{
    
    printf( "%d\n", count );
    /* It is not necessary to increment count since each function's
       variables are separate (so each count will be initialized one greater)
     */
    recurse ( count + 1 );
    printf("hello %d\n", count);

}

int main()
{
  recurse ( 1 ); /* First function call, so it starts at one */
  
  getch();
  return 0;
}
