/*
Author: Dipankar Dey
Find size of Bin tree
*/
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}

/* Computes the number of nodes in a tree. */
void size(struct node* node, int *sz) 
{
  if (node != NULL) {
	++*sz;
	size(node->left, sz);
	size(node->right, sz);
  }
}

/* Driver program to test size function*/    
int main()
{
  int sz = 0;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left  = newNode(6);
  root->right->right = newNode(7);   

  size(root, &sz);
  printf("Size of the tree is %d", sz);  
  getchar();
  return 0;
}