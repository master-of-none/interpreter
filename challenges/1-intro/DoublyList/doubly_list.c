#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *prev;
  	struct Node *next;
};

typedef struct Node Node;

void displayList(Node *node) {
    Node *cur = node;
    if (node == NULL) {
		printf("Empty List\n");
		return;
}

    while (cur != NULL) {
		printf("%c -> ", cur->data);
		cur = cur->next;
    }
    printf("\n");
}

void insertFront(Node **head, char c) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = c;
	newNode->next = *head;
	newNode -> prev = NULL;

	if(*head != NULL) {
		(*head) -> prev = newNode;
	}

	*head = newNode;
}

void insertEnd(Node **head, char c) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode -> data = c;
	newNode -> next = NULL;

	Node *temp = *head;

	if (*head == NULL){
		newNode -> prev = NULL;
		*head = newNode;
		return;
	}

	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;

}

void deleteFront(Node **head){
	if(*head == NULL){
		printf("Empty List\n");
		return;
	}
	Node *temp = *head;
	*head = temp->next;
	
	if(*head != NULL){
		(*head)->prev = NULL;
	}
	free(temp);
}

void deleteEnd(Node **head){
	if (*head == NULL){
		printf("Empty List\n");
		return;
	}

	Node *temp = *head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	if(temp->prev == NULL){
		*head = NULL;
	}
	else{
		temp->prev->next = NULL;
	}
	free(temp);
}

int main() {
	Node *head = NULL;
	insertFront(&head, 'a');
	insertFront(&head, 'b');
	insertFront(&head, 'c');
	insertEnd(&head, 'd');
	deleteFront(&head);
	deleteEnd(&head);
	displayList(head);
	return 0;
}
