#include <stdio.h>
#include <stdlib.h>
unsigned int myatoi(const char *p);
void dtob(unsigned int a);
  
int main(int argc, char *argv[]){
	if(argc == 1){
  		printf("dtobの後に入力された10進数を2進数表記で出力するプログラムです\n数字列は符号なし整数のみを対象とします\nUsage: $ ./dtob {数字列}\n");
 		exit(0);
	}
 
 	for(int i = 1; i < argc; i++){
 		dtob(myatoi(argv[i]));
	}	
 
	 return 0;
}
 
unsigned int myatoi(const char *p){
	int i = 0;
 	unsigned int number = 0;
 	while(*(p+i) != '\0'){
 		if(*(p+i) < '0' || *(p+i) > '9'){
 			printf("数字以外の文字が入力されました\n");
 			exit(0);
 		}
 		number = number * 10 + (*(p+i) - '0');
 		i++;
 	}
 	return number;
}
 
void dtob(unsigned int a){
	int reverse[32] = {0};
	printf("%11u -> ", a);
 
	for(int i = 31; a > 0; i--){
 	 	reverse[i] = a % 2;
        a /= 2;
    }
	reverse[32] = '\0';
	for(int j=0; j<=31; j++){
		printf("%d", reverse[j]);
	}

	puts("");
}


/*void dtob(unsigned int num){
	char s[32];
	unsigned int n=num;
	for(int i=31; i >= 0; n /= 2, i--){
		if(n % 2 == 0){
			s[i] = '0';
		} else if(n % 2 == 1){
			s[i] = '1';
		}
		if(n==1){
			for(int j=i-1; j >= 0; j--){
				s[j] = '0';
			}
		}
	s[32] = '\0';
	}
	printf("%11u -> %s\n", num, s);
}
*/ 
