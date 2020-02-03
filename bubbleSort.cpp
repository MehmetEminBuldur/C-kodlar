#include<stdio.h>

int main(){
	int n,arr[1000],i,j,temp;
	printf("Enter the length of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the %d. element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
