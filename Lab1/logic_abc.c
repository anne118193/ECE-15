/******************************************************************************
*
* File name: logic_abc.c
*
* Author:  Anne Lin
*          A16290169
*          als006@ucsd.edu
*
*
*     Lab #:1
* Problem #:1
*
* Submission Date: 10/30/2020
*
******************************************************************************/

/*-----------------------------------------------------------------------------
   Include files:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>

/*=============================================================================
  Constants and definitions:
=============================================================================*/

// put your #defines and typedefs here

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here): 
  	Write a C program, called logic abc.c, that prompts the user to enter three integers a, b, c, and then
	computes the results of the following logical operations, in sequence:
			!a || !b++ && c
			(a-1 || b/2) && (c*=2)
			(a-- || --b) && (c+=2)
			a || !(b && --c)

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* 
    Extra Credit 
    three numbers that make all of the results false would be: 
    a=1
    b=-2
    c=-2
    In order for an OR statement to be false, both sides of the statement must be false. 
    For the last statement, "a" must be 0 and !(b&&c) must false. Statement three decrements 
    "a" so we know that a-1=0; and a must be 1. this also works for the first statement because 
    "!a" needs to be false so that the overall statement is false. "b" can only be -1 or -2 in order 
    to make b/2=0 after the b++ in the first statement. We want b/2 to be 0 so that the OR statement
    in the second line is false. In the second statement, as long as (a-1 || b/2) is false, c*=2 can
    be true or false because the && will only evaluate to true if both sides of the && are true.
    Because the first part of the && statement is false, (c*=) will not evaluate so "c" will remain as -2.  
    "c" must be -2 because we need the c+=2 to be equal to 0 in order to make the third statement false. 
    The first part, (a-- || --b), executed to true which mans that c+=2 must be false or have a value of 0
    in order for the whole statement to be false.

*/

int main() 
{
  int a, b, c;

  printf("Enter integers a,b,c: ");
  scanf("%d %d %d", &a, &b, &c);

  (!a || !b++ && c) ? printf("       !a || !b++ && c: True\n") : printf("       !a || !b++ && c: False\n");
  ((a-1 || b/2) && (c*=2)) ? printf("(a-1 || b/2) && (c*=2): True\n") : printf("(a-1 || b/2) && (c*=2): False\n");
  ((a-- || --b) && (c+=2)) ? printf("(a-- || --b) && (c+=2): True\n") : printf("(a-- || --b) && (c+=2): False\n");
  (a || !(b && --c)) ? printf("      a || !(b && --c): True\n") : printf("      a || !(b && --c): False\n");

  return 0;
}


/******************************************************************************
                                End of file
******************************************************************************/
