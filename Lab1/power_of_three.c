/******************************************************************************
*
* File name: power_of_three.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:1
* Problem #:3
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

#define BASE 3

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here):
    Write a C program, called power of three.c, that prompts the user to input a 
    positive integer, and then checks whether this integer is a power of 3. If the input is, indeed, equal to 3n 
	for some nonnegative integer n the program should tell the
	user that the input is a power of 3 and print the exponent n. If the input is a positive integer which is not
	a power of 3, the program should print a corresponding message. Finally, if the input is an integer less
	than 1, the program should terminate with an appropriate error message

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  int userNum, num, n, remainder;
  n=0;

  printf("Enter a positive integer: ");
  scanf("%d", &userNum);
  num=userNum;

  if(userNum<=0)
  {
  	printf("Error: invalid integer entered!\n");
  	return 1;
  }

  while(num>1)
  {
  	remainder = num % BASE;
  	if(remainder==0)
  	{
  		num/=BASE;
  		n++;
  	}
  	else 
  	{
  		printf("%d is not a power of %d!\n", userNum, BASE);
  		return 1;
  	}
  }

  printf("%d is a power of %d, exponent = %d\n", userNum, BASE, n);

  return 0;
}


/******************************************************************************
                                End of file
******************************************************************************/

