#include<stdio.h>

int max=8;
int stack[8];
int top=-1;//points index of element which is the last element in stack

int peek(){//returns the element which points by top
	return stack[top];
} 

int pop(){//takes the last entered element from stack and decreases pointer(top)
	int data;
	if(top!=-1){
		data=stack[top];
		top=top-1;
	}else{
		printf("stack is empty!\n");
	}
	return data;
}

void push(int data){//puts data to next available place in stack and increases the pointer(top)
	if(top!=max){
		top++;
		stack[top]=data;
	}else{
		printf("stack is full!\n");
	}
}

int main(){
	pop();
	push(5);
	int a=pop();
	printf("%d\n",a);
	pop();
	push(8);
	push(-3);
	push(0);
	push(13);
	printf("%d\n",pop());
	printf("%d\n",peek());
	return 0;
}
