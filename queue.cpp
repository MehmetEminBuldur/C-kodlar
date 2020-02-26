#include<stdio.h>
#include<stdlib.h>
#define FULL 10
struct node{int data; struct node *next;};
typedef struct node node;
struct queue{int cnt; node *front; node*rear;};
typedef struct queue queue;
void init(queue *q){
	q->cnt=0;
	q->front=NULL;
	q->rear=NULL;
}
void enqueue(queue *q,int val){
	if(q->cnt<FULL){
		node *tmp;
		tmp=(node*)malloc(sizeof(node));
		tmp->data=val;
		tmp->next;
		if(q->rear!=q->front){
			q->rear->next=tmp;
			q->rear=tmp;
		}else{
			q->front=q->rear;
			q->rear=tmp;
		}
		q->cnt++;
	}else{
		printf("queue is full");
	}
}
int dequeue(queue *q){
	node *tmp;
	int val=q->front->data;
	tmp=q->front;
	q->front=q->front->next;
	q->cnt--;
	free(tmp);
	return val;
}
int main(){
	queue *q;int i;
	q=(queue*)malloc(sizeof(queue));
	init(q);
	for(i=0;i<11;i++){
		enqueue(q,i*10);
	}
	return 0;
}
