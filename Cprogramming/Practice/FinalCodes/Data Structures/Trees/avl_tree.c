// Implementation of AVL tree(Self-balancing BST)
#include<stdio.h>

typedef struct avlNode 
{  
    int data;
    struct avlNode *left, *right;
    int ht;
}avlNode, tnode;


avlNode* insert(avlNode*, int);
avlNode* Delete(avlNode*, int);
void inorder(avlNode*);
int height(avlNode*);
avlNode* rotateright(avlNode*);
avlNode* rotateleft(avlNode*);
avlNode* RR(avlNode*);
avlNode* LL(avlNode*);
avlNode* LR(avlNode*);
avlNode* RL(avlNode*);
int BF(avlNode*);
avlNode* createNode(int);
avlNode* FindMin(avlNode*);

  
int main()
{
    avlNode *root = NULL;
    int x, n, i, op;
    do
    {
        printf("1. Create the tree automatically \n");
        printf("2. Insert \n");
        printf("3. Delete \n");
        printf("4. Print the tree \n");
        printf("5. Quit \n");
        
        printf("Enter Your Choice : ");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1:
                root = NULL;
                int arr[] = {545, 12, 187, 23, 120, 56, 53, 202, 325, 276, 748, 8, 19}; 
                
                for(i=0;i<13;i++)
                {
                    root = insert(root, arr[i]);
                }
                
                printf("TREE CREATED!\n\n");
                       
                break;
                
            case 2:
                do
                {
                    printf("\nEnter the data to be inserted : ");
                    scanf("%d", &x);
                        
                    if(x!=0)
                    {
                        root = insert(root, x);
                    }
                }while(x!=0);
                
                break;
            case 3:
                printf("\nEnter the data to be deleted: ");
                scanf("%d", &x);
                    
                root = Delete(root, x);
                break;
            case 4:
                printf("\n****** This is the TREE ******\n\n");
                print_t(root);
                break;
        }
    }while(op!=5);
    
    return 0;
}


// Function to insert a value in the tree
avlNode* insert(avlNode *node, int value)
{
    if(node == NULL)
    {
        node = createNode(value);     // this function creates a new node and returns its address
    }
    else if(value > node->data)                
    {
        node->right = insert(node->right, value);     // insert in the right subtree
        
        if(BF(node) == -2)     // if right subtree has greater height
        {
            if(value > node->right->data)     // if value has been inserted in the right subtree of node's right child
                node = RR(node);
            else     // if value has been inserted in the left subtree of node's right child
                node = RL(node);     
        }
    }
    else if(value < node->data)
    {
        node->left = insert(node->left, value);     // insert in the left subtree
        
        if(BF(node) == 2)     // if left subtree has greater height
        {
            if(value < node->left->data)     // if value has been inserted in the left subtree of node's left child
                node = LL(node);
            else     // if value has been inserted in the right subtree of node's left child
                node = LR(node);
        }
    }
    
    node->ht = height(node);
    
    return node;
}


