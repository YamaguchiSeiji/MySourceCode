#include <stdio.h>
void show(int v[],int len){
        for(int i=0; i<len; i++){
                printf("%d番目の要素： %d\n",i,v[i]);
        }
}

int main(){
        int x[5]={1,30,-5,2,5000};
        show(x,5);
        return 0;
}
