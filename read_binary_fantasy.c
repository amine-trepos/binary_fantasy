/* Copyright 2022 amine-trepos
 *
 * This file is part of binary_fantasy.
 *
 * binary_fantasy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * binary_fantasy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with binary_fantasy.  If not, see <https://www.gnu.org/licenses/>.
 */

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
