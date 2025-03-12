#include <stdio.h>
int main(void){
    int w,h;
    while(1){
        scanf("%d %d",&h,&w);
        if(w==0)break;
        for(int i=0;i<h;i++){
           for(int i=0;i<w;i++){
                printf("#");
            }
         printf("\n");
      }
      printf("\n");
    
    }
    return 0;
}

