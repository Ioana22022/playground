#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;

}node;

void add_beg(int val, node **head){
	node *new_head = (node*)malloc(sizeof(node));
	new_head -> data = val;
	new_head -> next = *head;
	*head = new_head;	
}

void add_end(int val, node *head){
	node *current = head;
	node *new_node = (node*)malloc(sizeof(node));
	while(current->next != NULL) {
		current = current -> next;
	}
	new_node->data = val;
	current -> next = new_node;
	new_node -> next = NULL;
	
}

void del_beg(node **head) {
	node *temp = *head;
	(*head) = (*head)-> next;
	free(temp);

}

void remove_val(node *head, int val){
	if(head->data == val) {
		del_beg(&head);
		return;
	}
	node* current = head -> next;
	node* previous = current;
	while(current != NULL){
		if(current -> data == val){
			previous->next = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current -> next;
		
	}

}

void remove_end(node *head){
	node *current = head;
	if(head == NULL) return;
	if(head->next == NULL) { 
		del_beg(&head);
		return;
	}	
	while((current->next->next) != NULL) current = current -> next;
	//current -> next = NULL;
	free(current -> next);
	current -> next = NULL;

}

void printList(struct node *nd)
{
  while (nd != NULL)
  {
     printf(" %d ", nd->data);
     nd = nd->next;
  }
}

int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  add_beg(6, &head);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  add_beg(7, &head);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  add_beg(1, &head);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  add_end(4, head);
 
  printList(head);
  
  printf("\n");	
  //remove_val(head, 1);
  remove_end(head);	
  printList(head);
  printf("\n");
  return 0;
}

