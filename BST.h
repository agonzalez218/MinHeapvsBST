#ifndef BST_H
#define BST_H
 
typedef struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
} BST;

BST *createBST( int );
BST *createNode( int value );
BST *insertBST( BST *node, int key );
int getMinValueBST( BST* );
int minFromBST( int, int * );
void freeBST(BST *root );
 
#endif