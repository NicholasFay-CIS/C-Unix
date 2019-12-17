#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOTE:
 * - you may not use atoi
 * - you may not use *any* built-in functions -- strlen, strcpy, etc.
 * - you may assume all integers have <10 digits
 *
 */
typedef struct 
{
	int stack[100];
	int last_index;
}Stack;

void Push(Stack *s, int x)
{
	if(s->last_index > 99)
	{
		printf("ERROR: Index out of range.");
		exit(EXIT_FAILURE);
	} 
	else
	{
		s->last_index++;
		s->stack[s->last_index] = x;
	}
}

void Initialize(Stack *s)
{
	s->last_index = 0;
}

int Pop(Stack *s)
{
	if(s->last_index < 0)
	{
		printf("ERROR: Index out of range");
		exit(EXIT_FAILURE);
	}
	else
	{
		int x = s->stack[s->last_index];
		s->last_index--;
		return x;
	}
}
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
    Stack *s = malloc(sizeof(Stack));
    Initialize(s);
    int final;
    int digit1;
    int digit2;
    int temp;
    int i;
    /* pointer to the Var for first number */
    for(i=1; i<argc; i++)
    {
	    if(*argv[i] == '-')
	    {
		    digit1 = Pop(s);
		    digit2 = Pop(s);
		    final = digit2 - digit1;
		    Push(s, final);
	    }
	    else if(*argv[i] == '+')
	    {
		    digit1 = Pop(s);
		    digit2 = Pop(s);
		    final = digit2 + digit1;
		    Push(s, final);
	    }
	    else if(*argv[i] == 'x')
	    {
		    digit1 = Pop(s);
		    digit2 = Pop(s);
		    final = digit2 * digit1;
		    Push(s, final);
	    }
	    else 
	    {
		   temp = convert(argv[i]);
		   Push(s, temp);
	    }
    }
    int last = Pop(s);
    printf("The total is %d\n", last);
}
