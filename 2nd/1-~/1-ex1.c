#include <stdio.h>
 int main(){
 
  int n; scanf("%d",&n);
  int x[n],y[n],z[n];
  
  for(int i=0; i<n; i++){
     scanf("%d %d %d",&x[i],&y[i],&z[i]);
 }
  
  for(int i=0; i<n; i++){
      
      if(x[i]*x[i]+y[i]*y[i]==z[i]*z[i] || x[i]*x[i]+z[i]*z[i]==y[i]*y[i] || z[i]*z[i]+y[i]*y[i]==x[i]*x[i]){
          printf("YES\n");
      } else {
              printf("NO\n");
              }
    }
 
     return 0;
 }
