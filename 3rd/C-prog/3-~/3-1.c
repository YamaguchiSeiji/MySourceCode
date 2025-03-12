#include <stdio.h>
int input(int data[], int num){
	int i=0;
	puts("整数を入力してください。(最大20個)");
	puts("Ctrl+Dで入力終了。");
	printf("%2d: ",i+1);
	while(scanf("%d",&data[i]) != EOF){
		printf("%2d: ",i+2);
		i++;
		if(i >= 20){
			break;
		}
	}
	return i;
}

void reverse(int data[], int num){
	printf("%d個の数字を逆の順番で出力します。\n",num);
	for(int i = num-1; i >= 0; i--){
		printf("%2d: %d\n",num-i, data[i]);
	}
}

int main(){
	int num = 20;
	int data[num];
	int i=input(data, num);
	reverse(data, i);
	return 0;
}
