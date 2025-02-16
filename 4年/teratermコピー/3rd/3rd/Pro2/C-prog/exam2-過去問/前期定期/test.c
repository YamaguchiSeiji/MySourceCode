#include <stdio.h>

int main (void){



FILE *fp;

fp=fopen("data_int","wb");

if(fp==NULL){

printf("ファイルオープンに失敗しましたよ～ん\n");

return -1;}

else printf("Hello!ファイルオープンに成功しましたよ～ん\n");

int hairetu[]={1,2,3,4,5,6,7};

fwrite(&hairetu[0],sizeof(int),1,fp);

fwrite(&hairetu[1],sizeof(int),1,fp);

fwrite(&hairetu[2],sizeof(int),1,fp);

fwrite(&hairetu[3],sizeof(int),1,fp);

fwrite(&hairetu[4],sizeof(int),1,fp);

fwrite(&hairetu[5],sizeof(int),1,fp);

fwrite(&hairetu[6],sizeof(int),1,fp);



fclose(fp);

return 0;

}
