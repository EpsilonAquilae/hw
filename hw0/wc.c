#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void wc ( FILE *infile, char *inname);

int main (int argc, char *argv[]) {
	for (int i = 0; i < argc; i++){
		FILE *file = fopen (argv[i], "r");
		wc(file, argv[i]);
		fclose(file);
	}
	return 0;
}

void wc( FILE *infile, char *inname) {

	int total = 0;
	int spacecount = 1; // include the newline
	int newlinecount = 0;
	char ch;

//	infile = fopen(inname, "r");

	if (infile == NULL) return;

	while ((ch = fgetc(infile)) != EOF)
	{
		if (ch == ' ') spacecount++;
		if (ch == '\n') newlinecount++;
		total++;
	}

	printf("%i %i %i %s\n", newlinecount, spacecount, total, inname);
}
