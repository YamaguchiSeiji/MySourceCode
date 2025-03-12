#include <stdio.h>
void drawrect(int h,int w,char ch){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			printf("%c",ch);
		}
		puts("");
	}

}

int main(){
	drawrect(4,3,'@');
	drawrect(2,4,'#');
	return 0;
}
