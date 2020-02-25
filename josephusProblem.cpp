#include<stdio.h>
#include<stdlib.h>
typedef struct node* link;
struct node{ int item; link next;};
int main(){
	int i,n=9,m=5;
	link t=(link)malloc(sizeof(link));// head of linkedlist
	link x=t;
	t->item=1;
	t->next=t;
	for(i=2;i<=n;i++){//adding elements to the list
		x=(x->next=(link)malloc(sizeof(link)));
		x->item=i;
		x->next=t;	
	}
	while(x!=x->next){//deleting elements from list until last element remains
		for(i=1;i<m;i++){
			x=x->next;
		}
		x->next=x->next->next;
		n--;
	}
	printf("%d",x->item);//the last number at the list
	return 0;
}
