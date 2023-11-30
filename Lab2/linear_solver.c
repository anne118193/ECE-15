/******************************************************************************
*
* File name: linear_solver.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:2
* Problem #:1
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
#define SPECIAL_CHARACTER 'Y'

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here):
  Write a C program, called linear solver.c, that solves single-variable linear equations. 
  The program should prompt the user to enter a linear equation of the form
							aY + b = c
  where a, b, and c are real numbers of type double. The program should then output the value of Y
  that solves the equation, if such a value exists (see the note about verifying that a in nonzero). If the
  input provided by the user is not valid, the program should terminate with an appropriate error message.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  double a=0, b=0, c=0, y=0;
  char special_char, add_sign, equal_sign;

  printf("Enter a linear equation:   ");
  scanf("%lf%c %c %lf %c %lf", &a, &special_char, &add_sign, &b, &equal_sign, &c);
  
  if(a==0)
  {
  	printf("Invalid equation!\n");
  	return 1;
  }
  else if(special_char != SPECIAL_CHARACTER || add_sign != '+' || equal_sign != '=')
  {
  	printf("Invalid input!\n");
  	return 1;
  }
 
  	y=(c-b)/a;
  	printf("%c = %.3f\n", SPECIAL_CHARACTER, y);
  
  return 0;
}



/******************************************************************************
                                End of file
******************************************************************************/