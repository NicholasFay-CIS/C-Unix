#include <stdio.h>
int main()
{
	int prime; //Variable for possible prime number.
	int divisor; // Variable for the divisor.
	//For loop, iterates from five to one hundred.
	for(prime=5; prime<=100; prime++)
	{
		//end_loop variable to exit non prime if statement.
		int end_loop = 0;
		//For loop, iterates from two up until the possible #.
		for(divisor=2; divisor<=prime; divisor++)
		{
			//If there is no remainder.
			if(prime%divisor == 0)
			{
				//increment end_loop by one.
				end_loop++;
				//if the end_loop>zero, exit if.
				if(end_loop>0)
				{
					end_loop--;
					break;
				}
			}
		}
		//If the prime equals the divisor, number is prime.
		if(prime==divisor)
		{
			//prints the number that is prime.
			printf("%d is a prime number\n", prime);
		}
	}
}

