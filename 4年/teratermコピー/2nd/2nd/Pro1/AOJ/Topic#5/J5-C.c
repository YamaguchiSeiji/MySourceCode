#include <stdio.h>
int main(void){
    int h,w;
    
    while(1){
        scanf("%d %d",&h,&w);
        if(h==0)break;
        for(int n=0;n<h;n++){
            if(w%2==0){
                for(int i=0;i<w/2;i++){
                    if(n%2==0){
                        printf("#.");
                    } else {
                        printf(".#");
                    }
                }
            } else {
                for(int i=0;i<w;i++){
                    if(n%2==0){
                        if(i%2==0){
                            printf("#");
                        } else {
                            printf(".");
                        }
                    } else {
                        if(i%2==0){
                            printf(".");
                        } else {
                            printf("#");
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

