#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *left;
	struct node *right;
} *tree;

tree create_tree(char d){
	tree a;
	a=(tree)malloc(sizeof(tree));
	a->data=d;
	a->left=NULL;
	a->right=NULL;
	return a;	
}

tree insert(tree node,char data){//sorted
	if(node==NULL){ return create_tree(data);}
	if(data<node->data){
		node->left=insert(node->left,data);
	}else if(data>node->data){
		node->right=insert(node->right,data);
	}
	return node;
}

tree search(tree r,char key){
	if(r==NULL||r->data==key){return r;}
	if(key<r->data){return search(r->left,key);}
	return search(r->right,key);	
}
tree minValueNode(tree n){
	tree current=n;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}
tree del(tree r,char data){
	if(r==NULL){return r;}
	if(data<r->data){r->left=del(r->left,data);}
	else if(data>r->data){r->right=del(r->right,data);}
	else{
		if(r->left==NULL){
			tree tmp=r->right;
			free(r);return tmp;
		}else if(r->right==NULL){
			tree tmp=r->left;
			free(r);return tmp;
		}
		tree tmp=minValueNode(r->right);
		r->data=tmp->data;
		r->right=del(r->right,tmp->data);
	}
	return r;
}

void visit(tree t){
	printf("%c",t->data);
}

void pre_traverse(tree t){
	if(t==NULL){return;}
	visit(t);
	pre_traverse(t->left);
	pre_traverse(t->right);
}

void in_traverse(tree t){
	if(t==NULL){return;}
	in_traverse(t->left);
	visit(t);
	in_traverse(t->right);
}

void post_traverse(tree t){
	if(t==NULL){return;}
	post_traverse(t->left);
	post_traverse(t->right);
	visit(t);
}
int main(){
	tree test;
	test=NULL;char i;
	test=create_tree('E');
	for(i='A';i<='H';i++){
			insert(test,i);
	}
	printf("PRE TRAVERSE=");
	pre_traverse(test);
	printf("\t");
	printf("IN TRAVERSE=");
	in_traverse(test);
	printf("\t");
	printf("POST TRAVERSE=");
	post_traverse(test);
	return 0;
}
