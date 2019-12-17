#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* NOTE:
 * - you may not use atoi
 * - you may not use *any* built-in functions -- strlen, strcpy, etc.
 * - you may assume all integers have <10 digits
 *
 */
int convert(char arr[])
{
	int is_neg = 1; /* var to determine if a num is negative */
	int digit = 0; /* holds the value of the digit being created */
	int index = 0; 
	/*if the number is neg, set is neg to negative one to multiply later*/
	if (arr[0] == '-'){
		is_neg = -1;
		index = 1;
	}
	/* else if it is positive */
	else if(arr[0] == '+')
	{
		index = 1;
		is_neg = 1;

	}
	/*loop through the number each char at a time */	
	for (int i = index; i<=10; i++)
	{
		/*if the char is the null char, break */
		if(arr[i] == '\0')
		{
			break;
		}
		/*else if the char is not the null char, and index is at ten, the string must be too long */
		else if(arr[i] != '\0' && i == 10)
		{
			printf("ERROR: number has 10 or more digits\n");
			exit(EXIT_FAILURE);
		}
		/* if (NOT) the char is not greater than or equal to char of zero and is not less than or equal to char nine, number must be outside poss char */
		if(!(arr[i] >= '0' && arr[i] <= '9')){
			printf("ERROR: number has character that is outside 0-9\n");
			exit(EXIT_FAILURE);
		}
		/* mulitply the last char by ten and then add the value of the next char */	
		digit = digit * 10 + (arr[i] - '0');
	}
	/* returns the digit (non neg or neg) */
	return digit * is_neg;
}
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <integer> <+ or -> <integer>", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* pointer to the Var for first number */
    char *number1 = argv[1]; 
    char *operation = argv[2]; /*pointer to the  Var for the operation */
    char *number2 = argv[3]; /* pointer to the Var for the 2nd number */
    int final; /* var for resulting number */
    int digit1  = convert(number1);
    int digit2 = convert(number2);
    /* First If statement, if there is more than one valid char in the operation then Error. */ 
    /* else if the operation is a plus, add digit1 and digit2 */
    if (operation == "--" || operation == "++" || operation == "+-" || operation == "-+")
    {
	    printf("ERROR: operation may only be + or -");
	    exit(EXIT_FAILURE);
    }
    else if (*operation == '+' && operation[1] == '\0')
    {
	    final = digit1 + digit2;
	    printf("%d\n", final);
	    fflush(stdout);
    }
    /* if the operation is a minus, subtract digit1 and digit2 */
    else if (*operation == '-' && operation[1] == '\0')
    {
	    final = digit1 - digit2;
	    printf("%d\n", final);
	    fflush(stdout);
     }
    /*if it is some other char then it is an error */
    else 
    {
	   printf("ERROR: operation may only be + or -\n");
	   exit(EXIT_FAILURE);
    }
    /* Turn number1 into an integer.  You will need to do this by
     * looking at the character string one character at a time, and multiplying
     * by 10 as you go.
     * For example: if the string is "214", then I would start by finding the
     * '2'.  I would think (for the time being) the number is 2.  When I go
     * to the next character, I would see the "1".  I would then make the 
     * number 21, by multiplying my previous number (2) by 10 and adding the
     * current number (1) ... 2*10+1 = 21.
     * The next number is 4.  Again, take the previous number (21) times 10
     * and add the current number (4).  This makes 214.
     * The next character is the NULL character.  So we are done parsing the
     * string.  And stop at 214.
     * TRICK #1! --->
     *    char digit = '5';
     *    int digit_as_number = digit - '0'; <--- gives you 5.
     * TRICK #2! --->
     *    when you encounter a '\0', then use break to terminate the loop
     *    right then.
     */

    /* Now figure out which operation to do: plus or minus.
     * You will do this by inspecting the variable named "operation". */

    /* Now turn number2 into an integer. */
 
    /* Perform the operation and print the result */
}
