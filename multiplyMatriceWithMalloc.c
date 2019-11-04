#include<stdio.h>

int **matrisleriCarp(int**,int,int,int**,int,int);

int main(){
	int m,n,k,l,i,j;
	int **mat1,**mat2,**mat3;
	printf("birinci matris satir ve sutun girin:");
	scanf("%d %d",&n,&m);
	printf("ikinci matris satir ve sutun girin:");
	scanf("%d %d",&k,&l);
	if(m!=k) return 0;
	mat1=(int**)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		mat1[i]=(int*)malloc(m*sizeof(int));
	}
	mat2=(int**)malloc(k*sizeof(int));
	for(i=0;i<k;i++){
		mat2[i]=(int*)malloc(l*sizeof(int));
	}
	printf("birinci matrisin elemanlarini girin:");	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("ikinci matrisin elemanlarini girin:");
	for(i=0;i<k;i++){
		for(j=0;j<l;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	mat3=matrisleriCarp(mat1,n,m,mat2,k,l);
	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			printf("%d ",mat3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int **matrisleriCarp(int **a,int n,int m,int **b,int k,int l){
	int **c;
	int i,j,z;
	c=(int**)calloc(n,sizeof(int));
	for(i=0;i<l;i++){
		c[i]=(int*)calloc(l,sizeof(int));
	}
	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			for(z=0;z<k;z++){
				c[i][j]=c[i][j]+a[i][z]*b[z][j];
			}
		}
	}
	return c;
}
