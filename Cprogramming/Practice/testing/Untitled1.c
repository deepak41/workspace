#include<conio.h>
#include<stdio.h>

typedef struct node
{  int data;
   struct node *left,*right;
   int ht;
}node;


  node *insert(node *,int);
 
  void  preorder(node *);
  void  inorder(node *);
  int   height( node *);
  node *rotateright(node *);
  node *rotateleft(node *);
  node *RR(node *);
  node *LL(node *);
  node *LR(node *);
  node *RL(node *);
  int BF(node *);

  
void main()
{
    node *root=NULL;
    int x,n,i,op;
    
    printf("\nEnter no.of elements :");
    scanf("%d",&n);
    
    printf("\n Enter tree data :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    
    inorder(root);
    getch();
              
}

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else if(x > T->data)                // insert in right subtree
    {
        T->right = insert(T->right,x);
        
        if(BF(T)==-2)
        {
                     
            if(x>T->right->data)
                printf("a");
                //T=RR(T);
            else
                printf("b");
                //T=RL(T);  
        }
    }
    else if(x<T->data)
    {
        T->left=insert(T->left,x);
        
        if(BF(T)==2)
        {
            if(x < T->left->data)
                printf("c");
                //T=LL(T);
            else
                printf("d");
                //T=LR(T);
        }
    }
    
    T->ht=height(T);
    return(T);
}

int height(node *p)
{
    int h1=0, h2=0;
    
    if(p==NULL)
        return(0);
    else
    {    
        h1=height(p->left);
        h2=height(p->right);
        
        return(1+max(h1,h2));
    }
}


int BF(node *T)
{
    int lh,rh;
    
    if(T==NULL)
        return(0);
    
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    
    return(lh-rh);
}

void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("\n %d (height=%d)", T->data, height(T));
        inorder(T->right);
    }
}



int max(int a, int b)
{
  return (a >= b)? a: b;
} 

