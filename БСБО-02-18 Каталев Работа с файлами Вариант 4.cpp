#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

int main() {
	FILE* f;
	char c,file1[10],file2[10];
	int count = 1;

	printf("Enter the name of the input file: ");
	scanf("%s", &file1);
	printf("Enter the name of the output file: ");
	scanf("%s", &file2);

	if ((f = fopen(file1, "r")) == 0) {
		printf("Error reading file. Restart the program!");
		perror(file1);
	}
	else
		while ((c = fgetc(f)) != EOF)
			if (c == '\n') count++;

	printf("Number of lines in file: %d\n",count);
	fclose(f);

	if ((f = fopen(file2, "w")) == 0)
	{
		printf("Error writting file. Restart the program!");
		perror(file2);
	}
	else
		fprintf(f,"Number of lines in file: %d\n", count);

	fclose(f);
	return 0;
}