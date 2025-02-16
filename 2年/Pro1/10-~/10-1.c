#include <stdio.h>
int main(){
	char familyname[48],firstname[48];
	printf("Input your family name: ");
	scanf("%s",familyname);
	printf("Input your first name: ");
	scanf("%s",firstname);

	printf("Hello, %s %s!\n",firstname,familyname);
	printf("Initials: %c.%c.\n",firstname[0],familyname[0]);
	return 0;
}


