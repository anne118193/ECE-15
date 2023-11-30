/******************************************************************************
*
* File name: dna.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:3
* Problem #:3
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
#define MAX_IN_LENGTH 241
#define OUT_LENGTH 60

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
int read_DNA(char sequence[]);
double compare_DNA(char seq1[], char seq2[], char seq3[], int n);
void print_DNA(char seq1[], char seq2[], char seq3[], int n);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here)
 Your task is to write a C program, called dna.c, that reads three DNA sequences from a file called
dna input.dat and prints the results of a comparison between each pair of sequences to the file
dna output.dat. The input file dna input.dat consists of three lines. Each line is a single sequence of
characters from the set {A, C, G, T}, that appear without spaces in some order, terminated by
the end of line character \n. You can assume that the three lines contain the same number of characters,
and that this number is at most 241 (including the character \n)

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  input=fopen("dna_input.dat","r");
  output = fopen("dna_output.dat", "w");
  char seq1[MAX_IN_LENGTH]={0}, seq2[MAX_IN_LENGTH]={0}, seq3[MAX_IN_LENGTH]={0}, compare[MAX_IN_LENGTH]={0};
  int n1, n2;

  if((input=fopen("dna_input.dat","r"))==NULL)
  {
  	fprintf(output,"Unable to read input file dna_input.dat!\n");
  	return 1;
  }

  n1=read_DNA(seq1);
  n2=read_DNA(seq2);
  read_DNA(seq3);

  fprintf(output,"Comparison between sequence #1 and sequence #2:\n");
  compare_DNA(seq1, seq2, compare, n1);
  print_DNA(seq1, seq2, compare, n1);
  fprintf(output,"Comparison between sequence #1 and sequence #3:\n");
  compare_DNA(seq1, seq3, compare, n1);
  print_DNA(seq1, seq3, compare, n1);
  fprintf(output,"Comparison between sequence #2 and sequence #3:\n");
  compare_DNA(seq2, seq3, compare, n2);
  print_DNA(seq2, seq3, compare, n2); 
  
  fclose(input);
  fclose(output);
  return 0;
}

/*=============================================================================
  Function definitions
=============================================================================*/

// define (implement) all the functions here; document each function
int read_DNA(char sequence[])
{
  for(int i=0; i<MAX_IN_LENGTH; i++)
	{
		fscanf(input, "%c", &sequence[i]);
		if(sequence[i]=='\n')
			return i;
	}
  return 0;
}

double compare_DNA(char seq1[], char seq2[], char seq3[], int n)
{
	int overlap=0;
	double percentage=0.0;

	for(int i=0; i<n; i++)
	{
		if(seq1[i]==seq2[i])
		{
			seq3[i]=seq1[i];
			overlap++;
		}
		else
			seq3[i]=' ';
	}
	percentage=(overlap/(double)n)*100.0;
	return percentage;
}

void print_DNA(char seq1[], char seq2[], char seq3[], int n)
{
	int k=0, h=0, g=0, enter=0;
  while(h<n && k<n && g<n)
    {
      for(int i=0; i<OUT_LENGTH; i++)
      {
          fprintf(output,"%c", seq1[h]);
          h++;
          if(h==n)
            break;
      }
      fprintf(output,"\n");
        for(int i=0; i<OUT_LENGTH; i++)
        {
          fprintf(output,"%c", seq3[g]);
          g++;
          if(g==n)
            break;
        }
        fprintf(output,"\n");
        for(int i=0; i<OUT_LENGTH; i++)
        {
          fprintf(output,"%c", seq2[k]);
          k++;
          if(k==n)
          {
            enter=1;
            break;
          }
        }
        fprintf(output,"\n");
        if(enter==0)
          fprintf(output,"\n");
    }
  fprintf(output,"\n");
  fprintf(output,"The overlap percentage is %.1lf%%\n", compare_DNA(seq1, seq2, seq3, read_DNA(seq1)));
  fprintf(output,"\n");
	/*if(n%OUT_LENGTH==0)
	{
		for(int c=0; c<OUT_LENGTH; c++)
		{
			for(int i=0; i<OUT_LENGTH; i++)
			{
  				fprintf(output,"%c", seq1[h]);
  				h++;
			}
  			fprintf(output,"\n");
  			for(int i=0; i<OUT_LENGTH; i++)
  			{
  				fprintf(output,"%c", seq3[g]);
  				g++;

  			}
  			fprintf(output,"\n");
  			for(int i=0; i<OUT_LENGTH; i++)
  			{
  				fprintf(output,"%c", seq2[k]);
  				k++;
  			}
  			fprintf(output,"\n");
		}
	}*/
		
	/*for(int i=0; i<OUT_LENGTH; i++)
  		fprintf(output,"%c", seq1[i]);
  	fprintf(output,"\n");
  	for(int i=0; i<OUT_LENGTH; i++)
  		fprintf(output,"%c", seq3[i]);
  	fprintf(output,"\n");
  	for(int i=0; i<OUT_LENGTH; i++)
  		fprintf(output,"%c", seq2[i]);
  	fprintf(output,"\n");
  	fprintf(output,"\n");

  	for(int i=OUT_LENGTH; i<n; i++)
  		fprintf(output,"%c", seq1[i]);
  	fprintf(output,"\n");
  	for(int i=OUT_LENGTH; i<n; i++)
  		fprintf(output,"%c", seq3[i]);
  	fprintf(output,"\n");
  	for(int i=OUT_LENGTH; i<n; i++)
  		fprintf(output,"%c", seq2[i]);
  	fprintf(output,"\n");
  	fprintf(output,"\n");*/
}

/******************************************************************************
                                End of file
******************************************************************************/