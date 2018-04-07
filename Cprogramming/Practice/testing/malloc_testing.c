#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *a;
    a = malloc(sizeof(struct node));
    
    printf("%d\n", a);
    printf("%d", a->link);
    
    getch();
    return 0;
}
