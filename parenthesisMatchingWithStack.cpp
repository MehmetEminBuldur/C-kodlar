#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int info;
	char a;
	struct node *ptr;
} *top,*top1,*temp;
int cnt=0;
void create(){
	top=NULL;
}
int numOfElements(){//is empty or full(if there is a limit)
	return cnt;
}
struct node *peek(){
	return top;
}
void push(int data,char b){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->a=b;
	if(top==NULL){
		temp->ptr=NULL;//stack is empty.There is no old top so temp points null
	}else{
		temp->ptr=top;//temp will be new top so temp points old top
	}
	top=temp;//new top is temp
	cnt++;//number of elements in stack counter
}

char pop(){
	int val;
	char c;
	top1=top;
	if(top1==NULL){
		printf("stack is empty!");
		exit(0);
	}else{
		val=top1->info;
		c=top1->a;
		top1=top1->ptr;
		free(top);
		top=top1;
		cnt--;
		return c;
	}
}

int isMatched(char e,char f){//check for parenthesis is match
	if(e=='['&&f==']'){
		return 1;
	}else if(e=='('&&f==')'){
		return 1;
	}else if(e=='{'&&f=='}'){
		return 1;
	}else{
		return 0;
	}
} 
int main(){
	create();int i;
	char arr[100];
	gets(arr);
	for(i=0;i<strlen(arr);i++){
		if(arr[i]=='{'||arr[i]=='('||arr[i]=='['){
			push(i,arr[i]);
		}else if(arr[i]=='}'||arr[i]==')'||arr[i]==']'){
			if(numOfElements()==0||isMatched(peek()->a,arr[i])==0){
				printf("parenthesis are wrong!");
				return 0;
			}else{
				pop();
			}
		}
	}
	if(numOfElements()==0){
		printf("parenthesis are true :D");
	}else{
		printf("parenthesis are wrong!!");
	}
	return 0;
}
