#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Nicholas Fay*/

typedef struct
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
/* data members go here */
} Pixel;

typedef struct
{
	int width;
	int height;
	int max_value;
	Pixel *pix_array;
/* data members go here */
} Image;

/*
 * Arguments:
 *   filename: the name of the file to read
 *   img:      a pointer to an Image struct.  You put the data from the
 *             file in this struct
 */

void
ReadImage(char *filename, Image *img)
{
	FILE *f_in;
	int width, height, maxval;
	char magicNum[128];
	f_in = fopen(filename, "rb");
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	img->width = width;
	img->height = height;
	img->max_value = maxval;
	img->pix_array = malloc((sizeof(Pixel)*img->height*img->width));
	fread(img->pix_array, sizeof(Pixel), img->height*img->width, f_in);
	fprintf(stderr, "Reading image \"%s\"\n", filename);
    /* These lines are useful:
     * char magicNum[128];
     * int width, height, maxval;
     * fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
     * where f_in is the name of the input FILE.
     * NOTE: maxval is not needed, but we need to parse it.
     * NOTE: after the fscanf above, the file position indicator will
     * be pointing directly at the pixel data.
     */
	fprintf(stderr, "Done reading image \"%s\"\n", filename);
	fclose(f_in);
}


/*
 * Arguments:
 *   filename: the name of the file to write
 *   img:      a pointer to an Image struct.  You put the data from the
 *             file in this struct
 */

void WriteImage(char *filename, Image *img)
{
	FILE *f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out,"P6\n%d %d\n%d\n",img->width, img->height, 255);
	fwrite(img->pix_array, sizeof(Pixel), img->height*img->width, f_out);
	fprintf(stderr, "Writing image \"%s\"\n", filename);
    /* HINT:
     *  use fprintf to print out the first 4 lines of the file
     *  then use fwrite to print binary data.
     */
	fprintf(stderr, "Done writing image \"%s\"\n", filename);
	fclose(f_out);
}

/* 
 * Arguments:
 *    width:  the width of the image
 *    height: the height of the image
 *    row:    the row of the pixel
 *    column: the column of the pixel
 *
 * Returns: the index of the pixel in the image for (column, row)
 */

int GetPixelIndex(int width, int height, int row, int column)
{
    if (column < 0 || column >= width)
    {
        fprintf(stderr, "You asked for a pixel index for column %d, but the only valid values are between 0 and %d\n", column, width-1);
        exit(EXIT_FAILURE);
    }
    if (row < 0 || row >= height)
    {
        fprintf(stderr, "You asked for a pixel index for row %d, but the only valid values are between 0 and %d\n", row, height-1);
        exit(EXIT_FAILURE);
    }
    return row*width + column;
}

/* 
 * Arguments:
 *   input:    an image.  Take this image and replace the diagonal with
 *             a yellow line.
 *   output:   an image.  This should be the image with the yellow line
 *             diagonal.
 */
void YellowDiagonal(Image *input, Image *output)
{
		
    fprintf(stderr, "Executing YellowDiagonal\n");
    output->height = input->height;
    output->width = input->width;
    output->pix_array = malloc(sizeof(Pixel)*output->width*output->height);
    for(int row=0; row<output->height; row++)
    {
	   for(int col=0; col<output->width; col++)
	   {
		  int x = GetPixelIndex(output->width, output->height, row, col);
		  if(row == col)
		  {
			 output->pix_array[x].R = 255;
			 output->pix_array[x].G = 255;
			 output->pix_array[x].B = 0;

		  }
		  else
		  {
			 output->pix_array[x].R = input->pix_array[x].R;
			 output->pix_array[x].G = input->pix_array[x].G;
			 output->pix_array[x].B = input->pix_array[x].B;
	  	  }

	   }
    }

    /* HINTS: 
     *   You will need to assign values to every data member of the output.
     *   For the output's Pixel array you will need to do a malloc to get
     *   a new array.
     *   Yellow in R/G/B is 255/255/0.
     */
    fprintf(stderr, "Done executing YellowDiagonal\n");
}

/* 
 * Arguments:
 *   input1:    an image.  This is the "left image".
 *   input2:    an image.  This is the "right image".
 *   output:    an image.  This is the horizontal combination of input1 and 2.
 */
void LeftRightCombine(Image *input1, Image *input2, Image *output)
{
    fprintf(stderr, "Executing LeftRightCombine\n");
    output->width = input1->width + input2->width;
    output->height = input1->height;
    output->pix_array = malloc(sizeof(Pixel)*output->width*output->height);
    for(int row=0; row<input1->height; row++)
    {
	    for(int col=0; col<input1->width; col++) 
	    {
		   int x = GetPixelIndex(input1->width, input1->height, row, col);
		   int y = GetPixelIndex(output->width, output->height, row, col);
		   output->pix_array[y] = input1->pix_array[x];

	    }
     }
    for(int row=0; row<input2->height; row++)
    {
	    for(int col=0; col<input2->width; col++)
	    {
		    int z = GetPixelIndex(input2->width, input2->height, row, col);
		    int w = GetPixelIndex(output->width, output->height, row, col+input1->width);
		    output->pix_array[w] = input2->pix_array[z];

	    }
    }
   
    /* HINTS: 
     *   You will need to assign values to every data member of the output.
     *   For the output's Pixel array you will need to do a malloc to get
     *   a new array.
     *   The output's Pixel array will be larger than either of the inputs.
     *   IMPORTANT: the pixel index for an output pixel will be different
     *     than the pixel index for either of the inputs ... you will need
     *     to call GetPixelIndex multiple times.
     */

    fprintf(stderr, "Done executing LeftRightCombine\n");
}

void
VerifyInput()
{
    FILE *f_in = fopen("2G_input.pnm", "r");
    if (f_in == NULL)
    {
        fprintf(stderr, "Cannot open 2G_input.pnm for reading.\n");
        exit(EXIT_FAILURE);
    }
    fclose(f_in);

    FILE *f_out = fopen("2G_output.pnm", "w");
    if (f_out == NULL)
    {
        fprintf(stderr, "Cannot open 2G_output.pnm for writing.\n");
        exit(EXIT_FAILURE);
    }
    fclose(f_out);
}

int main(int argc, char *argv[])
{
    VerifyInput();

    Image source_image;
    Image yellow_diagonal;
    Image left_right;

    ReadImage("2G_input.pnm", &source_image);
    WriteImage("output_of_read.pnm", &source_image);

    YellowDiagonal(&source_image, &yellow_diagonal);
    WriteImage("yellow_diagonal.pnm", &yellow_diagonal);

    LeftRightCombine(&source_image, &yellow_diagonal, &left_right);
    WriteImage("2G_output.pnm", &left_right);

    free(source_image.pix_array);
    free(yellow_diagonal.pix_array);
    free(left_right.pix_array);

    return 0;
}
