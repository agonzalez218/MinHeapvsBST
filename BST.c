#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

BST *createBST( int num ) // create BST and return root node
{
	BST *root = (BST*)malloc(sizeof(BST));
  root->data = num;
	root->left = NULL;
  root->right = NULL;
	return root;
}
 
BST *insertBST( BST *node, int key) // insert key into BST
{ 
  if (node == NULL)
  {
    return createNode(key); 
  }
  if (key < node->data) 
  {
    node->left  = insertBST(node->left, key);
  } 
  else if (key > node->data) 
  {
    node->right = insertBST(node->right, key);    
  }
  return node; 
} 

int getMinValueBST(BST *temp) // go to left most node and return value
{
	while(temp->left!=NULL)
	{
		temp = temp->left;
	}
  return temp->data;
}

int minFromBST( int size, int *data )
{
  int i, min;
  BST *BSTRoot = createBST( data[ 0 ] ), *temp;
  temp = BSTRoot;
  for(i = 1; i < size; i++)
  {
    temp = insertBST(temp, data[i]);
  }
  min = getMinValueBST(BSTRoot); 
  freeBST(BSTRoot);
  return min;
}

BST *createNode( int value )
{
  BST *tempBST = (BST*)malloc(sizeof(BST));
  tempBST->data = value;
  tempBST->left = NULL;
  tempBST->right = NULL;
  return tempBST;
}

void freeBST( BST* root)  
{ 
  if (root == NULL)
  {
    return; 
  }
  freeBST(root->left); 
  freeBST(root->right); 
  free(root); 
}  