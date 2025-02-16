#include <stdio.h>
int main(void){
    int h,w;
   
    while(1){
        scanf("%d %d",&h,&w);
        if(w==0)break;
        for(int i=0;i<h-1;i++){
            if(i==0||i==h){
                for(int i=0;i<w;i++){
                    printf("#");
                }
            } else {
                printf("#");
                for(int i=0;i<w-2;i++){
                    printf(".");
                }
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<w;i++){
            printf("#");
        }
        printf("\n\n");
    }
    return 0;
}

