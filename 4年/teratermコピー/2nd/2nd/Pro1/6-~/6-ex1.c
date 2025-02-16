#include <stdio.h>
int main(){
	int size;
	do{
		printf("辺の長さを入力してください(3～15の奇数): ");
		scanf("%d",&size);
	} while(size%2==0||size<3||size>15);

	int squ[size][size];
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			squ[i][j]=0;
		}
	}
	
	int n=0,j=size/2;
	for(int i=1; i<=size*size; i++){
		if(squ[n][j]!=0){
			n+=2;
			j--;
		}
		squ[n][j]=i;
		if(n==0){
			n=size;
		}
		if(j==size-1){
			j=-1;
		}
		n--;
		j++;
		if(n==size-1&&j==0){
			n=1;
			j=size-1;
		}
	}

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%4d",squ[i][j]);
		}
		puts("");
	}

	return 0;
}
