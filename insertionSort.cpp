#include<stdio.h>

int main(){
	int n,arr[1000],val,i,j;  
	printf("Enter the length of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter %d. element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++){  
        val=arr[i];  
        j=i-1;  
        while((j>=0)&&(arr[j]>val)){  
            arr[j+1]=arr[j];  
            j=j-1;  
        }  
        arr[j+1]=val;  
    }  
    for(i=0;i<n;i++){
    	printf("%d\t",arr[i]);
	}
	return 0;
}
