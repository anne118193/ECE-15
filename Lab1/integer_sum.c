/******************************************************************************
*
* File name: integer_sum.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:1
* Problem #:4
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
  	Write a C program, called integer sum.c, that computes the sum of integers interactively provided
	by the user. At each iteration, the program should print the number of integers that the user has entered
	so far, along with a menu describing three possible actions from which the user could choose. The three
	possible actions are as follows:
				1. Entering a new integer
				2. Printing the sum of all the integers entered so far
				3. Exiting the program
	If the user enters a number other than 1, 2, or 3 when presented with this menu, the program should
	simply print the same menu again, prompting the user to enter a new choice of action. You are not required to introduce the constants 1, 2, and 3 into the program using #define, although you can do so.
	You can assume that when the user is prompted to enter an integer, the user indeed enters an integer.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main()
{
	int num, sum, choice, totalNum;
	choice = 0; 
	totalNum = 0; 
	sum = 0;
	num=0;

	printf("Welcome to the integer sum program!\n");

	while (choice != 3)
	{
		printf("So far, you have entered %d numbers. You may: \n", totalNum);
		printf("1. Enter a new integer\n");
		printf("2. Display the current sum\n");
		printf("3. Exit\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			{
				printf("Enter the new integer: ");
				scanf("%d", &num);
				sum+=num;
				totalNum++;
				break;
			}
			case 2:
			{
				printf("The current sum is: %d\n", sum);
				break;
			}
		}
	}

	return 0;
}




/******************************************************************************
                                End of file
******************************************************************************/

