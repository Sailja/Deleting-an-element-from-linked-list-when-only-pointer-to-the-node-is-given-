//given only pointer to a node to be deleted
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void deleteNode(struct node *x)
{
	struct node *temp=x->next;
	
	x->next=temp->next;
	x->data=temp->data;
	free(temp);
}
void printList(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
void push(struct node **head_ref, int new_data)
{
	struct node * new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
int main()
{
	struct node *head=NULL;
	push(&head,8);
	push(&head,9);
	push(&head,10);
	printList(head);
	deleteNode(head);
	printf("\n");
	printList(head);
}
