#include <stdio.h>
int main(){
	int day[365][6];
	for(int i=0; i<365; i++){
		scanf("%d,%d,%d,%d,%d,%d",&day[i][0],&day[i][1],&day[i][2],&day[i][3],&day[i][4],&day[i][5]);
		/* year month day maxtem mintem maxpre*/
	}
	int data[365][3][4]={};
	int n[3]={};
	for(int i=0; i<365; i++){
		//maxtem
		if(day[i][3]>data[n[0]][0][3]){
			data[0][0][0]=day[i][0];
			data[0][0][1]=day[i][1];
			data[0][0][2]=day[i][2];
			data[0][0][3]=day[i][3];
			n[0]=0;
		} else if(day[i][3]==data[0][0][3]){
			n[0]++;
			data[n[0]][0][0]=day[i][0];
			data[n[0]][0][1]=day[i][1];
			data[n[0]][0][2]=day[i][2];
			data[n[0]][0][3]=day[i][3];
		}

		//mintem
		if(day[i][4]<data[n[0]][1][3]){
			data[0][1][0]=day[i][0];
			data[0][1][1]=day[i][1];
			data[0][1][2]=day[i][2];
			data[0][1][3]=day[i][4];
			n[1]=0;
		} else if(day[i][4]==data[0][1][3]){
			n[1]++;
			data[n[1]][1][0]=day[i][0];
			data[n[1]][1][1]=day[i][1];
			data[n[1]][1][2]=day[i][2];
			data[n[1]][1][3]=day[i][4];
		}

		//maxpre
		if(day[i][5]>data[n[0]][2][3]){
			data[0][2][0]=day[i][0];
			data[0][2][1]=day[i][1];
			data[0][2][2]=day[i][2];
			data[0][2][3]=day[i][5];
			n[2]=0;
		} else if(day[i][5]==data[0][2][3]){
			n[2]++;
			data[n[2]][2][0]=day[i][0];
			data[n[2]][2][1]=day[i][1];
			data[n[2]][2][2]=day[i][2];
			data[n[2]][2][3]=day[i][5];
		}
	}
	
	puts("～気温が最も高かった日～");
	for(int i=0; i<=n[0]; i++){
		printf("%d年%d月%d日 %d℃\n",data[i][0][0],data[i][0][1],data[i][0][2],data[i][0][3]);
	}
	puts("");
	puts("～気温が最も低かった日～");
	for(int i=0; i<=n[1]; i++){
		printf("%d年%d月%d日 %d℃\n",data[i][1][0],data[i][1][1],data[i][1][2],data[i][1][3]);
	}
	puts("");
	puts("～降水量が最も多かった日～");
	for(int i=0; i<=n[0]; i++){
		printf("%d年%d月%d日 %dmm\n",data[i][2][0],data[i][2][1],data[i][2][2],data[i][2][3]);
	}
	puts("");

	return 0;
}
