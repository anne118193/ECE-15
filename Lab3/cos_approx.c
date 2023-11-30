/******************************************************************************
*
* File name: cos_approx.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:3
* Problem #:1
*
* Submission Date:11/27/2020
*
******************************************************************************/

/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/

#include <stdio.h>

/*=============================================================================
  Constants and definitions
=============================================================================*/

// put all #defines and typedefs (if any) here

/*=============================================================================
  Global variables
=============================================================================*/

// define/declare all global variables (if any) here
FILE *input=NULL;
FILE *output=NULL;

/*=============================================================================
  Forward function declarations
=============================================================================*/

// put forward declarations of all functions here
int factorial(int n);
double power(double x, int n);
double cos_N(double x, int N);
double cos_delta(double x, double delta);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here)
Your program should read its input from a file called cos input.dat. The first line in this file is
a positive integer m (you can assume that m 6 64). The first line isfollowed by m other lines; each such
line constitutes a test case. Every test-case line contains three numbers separated by whitespace. The
first number is either 1 or 2, indicating whether you should use cos N or cos delta. The second
number is the value of x for which you should compute cos(x). The third number y is either the required 
precision δ (if the first number is 2) or the required number of terms N (if the first number is 1).
In the former case, y will be a floating-point number while in the latter case, it will be an integer. In
both cases, you can assume that y is positive

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  int numCases=0, case_type, n;
  double x, delta;

  input=fopen("cos_input.dat","r");
  output = fopen("cos_output.dat", "w");
  if((input=fopen("cos_input.dat","r"))==NULL)
  {
  	fprintf(output,"Unable to read input file cos_input.dat!\n");
  	return 1;
  }

  fscanf(input, "%d", &numCases);
  for(int i=0; i<numCases; i++)
  {
  	fprintf(output,"Case %d: ", i+1);
  	fscanf(input, " %d", &case_type);

  	if(case_type==1)
  	{
  		fscanf(input, " %lf %d ", &x, &n);
  		fprintf(output,"cos(%.3lf) = %.12lf\n", x, cos_N(x,n));
  	}
  	else  if(case_type==2)
  	{
  		fscanf(input, " %lf %lf", &x, &delta);
  		fprintf(output,"cos(%.3lf) = %.12lf\n", x, cos_delta(x,delta));
  	}
  	else
  	{
  		fprintf(output,"Invalid case number\n");
  		return 1;
  	}
  }
  fclose(input);
  fclose(output);
  return 0;
}

/*=============================================================================
  Function definitions
=============================================================================*/

// define (implement) all the functions here; document each function
int factorial(int n)
{
	int fact=1;
	if (n==0)
		fact=1;

	for(int i=2; i<=n; i++)
		{
			fact*=i;
		}
	return fact;
}

double power(double x, int n)
{
	double power=1.0;
	if (n==0)
		return 1.0;

	for(int i=0; i<n; i++)
		{
			power*=x;
		}
	return power;
}

double cos_N(double x, int n)
{
	double sum=0.0, top=1.0, bottom=1.0, pos_neg=1.0;

	//if(n==1)
		//return sum;

	for(int c=0; c<n; c++)
	{
		bottom=factorial(c*2);
		top=power(x, c*2);
		pos_neg=power(-1, c);
		top*=pos_neg;
		sum+=(top/bottom);
		/*if(c%2==0)
			sum+=(top/bottom);
		else
			sum-=(top/bottom);*/
	}

	return sum;
}

double cos_delta(double x, double delta)
{
	double sum1, sum2, totalSum=1.0, difference=1.0;
	int n=1;

	
	do
	{
		sum1=cos_N(x, n);
		sum2=cos_N(x,n-1);
		//sum1 += power(-1,i)*power(x,2*i)/factorial(2*i);
		//sum2 += power(-1,(i+1))*power(x,2*(i+1))/factorial(2*(i+1));
		n++;
		difference = sum1-sum2;
		if(difference<0)
			difference*=-1;

	}
	while(difference>=delta);
	
	totalSum = cos_N(x,n-1);

	return totalSum;
}

/******************************************************************************
                                End of file
******************************************************************************/