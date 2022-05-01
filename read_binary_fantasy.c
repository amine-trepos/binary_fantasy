# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>

char abinaryascii_to_char (char* abinarybyte);

int main (int argc, char* argv[])
{
	/* 1文字ずつの表示設定 */
	setvbuf(stdout, NULL, _IONBF, 0);
	struct timespec typing_speed = {
		0,			/* 秒 */
		300000000	/* ナノ秒 0~999999999 */
	};

	/* 1byte分読み込んで表示 */
	printf("\n");
	{
		int i;
		for (i=1;i<argc;i++) {
			printf("%c", abinaryascii_to_char(argv[i]));
			nanosleep(&typing_speed, NULL);
		}
	}
	printf("\n\n");
	
	return 0;
}

char abinaryascii_to_char (char* abinaryascii)
{
	int b[8];
	int i;
	for (i=0;i<8;i++) {
		b[7-i] = (int)(*(abinaryascii+i)-'0');
	}
	if ((b[7]!=0)||(strlen(abinaryascii)!=8)) {
		fprintf(
			stderr,
			"\n\033[1;33merror:\033[m"
			" \"%s\" "
			"8ビットのASCIIコードではありません\n",
			abinaryascii
		);
		exit(EXIT_FAILURE);
	}
	return (char)(b[6]*64+b[5]*32+b[4]*16+b[3]*8+b[2]*4+b[1]*2+b[0]*1);
}
