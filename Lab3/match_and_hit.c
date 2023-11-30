/******************************************************************************
*
* File name: match_and_hit.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:3
* Problem #:2
*
* Submission Date:11/27/2020
*
******************************************************************************/

/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*=============================================================================
  Constants and definitions
=============================================================================*/

// put all #defines and typedefs (if any) here
#define MAX_QURIES 12
#define N_DIGITS 4

/*=============================================================================
  Global variables
=============================================================================*/

// define/declare all global variables (if any) here

/*=============================================================================
  Forward function declarations
=============================================================================*/

// put forward declarations of all functions here
int isvalid(int n);
int choose_N();
int matches(int N, int M);
int hits(int N, int M);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here)
 Write a C program, called match and hit.c, that implements(the computer part of) the Match & Hit
game. In this program, you are required to declare, define, and call the following functions:

The function isvalid(int n) that accepts as a parameter an arbitrary integer. The function
should return 1 if the integer is valid, and 0 otherwise. Recall that an integer is valid if it is 
positive, consists of exactly 4 decimal digits, and all these digits are nonzero and distinct.

The function choose N(void) that returns, as an int, a uniformly random choice of a valid
integer N. The function should call both the rand library function and the function isvalid.
It should keep calling rand until the number generated thereby is valid. Recall that before the
function rand is invoked, the random seed should be initialized using srand(time(0)).
3

The function matches(int N, int M) that accepts as parameters two integers N and M
and returns, as an int, the number of matches. You can assume than both N and M are valid.
I The function hits(int N, int M) that accepts as parameters two integers N and M, then
returns, as an int, the number of hits. You can assume than both N and M are valid

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  srand(time(0));
  int query=0, randomNum, test;
  randomNum=choose_N();

  printf("***Welcome to the MATCH and HIT game***\n");
  printf("The computer has selected a %d-digit number.\n", N_DIGITS);
  printf("Try to deduce it in %d rounds of queries.\n", MAX_QURIES); 

  for(int i=0; i<MAX_QURIES; i++)
  {
  	printf("Round #%d\n", i+1);
  	printf("Please enter your query (%d digits): ", N_DIGITS);
  	test=scanf("%d", &query);
  	while(getchar() != '\n'){}
  	
  	while(!(isvalid(query)) || test==0)
  	{
  		printf("Invalid number. Please try again!\n");
  		printf("Please enter your query (%d digits): ", N_DIGITS);
  		test = scanf("%d", &query);
  		while(getchar() != '\n'){}
  	}

  	if(matches(randomNum, query)==1)
  	{
  		if(hits(randomNum, query)==1)
  			printf("-> %d match and %d hit\n", matches(randomNum, query), hits(randomNum, query));
  		else
  			printf("-> %d match and %d hits\n", matches(randomNum, query), hits(randomNum, query));
  	} 
  	else
  	{
  		if(hits(randomNum, query)==1)
  			printf("-> %d matches and %d hit\n", matches(randomNum, query), hits(randomNum, query));
  		else
  			printf("-> %d matches and %d hits\n", matches(randomNum, query), hits(randomNum, query));
  	}

  	if(matches(randomNum, query)==4)
  	{
  		printf("**********************************\n");
  		printf("CONGRATULATIONS! You won the game!\n");
  		printf("**********************************\n");
  		return 0;
  	}
  }
  
  printf("*********************************\n");
  printf("Sorry, out of queries. Game over!\n");
  printf("*********************************\n");

  return 0;
}

/*=============================================================================
  Function definitions
=============================================================================*/

// define (implement) all the functions here; document each function
int isvalid(int n)
{
	int valid=1;
	int test=1, k=1;
	int a[N_DIGITS];

	for(int i=0; i<N_DIGITS; i++, k*=10)
	{
		test*=k;
	}

	if(n<=0)
		return 0;
	else if(n>k)
		return 0;
	else if(n<(k/10))
		return 0;
	
	k/=10;
	for(int i=0; i<N_DIGITS; i++, k/=10)
	{
		if(k==0)
		{
			a[i]=n;
			break;
		}
		a[i]=n/k;	
		n%=k;
	}
	
	for(int i=0; i<N_DIGITS; i++)
	{
		if(a[i]==0)
			return 0;
	}
	for(int i=0; i<N_DIGITS; i++)
	{
		for(int c=0; c<N_DIGITS; c++)
		{
			if(i==c)
				break;
			else if(a[i]==a[c])
				return 0;
		}
	}

	return valid;
}

int choose_N()
{
	int num;
	
	do
	{
		num=rand();
	}
	while(!isvalid(num));
	return num;
}

int matches(int N, int M)
{
	
	int a[N_DIGITS], b[N_DIGITS];
	int matches=0;
	int k=1, k1=1, test=1;

	for(int i=0; i<N_DIGITS; i++, k*=10, k1*=10)
	{
		test*=k;
	}
	k/=10;
	k1/=10;
	for(int i=0; i<N_DIGITS; i++, k/=10)
	{
		if(k==0)
		{
			a[i]=N;
			break;
		}
		a[i]=N/k;	
		N%=k;
	}
	
	for(int i=0; i<N_DIGITS; i++, k1/=10)
	{
		if(k1==0)
		{
			b[i]=M;
			break;
		}
		b[i]=M/k1;	
		M%=k1;
	}
	
	
	for(int i=0; i<N_DIGITS; i++)
	{
		if(a[i]==b[i])
			matches++;
	}

	return matches;
}

int hits(int N, int M)
{
	
	int hits=0;
	int a[N_DIGITS], b[N_DIGITS];
	int k=1, k1=1, test=1;

	for(int i=0; i<N_DIGITS; i++, k*=10, k1*=10)
	{
		test*=k;
	}
	k/=10;
	k1/=10;
	for(int i=0; i<N_DIGITS; i++, k/=10)
	{
		if(k==0)
		{
			a[i]=N;
			break;
		}
		a[i]=N/k;	
		N%=k;
	}
	for(int i=0; i<N_DIGITS; i++, k1/=10)
	{
		if(k1==0)
		{
			b[i]=M;
			break;
		}
		b[i]=M/k1;	
		M%=k1;
	}

	for(int i=0; i<N_DIGITS; i++)
	{
		for(int c=0; c<N_DIGITS; c++)
		{
			if(i==c)
				{}
			else if(a[i]==b[c])
				hits++;
		}
	}

	return hits;
}

/******************************************************************************
                                End of file
******************************************************************************/