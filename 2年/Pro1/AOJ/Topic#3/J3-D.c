#include <stdio.h>
int main(){
    int a,b,c;
    int n=0;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=a;i<=b;i++){
        if(c%i==0)n++;
    }
    printf("%d\n",n);
    
    return 0;
}
