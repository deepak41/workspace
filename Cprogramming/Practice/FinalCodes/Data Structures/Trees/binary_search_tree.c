#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode 
{  
    int data;
    struct bstnode *left, *right;
}bstnode, tnode;

bstnode* insert(bstnode*, int);
bstnode* createNode(int);
bstnode* Delete(bstnode*, int);
bstnode* FindMin(bstnode*);


int main()
{
    bstnode *root = NULL;
    int i, n, v;

    printf("How many data's do you want to insert ?\n");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Data %d: ", i+1);
        scanf("%d", &v);
        
        root = insert(root, v);
    }
    
    print_t(root);
    
    printf("Enter the data to be deleted");
    scanf("%d", &v);
    
    root = Delete(root, v);
    
    print_t(root);
    
    getch();
    return 0;
}


// Function to insert a value in the tree
bstnode* insert(bstnode* node, int value)
{
    if(node == NULL)
    {
        node = createNode(value);     // this function creates a new node and returns its address
    }
    else if(value < node->data)     // if the value is less than node data then it must be put in left subtree
    { 
        node->left = insert(node->left, value);
    }
    else     // else value will be put in the right subtree 
    {
        node->right = insert(node->right, value);
    }
    
    return node;
}


// Function to delete a value from tree
bstnode* Delete(bstnode *node, int value) 
{
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
			bstnode *temp = node;
			node = node->right;     // the right child is set at the place of the node to be deleted
			free(temp);
		}
		//Case 2: The node to be deleted has one child(left child)
		else if(node->right == NULL)
        {
			bstnode *temp = node;
			node = node->left;     // the left child is set at the place of the node to be deleted
			free(temp);
		}
		// case 3: The node to be deleted has 2 children
		else 
        { 
			bstnode *temp = FindMin(node->right);     //the minimum value in the node's right subtree is searched
			node->data = temp->data;     // node data is replaced by the minimum value
			
            node->right = Delete(node->right, temp->data);     // the node whose data was copied is deleted
		}
	}
	
    return node;
}


// function to create a node with a given value
bstnode* createNode(int value)
{
    bstnode *temp = (bstnode*) malloc(sizeof(bstnode));   // create a new node
    
    temp->data = value;
    temp->left = NULL;   
    temp->right = NULL;
    
    return temp;        
}

 
//Function to find the minimum value in a tree. 
bstnode* FindMin(bstnode* root)
{
	while(root->left != NULL) 
        root = root->left;
	
    return root;
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
