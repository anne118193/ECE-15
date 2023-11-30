/******************************************************************************
*
* File name: alphabetic_sort.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
* Problem #: 2
*
* Submission Date: 12/19/2020
*
******************************************************************************/


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                              Include Files                                  @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* If you need to use standard library functions other than those declared 
// in <stdio.h>, you may #include the corresponding header files here.*/


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                 Symbolic Constants and Type Definitions                     @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* If you need to define symbolic constants or if you would like to define 
// new types, you may put the corresponding #defines and typedefs here.*/



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                           Global Variables                                  @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* If you would like to use global variables, declare them here.*/
FILE *input=NULL;
FILE *output=NULL;

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                      Forward Function Declarations                          @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* Put forward declarations of all the functions (other than main) here.*/
void swap(char **a, char **b);
void sort(char **words, int num_words);


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function: describe what your program does here.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main(void) 
{
  input=fopen("alphabetic_sort.dat", "r");
  output=fopen("alphabetic_sort.out", "w");
  int num_words, num_letters;
  char *string;
  int i, c, j;

  if((input=fopen("alphabetic_sort.dat","r"))==NULL)
  {
  	fprintf(output,"Unable to read input file alphabetic_sort.dat!\n");
  	return 1;
  }

  fscanf(input, "%d", &num_words);
  char **words = (char**)malloc(num_words * sizeof(char*));
  if(words==NULL)
    exit(1);
  for (i=0; i<num_words; i++) 
  {
  	fscanf(input, "%d", &num_letters);
  	words[i] = (char *)malloc(num_letters * sizeof(char));
    if(words[i]==NULL)
      exit(1);
  	string = (char *)malloc(num_letters * sizeof(char));
    if(string==NULL)
      exit(1);
  	fscanf(input, "%s", string); 
  	for(c=0; c<num_letters; c++)
	  {
		  words[i][c]=string[c];
	  }
    free(string);
  }

  sort(words, num_words);

  for(i=0; i<num_words; i++)
  {
  	fprintf(output, "%s\n", words[i]);
  }
   
  for(j=0; j<num_words; j++)
  {
    free(words[j]);
  }
  free(words);      
  fclose(input);
  fclose(output);
  return 0;
}


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                            Function Definitions                             @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* Define (implement) all the functions here; document each function.*/
void swap(char **a, char **b)
{
	char *temp;
	temp = (char *)malloc(strlen(*a) * sizeof(char));
  if(temp==NULL)
    exit(1);
	strcpy(temp,*a);
  free(*a);
	*a = (char *)malloc(strlen(*b) * sizeof(char));
  if(a==NULL)
    exit(1);
	strcpy(*a,*b);
  free(*b);
	*b = (char *)malloc(strlen(temp) * sizeof(char));
  if(b==NULL)
    exit(1);
	strcpy(*b,temp);
  free(temp);
}

void sort(char **words, int num_words)
{
	int i, last, test;
	for(last=num_words-1; last>0; last--)
	{
		for (i=0; i<last; i++ )
		{
			test=strcmp(words[i], words[i+1]);
			if(test>0)
			{
				swap(&words[i], &words[i+1]);
			}
		}
	}
}
/*sorting algorithm:
1. compare the first 2 elements
2. if element 0 is greater than element 1, swap them
3. then compare element 1 and element 2
4. if element 1 is greater than element 2, swap them
  (continue unti all the elements have been scanned)
 After one pass, the largest element is the last element. 
 Do another pass, but stop one short of the end and continue 
 doing passes until the scanned size is 0. Once all of this is done,
 the largest element (the element closest the end of the alphabet) 
 will be at the end of the array, and the smallest element will be
 at the beginning of the array. */

/******************************************************************************

                                End of file

******************************************************************************/