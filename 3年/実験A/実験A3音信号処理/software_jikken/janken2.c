#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define TIE 0
#define WIN 1
#define LOSE -1

int setPlayerHand();
int setComputerHand();
int judge(int player, int computer);
void printResult(int result, int player, int computer);

int main(){
	int player;
	int computer;
	int result;
	
	srandom(time(0));

	while(1){

		computer = setComputerHand();

		player = setPlayerHand();
		result = judge(player, computer);
		printResult(result, player, computer);
		if(result != TIE){
			break;
		}
	}

	return 0;
}

int setComputerHand(){
	long a;
	a = random() % 3 + 1;

	return a;
}

int setPlayerHand(){
	int playerhand;
	while(1){
		system("clear");
		puts("じゃんけんの手を決めてください(1:ぐー, 2:ちょき, 3:ぱー)：");
		scanf("%d",&playerhand);

		if(playerhand>=1 && playerhand<=3){
			return playerhand;
		} else {
			puts("値が無効です.");
			sleep(1);
		}
	}
}


int judge(int player, int computer){
	if(player == 1 && computer == 2 || player == 2 && computer == 3 || player == 3 && computer == 1){
		return WIN;
	} else if(player == 1 && computer == 3 || player == 2 && computer == 1 || player == 3 && computer == 2){
		return LOSE;
	} else {
		return TIE;
	}
}

void printResult(int result, int player, int computer){
	sleep(1);
	if(player == 1){
		puts("あなた：ぐー");
	} else if(player == 2){
		puts("あなた：ちょき");
	} else if(player == 3){
		puts("あなた：ぱー");
	}
	if(computer == 1){
		puts("コンピュータ：ぐー");
	} else if(computer == 2){
		puts("コンピュータ：ちょき");
	} else if(computer == 3){
		puts("コンピュータ：ぱー");
	}

	if(result == LOSE){
		puts("\e[34m\e[47mあなたの負けです\e[0m");
	} else if(result == TIE){
		puts("\e[33m引き分けです\e[0m");
		sleep(1);
	} else if(result == WIN){
		puts("\e[31m\e[47mあなたの勝ちです\e[0m");
	}
}
