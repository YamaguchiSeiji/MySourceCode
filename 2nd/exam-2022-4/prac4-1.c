#include <stdio.h>

struct person{
	char name[80];
	int birth_year;
	int birth_month;
};

int combirth(struct person p1, struct person p2){
	int n;
	if(p1.birth_year > p2.birth_year){
		n = 1;
	} else if(p1.birth_year == p2.birth_year){
		if(p1.birth_month > p2.birth_month){
			n = 1;
		} else {
			n = 0;
		}
	} else {
		n = 0;
	}
	return n;
}

int main(){
	struct person pa={"Alice", 1999, 5};
	struct person pb={"Bob", 2000, 5};
	struct person pc={"Chris", 1999, 4};

	printf("%sは%sより若い？: %d\n", pa.name, pb.name, combirth(pa, pb));
	printf("%sは%sより若い？: %d\n", pa.name, pc.name, combirth(pa, pc));

	return 0;
}
