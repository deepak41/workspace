#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} node;


void append(node**, int);



int main()
{
    node *head;
    head = NULL;
    
    printf("No. of elements in the Linked List = %d\n", count(head));
    append(&head,1);
    append(&head,1);
    append(&head,88);
    append(&head,4);
    append(&head,17);
    append(&head,33);
    append(&head,85);
    append(&head,57);

    display(head);
    
    
    
    
    getch();
    return 0;
}


// inserts a new node at the end of the linked list
void append(node **h, int value)
{
    node *temp, *current;
    
    temp = malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    
    if(*h == NULL)     // if the list(or head) is empty
    {
        *h = temp;     // makes temp as the head of the list
    }
    else
    {
        current = *h;
          
        while(current->next != NULL)     // Traverse to the last node of the list
            current = current->next; 
            
        current->next = temp;     // the link part of last node points to temp
    }
} 






// for displaying the linked list
display(node *q)
{
    printf("\n");
    
    while(q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }
    printf("NULL");
}


// counts the no. of nodes in the list
count(node *q)
{
    int c = 0;
    
    while(q != NULL)
    {
        q = q->next;
        c++;
    }
    return c;
}

