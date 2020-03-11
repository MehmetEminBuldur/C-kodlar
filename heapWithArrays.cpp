#include<stdio.h>

void max_heapify(int i,int n,int *a){//using heap rule
	int l=2*i,r=2*i+1,largest,tmp;
	if(l<n&&a[l]>a[i]){
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
	for(i=n;i>0;i--){
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
int main(){
	int a[7];
	a[1]=23;a[2]=3;a[3]=45;a[4]=0;a[5]=1;a[6]=9;
	printf("First array:");
	print_array(6,a);
	create_heap(6,a);
	printf("Heapified array:");
	print_array(6,a);
	heap_sort(6,a);
	printf("Sorted array:");
	print_array(6,a);
	return 0;
}
