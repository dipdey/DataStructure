/*
Author: Dipankar Dey
Remove duplicate from a sorted single linked list
*/

#include <stdio.h>
#include <malloc.h>

typedef struct Node* List;

struct Node {
	int data;
	List next;
};

static void add(List *head, List *last, int data) {
	List node = (List)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	
	if (*head == NULL) {
		*head = node;
		if (last != NULL) {
			*last = node;
		}
	} else if (last != NULL) {
		(*last)->next = node;
		*last = node;
	} else {
		node->next = *head;
		*head = node;
	}
}

static void print(List head) {
	printf ("List is:: \n");
	while (head != NULL) {
		printf ("%5d", head->data);
		head = head->next;
	}
	printf("\n");
}

static void removeDuplicate(List *head) {
	List p1 = *head;
	List p2 = *head;
	List tmp;
	
	if ((head == NULL) || (*head == NULL) || ((*head)->next == NULL)) return;
	while (p1 != NULL) {
		while ((p2->next != NULL) && (p1->data == p2->next->data)) p2 = p2->next;
		if ((p1 != p2) && (p2 != NULL)) {
			if (*head == p1) {
				tmp = p1;
				*head = p1 = p2;
			} else {
				tmp = p1->next;
				p1->next = p2->next;
				p2 = p1;
			}
		} else {
			p2 = p1 = p1->next;
		}
	}
}

int main(int argc, char**argv) {
	int arr[] = {2,2,2,2,9,9,8,7,6,6,6,5};
	int i=0;
	List head = NULL;
	List last = NULL;
	
	for (i =0; i<sizeof(arr)/sizeof(int); i++) {
		add(&head, &last, arr[i]);
	}
	
	print(head);
	
	removeDuplicate(&head);
	print(head);
	
	return 0;
}