// Function to delete a value from tree
avlNode* Delete(avlNode *node, int value)
{   
    // First, standard BST delete is performed    
    if(node == NULL)
	{
        printf("Element Not Found");
    }
    // If the value to be deleted is smaller than the node data, then it lies in left subtree
	else if(value < node->data)
    { 
        node->left = Delete(node->left, value);
    }
    // If the value to be deleted is greater than the node data, then it lies in right subtree
	else if (value > node->data)
    { 
        node->right = Delete(node->right, value);
    }
	// If value is equal to node data, then this is the node to be deleted	
	else 
    {
		// Case 1: The node to be deleted has no child
		if(node->left == NULL && node->right == NULL) 
        { 
			free(node);
			node = NULL;
		}
		//Case 2: The node to be deleted has one child(right child)
		else if(node->left == NULL) 
        {
			avlNode *temp = node;
			node = node->right;     // the right child is set at the place of the node to be deleted
			free(temp);
		}
		//Case 2: The node to be deleted has one child(left child)
		else if(node->right == NULL)
        {
			avlNode *temp = node;
			node = node->left;     // the left child is set at the place of the node to be deleted
			free(temp);
		}
		// case 3: The node to be deleted has 2 children
		else 
        { 
			avlNode *temp = FindMin(node->right);     //the minimum value in the node's right subtree is searched
			node->data = temp->data;     // node data is replaced by the minimum value
			
            node->right = Delete(node->right, temp->data);     // the node whose data was copied is deleted
		}
	}
	// above this line, code is same as deletion in BST
	
	// If the tree had only one node(which has now been deleted) then return
    if (node == NULL)
      return node;
	
	// UPDATE HEIGHT OF THE CURRENT NODE
	node->ht = height(node);
	
	// If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (BF(node) > 1 && BF(node->left) >= 0)
        return LL(node);
 
    // Left Right Case
    if (BF(node) > 1 && BF(node->left) < 0)
    {
        return LR(node);
    }
 
    // Right Right Case
    if (BF(node) < -1 && BF(node->right) <= 0)
        return RR(node);
 
    // Right Left Case
    if (BF(node) < -1 && BF(node->right) > 0)
    {
        return RL(node);
    }
 
    return node;
}


int height(avlNode *node)
{
    int h1, h2;
    
    if(node == NULL)
        return(0);
        
    else
    {    
        h1 = height(node->left);
        h2 = height(node->right);
        
        return(1 + max(h1, h2));
    }
}


avlNode* rotateright(avlNode *node)
{
     /*
              A             
             /                B
            B       =>       /\
           /                C  A
          C
    */
    
    avlNode *k;
    
    k = node->left;
    node->left = k->right;
    k->right = node;
    
    node->ht = height(node);
    k->ht = height(k);
    
    return(k);
}


avlNode* rotateleft(avlNode *node)
{
     /*
              A             
               \                 B
                B       =>      /\
                 \             A  C
                  C
    */
    
    avlNode *k;
    
    k = node->right;
    node->right = k->left;
    k->left = node;
    
    node->ht = height(node);
    k->ht = height(k);
    
    return(k);
}


avlNode* RR(avlNode *node)
{
    /*
              A             
               \                 B
                B       =>      /\
                 \             A  C
                  C
    */
    
    node = rotateleft(node);
    return(node);
}


avlNode* LL(avlNode *node)
{
    /*
              A             
             /                B
            B       =>       /\
           /                C  A
          C
    */
    
    node = rotateright(node);
    return(node);
}


avlNode* LR(avlNode *node)
{
     /*
              A                      A
             /                      /                     C
            B          =>          C          =>         /\
            \                     /                     B  A
             C                   B
     */
    
    node->left = rotateleft(node->left);
    node = rotateright(node);
    
    return(node);
}


avlNode* RL(avlNode *node)
{
     /*
              A                 A
               \                 \                   C
                B       =>        C        =>       /\
               /                   \               A  B
              C                     B
     */
    
    node->right = rotateright(node->right);
    node = rotateleft(node);
    
    return(node);
}


int BF(avlNode *node)
{
    int lh, rh;
    
    if(node->left == NULL)
        lh = 0;
    else
        lh = node->left->ht;
    
    if(node->right == NULL)
        rh = 0;
    else
        rh = node->right->ht;
    
    return(lh-rh);
}


avlNode* FindMin(avlNode* root)
{
	while(root->left != NULL) 
        root = root->left;
	
    return root;
}


void inorder(avlNode *node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("\n %d (BF=%d)", node->data, BF(node));
        inorder(node->right);
    }
}


avlNode* createNode(int value)
{
    avlNode *temp = (avlNode*) malloc(sizeof(avlNode));   // create a new node
    
    temp->data = value;
    temp->left = NULL;   
    temp->right = NULL;
    
    return temp;        
}


int max(int a, int b)
{
  return (a >= b)? a: b;
} 





/*--------------------------------------------
******  CODE TO DISPLAY THE TREE  ******
-----------------------------------------------*/

int _print_t(tnode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int i, width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

int print_t(tnode *tree)
{
    char s[20][255];
    int i;
    
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}
