#include <stdio.h>
int main(){
	int ch, ch_sum=0, alp_sum=0;	
	while((ch = getchar()) != EOF){
		if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
			alp_sum++;
		}
		ch_sum++;
	}
	puts("");
	printf("全体文字数：%5d		英字の数：%5d\n", ch_sum, alp_sum);
	printf("英字が占める割合：%7.2f%%\n", (double)alp_sum / ch_sum * 100);
	return 0;
}
