#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
};

void addq(struct node **, struct node **, int);
delq(struct node **, struct node **);

int main()
{
    struct node *front, *rear;
    int item;
    
    front=rear=NULL;
    
    addq(&front, &rear, 11);
    addq(&front, &rear, 12);
    addq(&front, &rear, 13);
    addq(&front, &rear, 14);
    addq(&front, &rear, 15);
    addq(&front, &rear, 16);
    addq(&front, &rear, 17);
    
    q_display(front);
    printf("No. of items in queue = %d\n", count(front));
    
    printf("Items extracted from queue:\n");
    item = delq(&front, &rear);
    printf("%d", item);
    
    item = delq(&front, &rear);
    printf("%d", item);
    
    item = delq(&front, &rear);
    printf("%d", item);
    
    printf("\n");
    
    q_display(front);
    
    printf("No. of items in queue = %d\n", count(front));
    
    getch();
    return 0;
}

void addq(struct node **f, struct node **r, int item)
{
     struct node *q;
     
     q = malloc(sizeof(struct node));
     q->data = item;
     q->link = NULL;
     
     if(*f == NULL)
         *f = q;
     else
         (*r)->link = q;
         
     *r = q;
}

delq(struct node **f, struct node **r)
{
    struct node *delitem;
    delitem = *f;        
    *f = (*f)->link;
            
    return (delitem->data);        
}

q_display(struct node *q)
{
    printf("front->");
    
    while(q != NULL)
    {
        printf(" %d ", q->data);
        q = q->link;
        
        if(q == NULL)
            printf("<-rear");
    }
    printf("\n");
}

count(struct node *q)
{
    int c=0;
    
    while(q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}
