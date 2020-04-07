#include<stdio.h>
#include<string.h>
int main(){
	char string[1000],substring[20];int n,m,i,j,k,bct['z'-'a'];//bct means bad character table
	printf("enter a string(without space):");
	gets(string);
	printf("enter a substring: ");
	gets(substring);
	n=strlen(string);
	m=strlen(substring);
	printf("%d %d\n",n,m);
	for(i=0;i<'z'-'a';i++){
		bct[i]=m-1;
	}
	for(i=0;i<m-1;i++){
		bct[substring[i]-'a']=m-j-1;
	}
	i=m-1;
	while(i<n){
		k=0;
		while(k<m&&substring[m-1-k]==string[i-k]){
			k++;	
		}
		if(k==m){
			printf("substring in the string and substring starts from %d. index of string \n",i-m+1);i++;
		}else{
			i=i+bct[string[i]-'a'];
		}
	}
	return 0;
}
