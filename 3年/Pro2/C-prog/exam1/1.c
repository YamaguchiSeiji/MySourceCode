#include <stdio.h>

void dtoh(int, char[]);

int main(){
	int num;
	char s[8];
	for(int i=0; i < 8; i++){
		s[i] = '0';
	}
	scanf("%d", &num);
	int n=num;
	if(num < 0){
		puts("正の整数を入力してください.");
		return 0;
	}
	
	int j=0;
	while(s[j] != '\0'){
		num =  num  * 10 + (*s - '0');
		j++;
	}

	dtoh(num,s);
	return 0;
}

void dtoh(int num, char s[]){
	for(int i=7; i > 0; i--,num/=16){
		if(num%16 < 10){
			s[i] = num % 16 + '0';
		} else if(num%16 >= 10){
			
			s[i] = num % 10 + 'A';
		} else {
			s[i] = '0';
		}
		
	}
	printf("(%10d)10 -> (%s)16\n", num, s);
}
