#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printf_random_seat(int data[],int n){
	int seat_sum=0;
	for(int i=0; i<n; i++){
		seat_sum+=data[i];
	}
	int seat_num[seat_sum];
	int a=0,r;
	for(int i=0; i<seat_sum; i++){
		seat_num[i]=i+1;	
	}
	for(int i=seat_sum-1; i>=0; i--){
		r=rand()%seat_sum;
		a=seat_num[i];
		seat_num[i]=seat_num[r];
		seat_num[r]=a;
	}
	int k=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<data[i]; j++){
			printf("%3d",seat_num[k-1]);
			k++;
		}
		puts("");
	}
}

int main(){
	int data[]={5,6,6,6,7,7,5};
	int n=sizeof(data)/sizeof(data[0]);
	srand((unsigned)time(NULL));
	printf_random_seat(data,n);
	return 0;
}
