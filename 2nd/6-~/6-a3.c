#include <stdio.h>
int main(){
	int day[365][6];
	for(int i=0; i<365; i++){
		scanf("%d,%d,%d,%d,%d,%d",&day[i][0],&day[i][1],&day[i][2],&day[i][3],&day[i][4],&day[i][5]);
	}
/*
			0		1		2		
		 max_tem min_tem max_pre 
0 data	   0,0     0,1     0,2
1 year	   1,0	   1,1	   1,2
2 month	   2,0     2,1	   2,2
3 day	   3,0	   3,1	   3,2

*/
	int data[4][3][365]={};
	int n[3]={1,1,1};

	for(int i=0; i<365; i++){
		if(data[0][0][0]<day[i][3]){
			data[0][0][0]=day[i][3];
			data[1][0][0]=day[i][0];			
			data[2][0][0]=day[i][1];			
			data[3][0][0]=day[i][2];			
		} else if(data[0][0][0]==day[i][3]){
			data[0][0][n[0]]=day[i][3];
			data[1][0][n[0]]=day[i][0];
			data[2][0][n[0]]=day[i][1];
			data[3][0][n[0]]=day[i][2];
			n[0]++;
		}

		if(data[0][1][0]>day[i][4]){
			data[0][1][0]=day[i][4];
			data[1][1][0]=day[i][0];			
			data[2][1][0]=day[i][1];			
			data[3][1][0]=day[i][2];			
		} else if(data[0][1][1]==day[i][4]){
			data[0][1][n[1]]=day[i][4];
			data[1][1][n[1]]=day[i][0];
			data[2][1][n[1]]=day[i][1];
			data[3][1][n[1]]=day[i][2];
			n[1]++;
		}

		if(data[0][2][0]<day[i][5]){
			data[0][2][0]=day[i][5];
			data[1][2][0]=day[i][0];			
			data[2][2][0]=day[i][1];			
			data[3][2][0]=day[i][2];			
		}else if(data[0][0][2]==day[i][5]){
			data[0][2][n[0]]=day[i][5];
			data[1][2][n[0]]=day[i][0];
			data[2][2][n[0]]=day[i][1];
			data[3][2][n[0]]=day[i][2];
			n[2]++;
		}

	}
	
	for(n[0]=0; data[0][1][n[0]]!=0; n[0]++){
	printf("気温が最も高かった日: %d年%d月%d日　%d℃\n",data[1][0][n[0]],data[2][0][n[0]],data[3][0][n[0]],data[0][0][n[0]]);
	}
	
	for(n[1]=0; data[0][1][n[1]]!=0; n[1]++){
	printf("気温が最も低かった日: %d年%d月%d日　%d℃\n",data[1][1][n[1]],data[2][1][n[1]],data[3][1][n[1]],data[0][1][n[1]]);
	}
	for(n[2]=0; data[0][1][n[2]]!=0; n[2]++){
	printf("降水量が最も多かった日: %d年%d月%d日　%dmm\n",data[1][2][n[2]],data[2][2][n[2]],data[3][2][n[2]],data[0][2][n[2]]);
	}

	return 0;
}
