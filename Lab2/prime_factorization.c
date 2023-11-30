/******************************************************************************
*
* File name: prime_factorization.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:2
* Problem #:2
*
* Submission Date:11/13/2020
*
******************************************************************************/

/*-----------------------------------------------------------------------------
   Include files:
-----------------------------------------------------------------------------*/

#include <stdio.h>

/*=============================================================================
  Constants and definitions:
=============================================================================*/

// put your #defines and typedefs here


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here):
  Write a C program, called prime factorization.c, that prompts the user to enter an integer
and then prints its prime factorization. The program program should keep doing this repeatedly as
long as the user enters an integer greater than 1. If the user enters an integer less than or equal to 1, the
program should simply terminate. If the user enters a non-integer, the program should terminate with
an appropriate error message

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  int num, test_num;

  do
  {
  	printf("Enter an integer: ");
  	scanf(" %d", &num);
  	if(num==1)
		return 0;
	printf("The prime factorization of %d is ", num);

	test_num = num;
	for(int i=2; i<=test_num; )
	{
		if(test_num%i==0)
		{
			printf("%d ", i);
			test_num/=i;
		}
		else
			i++;
	}

  	printf("\n");
  }
  while(num>1);

  return 0;
}



/******************************************************************************
                                End of file
******************************************************************************/