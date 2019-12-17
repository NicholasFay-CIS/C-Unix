#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	FILE *fin, *fout; /*creates file we are reading, file we are writing */
	int row, col; /*initilize variables*/
	int buffer; /* initialize buffer */
	/*if there is not three arguments */
	if(argc != 3)
       	{
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*In File: open file and read binary. The file is the second arg in command line */
	fin = fopen(argv[1], "rb");
	/*Out File: open file to write to. this is third arg in command line */
	fout = fopen(argv[2], "w");
	/*since it is a ten b yten look at rows and columns, two loops one for the row and one for col */
	for(row=0; row<5; row++)
	{
		/*go to the begining of each row */
		fseek(fin, sizeof(int)*(row*10), SEEK_SET);
		for(col=0; col<5; col++) 
		{
			/* read the one digit at a time in the fin file */
			fread(&buffer, sizeof(int), 1, fin);
			/*print the one digit buffer with a new line char */
			fprintf(fout, "%d\n", buffer);
		}
	}
	/*close both the files we are using */		
	fclose(fin);
	fclose(fout);
}

