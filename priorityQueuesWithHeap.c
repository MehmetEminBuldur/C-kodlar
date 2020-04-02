#include<stdio.h>

void max_heapify(int i,int n,int *a){//using heap rule
	int l=2*i,r=2*i+1,largest,tmp;
	if(l<=n&&a[l]>a[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<=n&&a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		tmp=a[i];
		a[i]=a[largest];
		a[largest]=tmp;
		max_heapify(largest,n,a);
	}
}

void create_heap(int n,int *a){
	int i;
	for(i=n/2;i>0;i--){
		max_heapify(i,n,a);
	}
}

void heap_sort(int n,int *a){
	int i,tmp;
	create_heap(n,a);
	for(i=n;i>1;i--){
		tmp=a[1];
		a[1]=a[i];
		a[i]=tmp;
		max_heapify(1,i-1,a);
	}
}

void print_array(int n,int *a){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void print_tree(int n,int *a){
	int i=1,st=1,j;
	while(i<=n){
		j=1;
		while(j<=st&&i<=n){
			printf(" %d ",a[i]);
			j++;
			i++;
		}
		printf("\n");
		st=st*2;
	}
}
int max(int *a){
	return a[1];
}
int heap_extract_max(int *n,int *a){
	int max=a[1];
	a[1]=a[*n];
	(*n)--;
	max_heapify(1,*n,a);
	return max;
}
void heap_increase_key(int n,int i,int *a,int key){
	int temp;
	if(key<a[i]){
		printf("key is smaller than current value");return;
	}
	a[i]=key;
	while(i>1&&a[i/2]<a[i]){
		temp=a[i/2];
		a[i/2]=a[i];
		a[i]=temp;
		i=i/2;
	}
}
void max_heap_insert(int *n,int *a,int key){
	(*n)++;
	a[*n]=-999999999;
	heap_increase_key(*n,*n,a,key);
}
int main(){
	int a[7];
	a[1]=23;a[2]=3;a[3]=45;a[4]=0;a[5]=1;a[6]=9;
	int n=6;
	printf("First array:");
	print_array(n,a);
	create_heap(n,a);
	printf("Heapified array:");
	print_array(n,a);
	heap_sort(n,a);
	printf("Sorted array:");
	print_array(n,a);
	printf("\n");
	print_tree(n,a);
	create_heap(n,a);
	print_tree(n,a);
	int *b;b=&n;
	int max=heap_extract_max(b,a);printf("%d",max);
	printf("\n");
	n=*b;
	print_tree(n,a);	
	heap_increase_key(n,3,a,25);
	print_tree(n,a);
	max_heap_insert(&n,a,30);
	print_tree(n,a);	
	return 0;
}
