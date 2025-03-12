#include <stdio.h>
unsigned int myatoi(const char *s);

void dtob(unsigned int num);

int main(int argc, char* argv[]){
	if(argc == 1){
		puts("dtobの後に入力された10進数を2進数表記を出力するプログラムです.");
		puts("数字列は符号なし整数のみを対象とします.");
		puts("Usage: $ ./dtob {数字列}");
	}
	
	for(int i=1; i<argc; i++){
		for(int j=0; argv[i][j] != '\0'; j++){
			if(argv[i][j] < '0' || argv[i][j] > '9'){
				puts("数字以外の文字が入力されました。");
				return 0;
			}
		}
		dtob(myatoi(argv[i]));
	}

	return 0;
}

unsigned int myatoi(const char *s){
	unsigned int num = 0;
	while(*s != '\0'){
		num =  num  * 10 + (*s - '0');
		s++;
	}
	return num;
}

void dtob(unsigned int num){
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

	}
	s[32] = '\0';
	printf("%11u -> %s\n", num, s);
}
