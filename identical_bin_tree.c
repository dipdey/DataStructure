/*
Author: Dipankar Dey
Find given two bin tree is identical or not
*/
#include <stdio.h>
#include <malloc.h>

#define NOMEM(a) do {if ((a) == NULL) exit(-1);} while (0);

typedef struct Node* Tree;
struct Node {
	int data;
	Tree left;
	Tree right;
};

static void _add_recur(Tree *root, int data) {
	if (*root == NULL) {
		*root = (Tree) malloc(sizeof(struct Node));
		NOMEM(*root);
		(*root)->data = data;
		(*root)->left = (*root)->right = NULL;
	} else {
		if (data < (*root)->data) {
			_add_recur(&((*root)->left), data);
		} else {
			_add_recur(&((*root)->right), data);
		}
	}
}

static void add_recur(Tree *root, int data) {
	if (root != NULL) {
		_add_recur(root, data);
	}
}

static int check_identical(Tree r1, Tree r2) {
	if ((NULL == r1) && (NULL == r2)) {
		return 1; // Identical
	} else if ((NULL != r1) && (NULL != r2)) {
		int i = 0;
		if (r1->data == r2->data) {
			i = check_identical(r1->left, r2->left);
			if (i) {
				i = check_identical(r1->right, r2->right);
			}
		}
		return i;
	} else {
		return 0;
	}
}

static void create_tree(Tree *root, int *arr, int size) {
	int i = 0;
	for (i = 0; i<size; i++) {
		add_recur(root, arr[i]);
	}
}

int main(int argc, char **argv) {
	Tree r1 = NULL;
	Tree r2 = NULL;
	int arr1[] = {10, 5, 15, 3, 6, 1, 4, 9, 7, 11, 20};
	int arr2[] = {10, 5, 15, 3, 6, 1, 4, 9, 8, 11, 20};
	
	create_tree(&r1, arr1, sizeof(arr1)/sizeof(int));
	create_tree(&r2, arr2, sizeof(arr2)/sizeof(int));
	
	printf ("Are these tree identical? %s\n", (check_identical(r1, r2)? "Yes" : "No"));
	return 0;
}
