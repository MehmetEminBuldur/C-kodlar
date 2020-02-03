#include<stdio.h>

int main(){
	int n,arr[1000],i,j,min,temp;
	printf("Enter the length of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter the %d.th element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;		
	}
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}

