#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}tnode, btnode;


struct node* root;

struct node* insert(btnode* r, int data);

int main()
{
    root = NULL;
    int n, v,i;

    printf("How many data's do you want to insert ?\n");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Data %d: ", i+1);
        scanf("%d", &v);
        root = insert(root, v);
    }
    printf("hello\n");
    
    print_t(root);
    
    getch();
    return 0;
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL) // BST is not created created
    {
        r = (struct node*) malloc(sizeof(struct node)); // create a new node
        r->data = data;  // insert data to new node
        // make left and right childs empty
        r->left = NULL;   
        r->right = NULL;
    }
    // if the data is less than node value then we must put this in left sub-tree
    else if(data < r->data){ 
        r->left = insert(r->left, data);
    }
    // else this will be in the right subtree
    else {
        r->right = insert(r->right, data);
    }
    return r;

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
