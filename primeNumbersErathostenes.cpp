#include<stdio.h>

int main(){
	int n,arr[1000],i,j;
	printf("Enter the bound for prime numbers:");
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		arr[i]=1;		
	}
	for(i=2;i<n;i++){
		if(arr[i]==1){
			for(j=i;i*j<n;j++){
				arr[i*j]=0;
			}
		}
	}
	for(i=2;i<n;i++){
		if(arr[i]==1){
			printf("%d\t",i);
		}
	}
	return 0;
}
