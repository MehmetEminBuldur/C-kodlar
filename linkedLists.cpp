#include<stdio.h>
#include<stdlib.h>

typedef struct link{
	int item;
	struct link *next;
} node;
node *insert_top(int num,node *head){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->item=num;
	newnode->next=head;
	head=newnode;
	return head;
}
node *insert_after(int num,node *head,int prevnum){
	node *curr=head;
	node *newnode=(node*)malloc(sizeof(node));
	while(curr->item!=prevnum){
		curr=curr->next;
	}
	newnode->item=num;
	newnode->next=curr->next;
	curr->next=newnode;
	return head;
}
node *delete_value(int num,node *head){
	node *curr=(node*)malloc(sizeof(node));
	node *prev=(node*)malloc(sizeof(node));
	curr=head;
	while(curr!=NULL){
		if(curr->item==num){
			if(curr==head){
				head=curr->next;
				return head;
			}else{
				prev->next=curr->next;
				return head;
			}
		}
		prev=curr;
		curr=curr->next;
	}
	return head;
}

int main(){
	node *head;
	int i;
	head=insert_top(1,head);
	for(i=2;i<10;i++){
		insert_after(i,head,i-1);
	}
	head=delete_value(6,head);
	node *p;
	for(p=head;p!=NULL;p=p->next){
		printf(" %d ",p->item);
 	}
	return 0;
}
