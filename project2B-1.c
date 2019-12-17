#include <stdio.h>

int main()
{
    int A[100] = { 252, 657, 268, 402, 950, 66, 391, 285, 133, 577, 649, 166, 987, 314, 954, 214, 920, 230, 904, 801, 40, 552, 369, 682, 202, 712, 395, 517, 755, 603, 134, 385, 428, 941, 443, 477, 95, 647, 687, 737, 673, 19, 325, 697, 577, 181, 45, 964, 267, 600, 858, 145, 781, 760, 949, 508, 673, 717, 446, 634, 635, 679, 466, 474, 916, 855, 216, 899, 804, 159, 237, 625, 963, 388, 437, 682, 821, 325, 805, 876, 968, 414, 190, 434, 902, 794, 752, 729, 77, 243, 705, 953, 765, 637, 765, 158, 166, 599, 70, 927 };
    /* YOUR CODE GOES HERE */

    /* SORT IT */
    /* establishes variables for i, k and possible to be integers */
    int i; /* variable for the number that is being compared to everything else */ 
    int k; /* variable that loops through numbers in list and compares to i */
    int possible; /* variable for a switched number */
    /* First loop, i starts at the first index and goes upto the last two elements */
    for(i=0;i<100;i++)
    {
	    /* Second loop, k starts one index higher than i, loops upto last two elements */
	    for(k=i+1;k<100;k++)
	    {
		    /* if number at i is greater than number at k */
		    if(A[i]>A[k])
		    {
			    /* poss variable set to number at index i */
			    possible = A[i];
			    /* swaps number at i and number at k */
			    A[i] = A[k];
			    /* sets the number at index k to possible var */
			    A[k] = possible;
	    	    }
             }
     }



    /* PRINT IT */
    /* loop to print each element in the list */
    for(i=1; i<101; i++)
    {
	    /* prints number at index i minus one, includes a tab in print */
	    printf("\t%d", A[i-1]);
	/* if index count divided by 10 and i greater than zero, print a newline */
        if (i % 10 == 0 && i > 0) {
            printf("\n");
        }
    }


    /* HINT: WRITE THE PRINT FUNCTION FIRST  */
    return 0;
}
