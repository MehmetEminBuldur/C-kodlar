#include <stdio.h>

int main(){
	int n,arr[1000],x,i;
	printf("Enter the length of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the %d.element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element for searching:");
	scanf("%d",&x);
	i=0;
	while(i<n&&arr[i]!=x){
		i++;
	}
	if(i<n){
		printf("%d. element of array is searched element:%d",i+1,x);
	}else{
		printf("Searched element there is not in array.");
	}
	return 0; 
}
