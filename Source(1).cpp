#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa{
	char nome[20];
	int idade;
}PESSOA;

PESSOA pessoasOut[3];
PESSOA pessoasIn[3];

int main(){
	int i;
	for (i = 0; i < 3; i++){

		printf("Insira o nome\n");
		scanf("%s", &pessoasOut[i].nome);

		printf("Insira a idade\n");
		scanf("%d", &pessoasOut[i].idade);
	}

	FILE *fp = fopen("pessoas.bin", "wb");

	for (i = 0; i < 3; i++){
		fwrite(&pessoasOut[i], sizeof(pessoasOut[i]), 1, fp);
	}

	fclose(fp);

	FILE *fp2 = fopen("pessoas.bin", "rb");

	for (i = 0; i < 3; i++){

		fread(&pessoasOut[i], sizeof(pessoasOut[i]), 1, fp2);
		pessoasOut[i].nome == pessoasIn[i].nome;
		pessoasOut[i].idade == pessoasIn[i].idade;
	}

	fclose(fp2);
	exit(0);

	fflush(stdin);
	getchar();
}