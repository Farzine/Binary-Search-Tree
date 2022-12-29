#include<stdio.h>
#include<malloc.h>


struct node{
         int data;
         struct node*left;
         struct node*right;
};

struct node* createnode(int data)
{
    struct node* n;    // creating a node pointer
    n = (struct node*) malloc (sizeof(struct node)); // allocating memory in the heap
    n->data = data;  // Setting the data
    n-> left = NULL; // setting left and right children to the node
    n-> right = NULL;
    return n; // returning the created node
}


void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

}


struct node* inOrderPredecessor(struct node* root)
{
    root=root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int value)
{
    struct node* iPre;
    if(root==NULL)
        return NULL;
    if(root->left == NULL&& root->right == NULL){
        free(root);
        return NULL;
    }
   // search for the node to be deleted
   if(value < root ->data)
        root->left = deleteNode(root->left, value);
   else if(value>root->data)
         root->right = deleteNode(root->right, value);
   // Deletion strategy when the node is found
   else{
    iPre = inOrderPredecessor(root);
    root->data = iPre->data;
    root->left = deleteNode(root->left, iPre->data);
   }
   return root;
}


int main()
{
    /*
    // constructing the root node
    struct node* p;
    p = (struct node*) malloc (sizeof(struct node));
    p->data = 2;
    p-> left = NULL;
    p-> right = NULL;

    // constructing the second node
    struct node* p1;
    p1 = (struct node*) malloc (sizeof(struct node));
    p1->data = 1;
    p1-> left = NULL;
    p1-> right = NULL;

    //constructing the third node
    struct node* p2;
    p2 = (struct node*) malloc (sizeof(struct node));
    p2->data = 4;
    p2-> left = NULL;
    p2-> right = NULL;
    */

    // constructing the root node Using function
    struct node* p = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);

    // Finally the tree looks like this:
    //            5
    //           /  \
    //         3    6
    //        /  \
    //      1    4

    //linking the root node with left and right children
    p-> left = p1;
    p-> right = p2;
    p1-> left = p3;
    p1-> right = p4;

    inOrder(p);
    printf("\n");
    deleteNode(p,5);

    inOrder(p);

    return 0;
}

