#pragma warning(disable :4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

FILE* IN_CODE;
FILE* OUT_TXT;

int IsDef(char* Line);
int IsReturn(char* Line);
void PrintDef(char* Line);
int cyc(char* Line);
int ifc_in(char Line[]);
int ifc_out(char Line[]);

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("Usage : %s <input.py> <output.txt>\n", argv[0]);
		exit(1);
	}

	char Line[BUF_SIZE];
	char py_code[100];
	char txt_file[100];

	strcpy(py_code, argv[1]);
	strcpy(txt_file, argv[2]);

	IN_CODE = fopen(py_code, "r");
	if (IN_CODE == NULL)
	{
		fprintf(stderr, "File not found\n");
		exit(1);
	};
	OUT_TXT = fopen(txt_file, "w");
	if (OUT_TXT == NULL)
	{
		fprintf(stderr, "File Open Error!\n");
		exit(1);
	};

	int IFC_IN = 0;
	int IFC_OUT = 0;
	int CYC = 0;

	return 0;
}