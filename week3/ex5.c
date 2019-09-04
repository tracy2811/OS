// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
	struct node *prev;
};

void print_list(struct node *head) {
	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void insert_node(struct node **head, int val) {
	// Insert to head;
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = *head;
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

void delete_node(struct node **head, int val) {
	// Delete the fisrt occurence of val in list
	struct node *prev;
	prev = *head;

	if ((*head) == NULL)
		return;
	if ((*head)->value == val) {
		*head = (*head)->next;
		free(prev);
		return;
	}

	while (prev->next != NULL && prev->next->value != val) {
		prev = prev->next;
	}
	if (prev->next != NULL) {
		struct node *del = prev->next;
		prev->next = del->next;
		free(del);
	}
}

// Test implemented singly linked list
int main() {
	struct node *head = NULL;
	insert_node(&head, 1);
	insert_node(&head, 3);
	insert_node(&head, 5);
	insert_node(&head, 5);
	delete_node(&head, 3);
	delete_node(&head, 5);
	delete_node(&head, 0);
	print_list(head);
	return 0;
}
