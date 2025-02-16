#include <stdio.h>
struct person{
	char name[64];
	int age;
};

int main(){
	int num=2,i=0;
	struct person s[2];
	while(i<num){
		printf("名前: ");
		scanf("%s",s[i].name);
		printf("年齢: ");
		scanf("%d",&s[i].age);
		i++;
	}
	if(s[0].age>s[1].age){
		printf("%sさんの方が%d歳年上です。\n",s[0].name,s[0].age-s[1].age);
	} else if(s[0].age<s[1].age){
		printf("%sさんの方が%d歳年上です。\n",s[1].name,s[1].age-s[0].age);
	} else {
		printf("%sさんと%sさんは同い年です。\n",s[0].name,s[1].name);
	}
	
	return 0;
}
