#include<stdio.h>
#include<string.h>

int main(){
	char string[1000],substring[20];int n,m,i,j;
	printf("enter a string: ");
	gets(string);
	printf("enter a substring: ");
	gets(substring);
	n=strlen(string);
	m=strlen(substring);
	printf("%d %d\n",n,m);
	for(i=0;i<n-m+1;i++){
		j=0;
		while(j<m&&string[i+j]==substring[j]){
			j++;
		}
		if(j==m){
			printf("substring in the string and substring starts from %d. index of string \n",i+1);
		}
	}
	return 0;
}
