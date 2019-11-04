#include<stdio.h>
int factorielRec(int);
int main(){
	int n,result;
	printf("Faktoriyelinin alinmasini istediginiz sayiyi girin:");
	scanf("%d",&n);
	result=factorielRec(n);
	printf("%d'nin faktoriyeli:%d",n,result);
	return 0;
}
int factorielRec(int a){
	if(a==1||a==0) return 1;
	return a*factorielRec(a-1);
}
