#include<stdio.h>
#define MAX 5
int q[MAX],front=0,rear=-1,cnt=0;
int peek(){
	return q[front];
}
int isEmpty(){
	return cnt==0;
}
int isFull(){
	return cnt==MAX;
}
void enqueue(int data){
	if(!isFull()){
		if(rear==MAX-1){
			rear=-1;
		}
		q[++rear]=data;
		cnt++;
	}else{
		printf("\nqueue is full");
	}
}
int dequeue(){//remove first in element from queue
	int data=q[front];
	if(cnt!=0){
		if(front==MAX){
			front=0;
		}
		front++;
		cnt--;
	}else{
		printf("\nqueue is empty");
	}
	return data;
}
int main(){
	int i;
	enqueue(5);
	enqueue(6);
	enqueue(-1);
	enqueue(129);
	enqueue(23);
	enqueue(1);
	for(i=i;i<MAX;i++){
		printf("\n%d",q[i]);
	}
	for(i=0;i<MAX+1;i++){
		printf("\n%d",dequeue());
	}
	return 0;
}
