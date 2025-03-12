#include <stdio.h>
int main(){
    int x,y;
    for(int i=0;i>=0;i++){
        scanf("%d %d",&x,&y);
        if(x==0&&y==0)break;
        if(x>y)printf("%d %d\n",y,x);
        if(x<y)printf("%d %d\n",x,y);
        if(x==y)printf("%d %d\n",x,y);
    }
    return 0;
}
