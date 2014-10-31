/*
Author: Dipankar Dey
The Great Tree-List Recursion Problem.
*/
#include <stdio.h>
#include <malloc.h>

#define NOMEM(a) do {if ((a) == NULL) exit(-1);} while (0);
#define NEXT(n) (n)->right
#define PREV(n) (n)->left

typedef struct _Node* Tree;
typedef struct _Node* Node;
struct _Node {
	int data;
	Tree left;
	Tree right;
};

static void _add_recur(Tree *root, int data) {
	if (*root == NULL) {
		*root = (Tree) malloc(sizeof(struct _Node));
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

static void _tree_to_list(Tree root, Node *head, Node *last) {
	if (root != NULL) {
		_tree_to_list(root->left, head, last);
		if (*head == NULL) {
			*last = *head = root;
		} else {
			NEXT(*last) = root;
			PREV(root) = *last;
			*last = root;
		}
		_tree_to_list(root->right, head, last);
	}
}

static void tree_to_list(Tree root, Node *head, Node *last) {
	if ((root != NULL) && (head != NULL) && (last != NULL)) {
		_tree_to_list(root, head, last);
		if ((*head != NULL) && (*last != NULL)) {
			NEXT(*last) = *head;
			PREV(*head) = *last;
		}
	}
}

static void printListForward(Node head, Node last) {
	if ((head != NULL) && (last != NULL)) {
		while (head != last) {
			printf ("%5d", head->data);
			head = NEXT(head);
		}
		if (head == last) {
			printf ("%5d", head->data);
		}
		printf ("\n");
	}
}

static void printListBackward(Node head, Node last) {
	if ((head != NULL) && (last != NULL)) {
		while (last != head) {
			printf ("%5d", last->data);
			last = PREV(last);
		}
		if (head == last) {
			printf ("%5d", last->data);
		}
		printf ("\n");
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
	Node head = NULL;
	Node last = NULL;
	int arr1[] = {10, 5, 15, 3, 6, 1, 4, 9, 7, 11, 20};
	
	create_tree(&r1, arr1, sizeof(arr1)/sizeof(int));
	tree_to_list(r1, &head, &last);
	
	printListForward(head, last);
	printListBackward(head, last);
	
	return 0;
}
