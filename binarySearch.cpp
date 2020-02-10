#include<stdio.h>

int main(){
	int n,arr[1000],x,i,low,mid,high;
	printf("Enter the length of array:");
	scanf("%d",&n);
	printf("Array should be sorted!!!\n");
	for(i=0;i<n;i++){
		printf("Enter the %d. element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter a number for search:");
	scanf("%d",&x);
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high&&arr[mid]!=x){
		if(arr[mid]<x){
			low=mid+1;
		}else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	if(arr[mid]!=x){
		printf("Element there is not in the array.");		
	}else{
		printf("%d. element of array is searched element: %d",mid+1,x);
	}
	return 0;
}
