#include<stdio.h>
void quickSort(int *a,int l,int r){
	int s;
	if(l<r){
		s=hoaraPartition(a,l,r);
		quickSort(a,l,s-1);
		quickSort(a,s+1,r);
	}
	return;
}

int hoaraPartition(int *a,int l,int r){
	int p=a[l],i=l,j=r+1,temp;
	do{
		do{
			i++;
		}while(a[i]<p);
		do{
			j--;
		}while(a[j]>p);
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}while(i<=j);
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}

int main(){
	int a[]={12,3,123,4,55,45,47,48,1232,7,56,675,43,12,123542,0,12,2,3,212,123,123123,1};
	int right=(sizeof(a)/sizeof(int))-1;
	int left=0,i;
	quickSort(a,left,right);
	for(i=0;i<=right;i++){
		printf(" %d ",a[i]);
	}
	return 0;
}
