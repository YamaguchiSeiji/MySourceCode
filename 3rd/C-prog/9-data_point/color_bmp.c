#include	<stdio.h>
#include	<stdlib.h>
#include	<stdint.h>	// uint32_t や uint8_t を使うため

typedef struct pixel {
	uint8_t b;
	uint8_t g;
	uint8_t r;
} Pixel;


int main(int argc, char *argv[])
{
	uint32_t	size_w, size_h;	// 符号なし整数 32ビット
	uint32_t 	data_pos;
	Pixel 		pix;
	FILE		*fp;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	fp = fopen( argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "File %s not opened\n", argv[1]);
		exit(1);
	}

	fseek(fp, 18, SEEK_SET);		// ファイル先頭から18バイト目へ移動
	fread(&size_w, sizeof(uint32_t), 1, fp);	// 画像の幅　を読み込み
	fread(&size_h, sizeof(uint32_t), 1, fp);	// 画像の高さを読み込み

	fseek(fp, 10, SEEK_SET);
	fread(&data_pos, sizeof(uint32_t), 1, fp);

	fseek(fp, data_pos, SEEK_SET);
	fread(&pix, sizeof(Pixel), 1, fp);


	fclose(fp);

	printf("%s: width=%d, height=%d\n", argv[1], size_w, size_h);
	printf("%s: B =%02X, G=%02X, R=%02X\n", argv[1], pix.b, pix.g, pix.r);
	printf("%s: B =%d, G=%d, R=%d\n", argv[1], pix.b, pix.g, pix.r);

	return 0;
}
