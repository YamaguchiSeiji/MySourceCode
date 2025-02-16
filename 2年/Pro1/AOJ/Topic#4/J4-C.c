#include <stdio.h>
int main(){
    int a,b,i=0;
    char op;
    while(i>=0){
        scanf("%d %c %d",&a,&op,&b);
        if(op=='?')break;
        if(op=='+')printf("%d\n",a+b);
        if(op=='-')printf("%d\n",a-b);
        if(op=='*')printf("%d\n",a*b);
        if(op=='/')printf("%d\n",a/b);
    }
    return 0;
}
