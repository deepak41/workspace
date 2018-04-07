#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} node;


void append(node**, int);
void add_at_beg(node**, int);
void add_after(node*, int, int);
void deleteNode(node **h, int value);


int main()
{
    node *head;
    head = NULL;
    
    printf("No. of elements in the Linked List = %d\n", count(head));
    append(&head,1);
    append(&head,1);
    append(&head,3);
    append(&head,4);
    append(&head,17);

    display(head);
   
    add_at_beg(&head,999);
    add_at_beg(&head,888);
    add_at_beg(&head,777);
    
    display(head);
     
    add_after(head,7,0);
    add_after(head,2,1);
    add_after(head,1,99);
    add_at_beg(&head,777);
    
    display(head);
    printf("\nNo. of elements in the Linked List = %d\n", count(head));
    
    //deleteNode(&head,888);
    //deleteNode(&head,1);
    deleteNode(&head, 1);
    deleteNode(&head, 777);
    
    display(head);
    printf("No. of elements in the linked list = %d\n", count(head));
    
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


// inserts a new node at the beginning of the linked list.
void add_at_beg(node **h, int value)
{
    node *temp;
    
    temp = malloc(sizeof(node));
    temp->data = value;
    temp->next = *h;     // the link part of temp points to the head of the list
    
    *h = temp;     // makes temp as the head of the list
}


// Inserts after given no. of nodes
void add_after(node *h, int n, int value)
{
    node *temp, *current;
    int i;
    
    temp = (node*)malloc(sizeof(node));
    temp->data = value;
    
    current = h;
    
    for(i=1; i<n; i++)     // Traverse to the nth node of the list
    {
        current = current->next;
    }
    
    temp->next = current->next;     // the link part of temp points to the (n+1)th node of the list
    current->next = temp;     // the link part of nth node points to temp
}


// deletes all the nodes having the given value
void deleteNode(node **h, int value)
{
    node *current, *temp;
    current = *h;
    
    while(current != NULL)
    {
        // if the node to be deleted is the first node of the list
        if(current == *h && current->data == value)    
        {
            temp = *h;
            *h = current->next;     // the next node becomes head
            free(temp);
            
            current = *h;
        }
        // if the node to be deleted is other than first node
        else if(current->next != NULL && current->next->data == value)
        {
            temp = current->next;     // this node is to be deleted
            current->next = temp->next;
            free(temp);
        }
        else
            current = current->next;
    }                  
}


// for displaying the linked list
display(node *q)
{
    printf("\n");
    
    while(q != NULL)
    {
        printf("%d => ", q->data);
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
