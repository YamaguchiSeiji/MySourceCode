#include <stdio.h>
int main(){
	char mouths[]={'_','o','.'};
	char eyes[]={'*',';','^','~','-'};
	for(int i=0; i<sizeof(eyes)/sizeof(eyes[0]); i++){
		for(int j=0; j<sizeof(mouths)/sizeof(mouths[0]); j++){
			printf("(%c%c%c)\n",eyes[i],mouths[j],eyes[i]);
		}
	}
	return 0;
}
