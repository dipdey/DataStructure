/*Author: Dipankar Dey
Reverse a Linked List in groups of given size
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

static List _reverse_in_group(List *head, int k) {
	List p1 = NULL;
	List p2 = NULL;
	List p3 = NULL;
	List tmp;
	
	if (*head == NULL) return NULL;
	//else if ((*head)->next == NULL) return *head;
	else {
		int ik = k;
		tmp = *head;
		while (ik--) {
			if (tmp != NULL) tmp = tmp->next;
			else break;
		}
		//if (tmp != NULL) printf("* %d\n", tmp->data);
		//else printf("* tmp NULL\n");
		p3 = _reverse_in_group(&tmp, k);
		//if (p3 == NULL)printf ("p3 NULL\n");
		p1 = *head;
		//printf ("p1 %d\n", p1->data);
		while (p1 != NULL && k--) {
			p2 = p1;
			p1 = p1->next;
			p2->next = p3;
			p3 = p2;
		}
		//printf ("%d\n", p2->data);
		*head = p2;
		return *head;
	}
}

static void reverse_in_group(List *head, int k) {
	if (head != NULL && k > 0) {
		if (k > 1) { // Atleast 2 elements group is required
			*head = _reverse_in_group(head, k);
		} else {
		// Do regular reverse linked list
		}
	}
}

int main(int argc, char**argv) {
//	int arr[] = {2,2,2,2,9,9,8,7,6,6,6,5};
	int arr[] = {1,2,3,4,5,6,7,8};//,9, 23,45};
	int i=0;
	List head = NULL;
	List last = NULL;
	
	for (i =0; i<sizeof(arr)/sizeof(int); i++) {
		add(&head, &last, arr[i]);
	}
	
	print(head);
	reverse_in_group(&head, 3);
	print(head);
	
	return 0;
}
