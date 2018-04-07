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
    struct node *p;
    p = NULL;
    
    printf("No. of elements in the Linked List = %d\n", count(p));
    append(&p,1);
    append(&p,2);
    append(&p,3);
    append(&p,4);
    append(&p,17);
    
    display(p);
    
    addatbeg(&p,999);
    addatbeg(&p,888);
    addatbeg(&p,777);
    
    display(p);
    
    addafter(p,7,0);
    addafter(p,2,1);
    addafter(p,1,99);
    
    display(p);
    printf("No. of elements in the Linked List = %d\n", count(p));
    
    deleteNode(&p,888);
    deleteNode(&p,1);
    deleteNode(&p,777);
    
    display(p);
    printf("No. of elements in the linked list = %d\n", count(p));
    
    getch();
    return 0;
}

append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    
    if(temp == NULL)
    {
          temp = malloc(sizeof(struct node));
          temp->data = num;
          temp->link = NULL;
          *q = temp;
    }
    else
    {
          temp = *q;
          
          while(temp->link != NULL)
              temp = temp->link;
              
          r = malloc(sizeof(struct node));
          r->data = num;
          r->link = NULL;
          temp->link = r;
    }
}                            

addatbeg(struct node **q, int num)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;
    
    temp = q;
    
    for(i=0;i<loc;i++)
    {
        temp = temp->link;
        if(temp == NULL)
        {
            printf("There are less than %d elements in list\n", loc);
            return 0;
        }
    }
    r = malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

display(struct node *q)
{
    printf("\n");
    
    while(q != NULL)
    {
        printf("%d", q->data);
        q = q->link;
    }
}

count(struct node *q)
{
    int c = 0;
    
    while(q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}

deleteNode(struct node **q, int num)
{
    struct node *old, *temp;
    
    temp = *q;
    
    while(temp != NULL)
    {
        if(temp->data == num)
        {
            if(temp == *q)
            {
                *q = temp->link;
                free(temp);
                return 0;
            }
            else
            {
                old->link = temp->link;
                free(temp);
                return 0;
            }
        }
        else
        {
            old = temp;
            temp = temp->link;
        }
    }
    printf("Element %d not found\n", num);
}
