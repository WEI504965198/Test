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

	while (fgets(Line, BUF_SIZE - 1, IN_CODE) != NULL) // Until the end of the input file
	{
		if (Line[0] != ' ' && IsDef(Line)) {	// If find a "def" statement

			while (1) {

				IFC_IN = 0;
				IFC_OUT = 0;
				CYC = 0;

				if (!IsDef(Line)) { // Repeat until the "def" comes out
					while (fgets(Line, BUF_SIZE - 1, IN_CODE) != NULL)
						if (IsDef(Line))break;
				}

				if (Line[0] != ' ' && IsDef(Line)) // if "def"
				{
					PrintDef(Line);
					IFC_IN += ifc_in(Line);  // Analyze "def" and "IFC" 
				}

				if (fgets(Line, BUF_SIZE - 1, IN_CODE) == NULL) // If it's "NULL", then break. If it's not "NULL", read the next sentence
				{
					break;
				}
			}
		}
	}
	return 0;
}