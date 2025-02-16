#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char func;
	int addr;
} instruction;

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Error");
		return 0;
	}

	FILE *fp = fopen(argv[1], "r");
	
	if(fp == NULL){
		printf("file not open!\n");
		exit(1);
	}
	
	instruction input[1000];
	int count = 0;
	int data[1000];
	int acc;
	int start_addr;
	int flag = 0;
	
	while(fscanf(fp, "%c %d\n", &input[count].func, &input[count].addr) != EOF){
		if(input[count].func == '*'){
			count += input[count].addr - 1;
		}
		count++;
	}

	count = 0;
	while(1){
		printf("%d: %c: %d\n", count, input[count].func, input[count].addr);
		switch(input[count].func){
			case '*':
				start_addr = input[count].addr;
				count += start_addr;
				break;
			case 'L':
				acc = data[input[count].addr];
				break;
			case 'C':
				acc = input[count].addr;
				break;
			case 'T':
				data[input[count].addr] = acc;
				break;
			case 'A':
				acc += data[input[count].addr];
				break;
			case 'S':
				acc -= data[input[count].addr];
				break;
			case 'M':
				acc *= data[input[count].addr];
				break;
			case 'D':
				acc /= data[input[count].addr];
				break;
			case 'J':
				count = input[count].addr + start_addr;
				continue;
			case 'Z':
				if(acc == 0){
					count = input[count].addr + start_addr;
					continue;
				}
				break;
			case 'R':
				printf("Input: ");
				scanf("%d", &data[input[count].addr]);
				break;
			case 'W':
				printf("Result: %d\n", data[input[count].addr]);
				break;
			case 'H':
				flag = 1;
			case '/':
				start_addr = input[count].addr - 1;
				count += start_addr;
				break;
		}
		count++;
		if(flag){
			break;
		}

	}	
	fclose(fp);

}
