#include <stdio.h>
#include <iostream>
#define BUFFSIZE 124

extern double X[100][5];

void read_data(char* fname) {
	FILE* fp; // FILE�^�\����
	errno_t err; // errno_t�^(int�^)
	int i = 0;
	char delim[] = " ";
	char* ctx;
	char readline[BUFFSIZE];
	err = fopen_s(&fp, fname, "r"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
	if (err != 0) {
		printf("%s file not open!\n", fname);
	}
	else {
		printf("%s file opened!\n", fname);

		// 1�s�Âǂݍ���
		while (fgets(readline, BUFFSIZE, fp) != NULL) {
			X[i][0] = atof(strtok_s(readline, delim, &ctx));
			X[i][1] = atof(strtok_s(NULL, delim, &ctx));
			X[i][2] = atof(strtok_s(NULL, delim, &ctx));
			X[i][3] = atof(strtok_s(NULL, delim, &ctx));
			X[i][4] = atof(strtok_s(NULL, delim, &ctx));
			i++;
		}
	}


	fclose(fp); // �t�@�C�������

}