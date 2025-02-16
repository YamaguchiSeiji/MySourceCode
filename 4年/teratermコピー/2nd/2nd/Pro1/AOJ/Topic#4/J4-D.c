#include <stdio.h>
int main(){
    int n,i;
    int min=1000000,max=-1000000;
    long long sum=0;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++){
        scanf("%d ",&x[i]);
    }
    for(i=0;i<n;i++){
        sum+=x[i];
        if(min>x[i])min=x[i];
        if(max<x[i])max=x[i];
    }
    printf("%d %d %lld\n",min,max,sum);

    return 0;
}
