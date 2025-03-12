#include <stdio.h>
int main(){
	int data[7][9]={
	{1,1,1,1,1,1,1,1,1},
	{0,0,0,0,2,0,0,0,0},
	{0,0,0,2,0,2,0,0,0},
	{0,0,2,0,0,0,2,0,0},
	{0,2,2,2,2,2,2,2,0},
	{2,0,0,0,0,0,0,0,2},
	{1,1,1,1,1,1,1,1,1}
	};

	for(int i=0; i<7; i++){
		for(int j=0; j<9; j++){
			switch(data[i][j]){
				case 1: putchar('-');
						break;
				case 2: putchar('#');
						break;
				default : putchar(' ');
						break;
			}
		}
		puts(" ");
	}
	return 0;
}
