#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	char a;
	int m[4][4],i,j,b,k,l,n,temp;
	int c=0;
	int control=0;
	for(i=0;i<4;i++){//ba�lang�� matrisi 0'a e�itleme
		for(j=0;j<4;j++){
			m[i][j]=0;
		}
	}
	k=rand()%4;
	l=rand()%4;
	m[k][l]=(rand()%2+1)*2;
	while((c<9)&&(c!=-1)){
		for(i=0;i<4;i++){
			printf("\n");
			for(j=0;j<4;j++){
				if(m[i][j]==0){
					printf("|		 |");
				}else if((i==k)&&(j==l)){
					printf("|	*%d	 |",m[i][j]);
				}else {
					printf("|	%d	 |",m[i][j]);
				}
			}
		}
		printf("\n CIKIS:e      RESTART:x");
		printf("\n YON GIRINIZ(sag=d sol=a yukari=w asagi=s):");
		scanf("%s",&a);
		if(a=='d'){//sa�a
			for(i=0;i<4;i++){//toplama i�lemi
				for(j=3;j>0;j--){
					if(m[i][j]==m[i][j-1]){
						m[i][j]=m[i][j]*2;
						m[i][j-1]=0;
					}
				}
			}
			for(i=0;i<4;i++){//toplama i�lemi
				if((m[i][0]!=m[i][1])&&(m[i][1]==0)&&(m[i][0]==m[i][2])){
						m[i][2]=m[i][2]*2;
						m[i][0]=0;
				}else if((m[i][0]!=m[i][1])&&(m[i][1]==m[i][2])&&(m[i][2]==0)&&(m[i][3]==m[i][0])){
						m[i][3]=m[i][3]*2;
						m[i][0]=0;
				}else if((m[i][1]!=m[i][2])&&(m[i][1]==m[i][3])&&(m[i][2]==0)){
						m[i][3]=m[i][3]*2;
						m[i][1]=0;
				}
			}
			for(i=0;i<4;i++){//kayd�rma i�lemi
				for(j=3;j>0;j--){
					n=3;
					while(n>0){
						if(m[i][n]==0){
							temp=m[i][n];
							m[i][n]=m[i][n-1];
							m[i][n-1]=temp;
						}
						n--;
					}
				}
			}
			c=0;
			for(i=0;i<3;i++){//kay�p kontrol�
				for(j=0;j<3;j++){
					if((m[i][j]!=m[i][j+1])&&(m[i][j]!=m[i+1][j])&&(m[i][j]!=0)&&(m[i][j+1]!=0)&&(m[i+1][j]!=0)){
						c++;
					}
				}
			}
			for(i=0;i<4;i++){//kazanma kontrol�
				for(j=0;j<4;j++){
					if(m[i][j]==2048){
						c=-1;
					}
				}
			}
			do{ /*random say� atama */
			k=rand()%4;
			l=rand()%4;
			}while((m[k][l]!=0)&&(c<9));
			if(c<9){
				m[k][l]=(rand()%2+1)*2;
			}
			if(c==9){
				printf("Oyun Bitti Kaybettiniz :(");
			}else if(c== -1){
				printf("Oyunu Kazand�n�z.");
			}
		}else if(a=='a'){//sola
			for(i=0;i<4;i++){//toplama i�lemi
				for(j=0;j<3;j++){
					if(m[i][j]==m[i][j+1]){
						m[i][j]=m[i][j]*2;
						m[i][j+1]=0;
					}
				}
			}
			for(i=0;i<4;i++){//toplama i�lemi
				if((m[i][0]!=m[i][1])&&(m[i][1]==0)&&(m[i][0]==m[i][2])){
						m[i][0]=m[i][0]*2;
						m[i][2]=0;
				}else if((m[i][0]!=m[i][1])&&(m[i][1]==m[i][2])&&(m[i][2]==0)&&(m[i][3]==m[i][0])){
						m[i][0]=m[i][0]*2;
						m[i][3]=0;
				}else if((m[i][1]!=m[i][2])&&(m[i][1]==m[i][3])&&(m[i][2]==0)){
						m[i][1]=m[i][1]*2;
						m[i][3]=0;
				}
			}
			for(i=0;i<4;i++){//kayd�rma i�lemi
				for(j=0;j<3;j++){
					n=0;
					while(n<3){
						if(m[i][n]==0){
							temp=m[i][n];
							m[i][n]=m[i][n+1];
							m[i][n+1]=temp;
						}
						n++;
					}
				}
			}
			c=0;
			for(i=0;i<3;i++){//kay�p kontrol�
				for(j=0;j<3;j++){
					if((m[i][j]!=m[i][j+1])&&(m[i][j]!=m[i+1][j])&&(m[i][j]!=0)&&(m[i][j+1]!=0)&&(m[i+1][j]!=0)){
						c++;
					}
				}
			}
			for(i=0;i<4;i++){//kazanma kontrol�
				for(j=0;j<4;j++){
					if(m[i][j]==2048){
						c= -1;
					}
				}
			}
			do{//say� atama
			k=rand()%4;
			l=rand()%4;
			}while((m[k][l]!=0)&&(c<9));
			if(c<9){
				m[k][l]=(rand()%2+1)*2;
			}
			if(c==9){
				printf("Oyun Bitti Kaybettiniz :(");
			}else if(c== -1){
				printf("Oyunu Kazand�n�z.");
			}		
		}else if(a=='w'){//yukar�
			for(i=0;i<3;i++){//toplama i�lemi
				for(j=0;j<4;j++){
					if(m[i][j]==m[i+1][j]){
						m[i][j]=m[i][j]*2;
						m[i+1][j]=0;
					}
				}
			}
			for(j=0;j<4;j++){//toplama i�lemi
				if((m[0][j]!=m[1][j])&&(m[1][j]==0)&&(m[0][j]==m[2][j])){
						m[0][j]=m[0][j]*2;
						m[2][j]=0;
				}else if((m[0][j]!=m[1][j])&&(m[1][j]==m[2][j])&&(m[2][j]==0)&&(m[3][j]==m[0][j])){
						m[0][j]=m[0][j]*2;
						m[3][j]=0;
				}else if((m[1][j]!=m[2][j])&&(m[1][j]==m[3][j])&&(m[2][j]==0)){
						m[1][j]=m[1][j]*2;
						m[3][j]=0;
				}
			}
			for(i=0;i<3;i++){//kayd�rma i�lemi
				for(j=0;j<4;j++){
					n=0;
					while(n<3){
						if(m[n][j]==0){
							temp=m[n][j];
							m[n][j]=m[n+1][j];
							m[n+1][j]=temp;
						}
						n++;
					}
				}
			}
			c=0;
			for(i=0;i<3;i++){//kaybetme kontrol� 
				for(j=0;j<3;j++){
					if((m[i][j]!=m[i][j+1])&&(m[i][j]!=m[i+1][j])&&(m[i][j]!=0)&&(m[i][j+1]!=0)&&(m[i+1][j]!=0)){
						c++;
					}
				}
			}
			for(i=0;i<4;i++){//kazanma kontrol�
				for(j=0;j<4;j++){
					if(m[i][j]==2048){
						c=-1;
					}
				}
			}
			do{//say� atama 
			k=rand()%4;
			l=rand()%4;
			}while((m[k][l]!=0)&&(c<9));
			if(c<9){
				m[k][l]=(rand()%2+1)*2;
			}
			if(c==9){
				printf("Oyun Bitti Kaybettiniz :(");
			}else if(c==-1){
				printf("Oyunu Kazand�n�z.");
			}
		}else if(a=='s'){//a�a��
			for(i=3;i>0;i--){//toplama i�lemi
				for(j=0;j<4;j++){
					if(m[i][j]==m[i-1][j]){
						m[i][j]=m[i][j]*2;
						m[i-1][j]=0;
					}
				}
			}
			for(j=0;j<4;j++){//toplama i�lemi
				if((m[0][j]!=m[1][j])&&(m[1][j]==0)&&(m[0][j]==m[2][j])){
						m[2][j]=m[2][j]*2;
						m[0][j]=0;
				}else if((m[0][j]!=m[1][j])&&(m[1][j]==m[2][j])&&(m[2][j]==0)&&(m[3][j]==m[0][j])){
						m[3][j]=m[3][j]*2;
						m[0][j]=0;
				}else if((m[1][j]!=m[2][j])&&(m[1][j]==m[3][j])&&(m[2][j]==0)){
						m[3][j]=m[3][j]*2;
						m[1][j]=0;
				}
			}
			for(i=3;i>0;i--){//kayd�rma i�lemi
				for(j=0;j<4;j++){
					n=3;
					while(n>0){
						if(m[n][j]==0){
							temp=m[n][j];
							m[n][j]=m[n-1][j];
							m[n-1][j]=temp;
						}
						n--;
					}
				}
			}
			c=0;
			for(i=0;i<3;i++){//kayb� kontrol i�lemi
				for(j=0;j<3;j++){
					if((m[i][j]!=m[i][j+1])&&(m[i][j]!=m[i+1][j])&&(m[i][j]!=0)&&(m[i][j+1]!=0)&&(m[i+1][j]!=0)){
						c++;
					}
				}
			}
			for(i=0;i<4;i++){//kazanc� kontrol i�lemi
				for(j=0;j<4;j++){
					if(m[i][j]==2048){
						c=-1;
					}
				}
			}
			do{
			k=rand()%4;
			l=rand()%4;
			}while((m[k][l]!=0)&&(c<9));
			if(c<9){
				m[k][l]=(rand()%2+1)*2;
			}
			if(c==9){
				printf("Oyun Bitti Kaybettiniz :(");
			}else if(c==-1){
				printf("Oyunu Kazand�n�z.");
			}
		}else if(a=='e'){
			c=10;
			printf("OYUNDAN CIKTINIZ.");
		}else if(a=='x'){//restart durumu
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					m[i][j]=0;
				}
			}
			k=rand()%4;
			l=rand()%4;
			m[k][l]=(rand()%2+1)*2;
		}else {
			printf("yanlis girdiniz tekrar giriniz(sag=r sol=l yukari=u asagi=d):");
		}
	}
	return 0;
}
