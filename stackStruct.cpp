#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *ptr;
} *top,*top1,*temp;
int cnt=0;
void create(){
	top=NULL;
}
int numOfElements(){//is empty or full(if there is a limit)
	return cnt;
}
void push(int data){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	if(top==NULL){
		temp->ptr=NULL;//stack is empty.There is no old top so temp points null
	}else{
		temp->ptr=top;//temp will be new top so temp points old top
	}
	top=temp;//new top is temp
	cnt++;//number of elements in stack counter
}

int pop(){
	int val;
	top1=top;
	if(top1==NULL){
		printf("stack is empty!");
		exit(0);
	}else{
		val=top1->info;
		top1=top1->ptr;
		free(top);
		top=top1;
		cnt--;
		return val;
	}
}
int main(){
	create();
	push(5);
	push(8);
	int b=pop();
	printf("%d %d\n",b,pop());
	printf("%d\n",numOfElements());
	printf("%d",pop());
	return 0;
}
