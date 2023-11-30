/******************************************************************************
*
* File name: digits.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:1
* Problem #:2
*
* Submission Date:10/30/2020
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
 	Write a C program, called digits.c, that prompts the user to enter an integer, and then prints out
	its decimal digits, each one on a separate line, starting with the least significant (rightmost) digit. Each
	printed line should indicate which of the digits is being printed. Note that the user can input either a
	positive or a negative integer: the inputs n and −n, where n is an integer, should produce exactly the same
	output.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  int i, num, digit;
  i=1;

  printf("Enter an integer: ");
  scanf("%d", &num);

  if(num<0)
  {
  	num*=-1;
  }

  if(num==0)
  {
  	printf("Digit (1): 0\n");
  }

  while(num!=0)
  {
  	digit=num%10;
  	printf("Digit (%d) : %d\n", i, digit);
  	num/=10;
  	i++;
  }

  return 0;
}


/******************************************************************************
                                End of file
******************************************************************************/

