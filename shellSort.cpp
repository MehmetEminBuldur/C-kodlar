#include<stdio.h>

int main(){
	int n,arr[1000],x,i,mid,temp,j;
	printf("Enter the length of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the %d. element of array:",i+1);
		scanf("%d",&arr[i]);
	}
	for(mid=n/2;mid>0;mid=mid/2){ 
        for(i=mid;i<n;i++){ 
    		temp=arr[i];        
            j=i;
			while(j>=mid&&arr[j-mid]>temp){
                arr[j]=arr[j-mid]; 
                j=j-mid;
        	}
            arr[j]=temp; 
        } 
    }
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
	return 0;
}
