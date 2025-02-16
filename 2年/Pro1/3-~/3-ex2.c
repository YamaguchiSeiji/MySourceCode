#include <stdio.h>
int main(){
	int height,width;
	int h=0,w=0;

	do{
		printf("高さと幅を空白区切りで入力してください（どちらも3以上の奇数）");
		scanf("%d %d",&height,&width);
		if(height<3||width<3||height%2==0||width%2==0){
			printf("値が正しくありません。\n");
		}
	} while(height<3||width<3||height%2==0||width%2==0);
	
	while(h<height){
		if(h==0||h==height/2||h==height-1){
			while(w<width){
				putchar('*');
				w++;
			}
		} else {
			while(w<width){
				if(w==0||w==width/2||w==width-1){
					putchar('*');
				} else {
					putchar(' ');
				}
				w++;
			}
		}
		w=0;
		printf("\n");
		h++;
	}

	return 0;
}
