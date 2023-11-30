/******************************************************************************
*
* File name: hopscotch.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
* Problem #: 3
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

/* If you need to use standard library functions other than those declared 
// in <stdio.h>, you may #include the corresponding header files here.*/



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                 Symbolic Constants and Type Definitions                     @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/* If you need to define symbolic constants or if you would like to define 
// new types, you may put the corresponding #defines and typedefs here.*/
#define NUM_COLMNS 3


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
void get_marbles(int **marbles, int num_rows);
int max_marbles(int **marbles, int **total_marbles, int num_rows);
void get_path(int **total_marbles, char *path, int num_rows);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function: describe what your program does here.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main(void) 
{
  input=fopen("hopscotch.dat", "r");
  output=fopen("hopscotch.out", "w");
  int num_rows, max;

  if((input=fopen("hopscotch.dat","r"))==NULL)
  {
  	fprintf(output,"Unable to read input file hopscotch.dat!\n");
  	return 1;
  }

  fscanf(input, "%d", &num_rows);
  //make array for # of marbles from input 
  int **marbles = (int **)malloc(num_rows * sizeof(int *)); 
  if(marbles==NULL)
  	exit(1);  
  for (int i=0; i<num_rows; i++) 
  {
  	marbles[i] = (int *)malloc(NUM_COLMNS * sizeof(int)); 
  	if(marbles[i]==NULL)
  		exit(1);
  }
  //make array for calculating total marbles for each square 
  int **total_marbles = (int **)malloc(num_rows * sizeof(int *)); 
  if(total_marbles==NULL)
  	exit(1); 
  for (int i=0; i<num_rows; i++) 
  {
  	total_marbles[i] = (int *)malloc(NUM_COLMNS * sizeof(int));
  	if(total_marbles[i]==NULL)
  		exit(1);
  } 
  //make array for storing the path
  char *path = (char *)malloc((num_rows+1) * sizeof(char )); 
  if(path==NULL)
  	exit(1); 

  get_marbles(marbles, num_rows);
  max = max_marbles(marbles, total_marbles, num_rows);
  get_path(total_marbles, path, num_rows);

  fprintf(output, "Maximum possible score: %d\n", max);
  fprintf(output, "A path that achieves this score: ");
  for(int i=num_rows; i>=0; i--)
  {
  	fprintf(output, "%c", path[i]);
  }
  fprintf(output, "\n");

  for(int i=0; i<num_rows; i++)
  {
  	free(marbles[i]);
  	free(total_marbles[i]);
  }
  free(marbles);
  free(total_marbles);
  free(path);
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
void get_marbles(int **marbles, int num_rows)
{
	for(int i=0; i<num_rows; i++)
	{
		for(int c=0; c<NUM_COLMNS; c++)
		{
			fscanf(input, "%d", &marbles[i][c]);
		}
	}
}

int max_marbles(int **marbles, int **total_marbles, int num_rows)
{
	int max;

	for(int i=0; i<NUM_COLMNS; i++)
	{
		total_marbles[0][i]=marbles[0][i];
	}
	for(int i=1; i<num_rows; i++)
	{
		//left
		if(total_marbles[i-1][0] > total_marbles[i-1][1])
			total_marbles[i][0] = (total_marbles[i-1][0]+marbles[i][0]);
		else
			total_marbles[i][0] = (total_marbles[i-1][1]+marbles[i][0]);
		//middle
		if(total_marbles[i-1][0] > total_marbles[i-1][1])
		{
			if(total_marbles[i-1][0]+marbles[i][1] > total_marbles[i-1][2]+marbles[i][1])
				total_marbles[i][1] = (total_marbles[i-1][0]+marbles[i][1]);
		}
		if(total_marbles[i-1][1] > total_marbles[i-1][0])
		{
			if(total_marbles[i-1][1] > total_marbles[i-1][2])
				total_marbles[i][1] = (total_marbles[i-1][1]+marbles[i][1]);
		}
		if(total_marbles[i-1][2] > total_marbles[i-1][0])
		{
			if(total_marbles[i-1][2] > total_marbles[i-1][1])
				total_marbles[i][1] = (total_marbles[i-1][2]+marbles[i][1]);
		}
		//right
		if(total_marbles[i-1][1] > total_marbles[i-1][2])
			total_marbles[i][2] = (total_marbles[i-1][1]+marbles[i][2]);
		else
			total_marbles[i][2] = (total_marbles[i-1][2]+marbles[i][2]);
	}
	//compare
	if(total_marbles[num_rows-1][0]>total_marbles[num_rows-1][1] && total_marbles[num_rows-1][0]>total_marbles[num_rows-1][2])
	{
		max=total_marbles[num_rows-1][0];
	}
	else if(total_marbles[num_rows-1][1]>total_marbles[num_rows-1][0] && total_marbles[num_rows-1][1]>total_marbles[num_rows-1][2])
	{
		max=total_marbles[num_rows-1][1];
	}
	else if(total_marbles[num_rows-1][2]>total_marbles[num_rows-1][0] && total_marbles[num_rows-1][2]>total_marbles[num_rows-1][1])
	{
		max=total_marbles[num_rows-1][2];
	}
	return max;
}

void get_path(int **total_marbles, char *path, int num_rows)
{
	int which_column;
	if(total_marbles[num_rows-1][0] > total_marbles[num_rows-1][1] && total_marbles[num_rows-1][0] > total_marbles[num_rows-1][2])
		{
			path[0]='R';
			which_column=1;
		}
		else if(total_marbles[num_rows-1][1] > total_marbles[num_rows-1][0] && total_marbles[num_rows-1][1] > total_marbles[num_rows-1][2])
		{
			path[0]='D';
			which_column=2;
		}
		else
		{
			path[0]='L';
			which_column=3;
		}
	for(int i=num_rows-2, c=1; i>=0; i--,c++)
	{
		if(which_column==1)
		{
			if(total_marbles[i][0] > total_marbles[i][1])
			{
				path[c]='D';
				which_column=1;
			}
			else
			{
				path[c]='L';
				which_column=2;
			}
		}
		else if(which_column==2)
		{
			if(total_marbles[i][0]>total_marbles[i][1] && total_marbles[i][0]>total_marbles[i][2])
			{
				path[c]='R';
				which_column=1;
			}
			else if(total_marbles[i][1]>total_marbles[i][0] && total_marbles[i][1]>total_marbles[i][2])
			{
				path[c]='D';
				which_column=2;
			}
			else
			{
				path[c]='L';
				which_column=3;
			}
		}
		else
		{
			if(total_marbles[i][1]>total_marbles[i][2])
			{
				path[c]='R';
				which_column=2;
			}
			else
			{
				path[c]='D';
				which_column=3;
			}
		}
	}
	
	if(which_column==2)
		path[num_rows]='D';
	else if(which_column==1)
		path[num_rows]='L';
	else
		path[num_rows]='R';

}
/******************************************************************************

                                End of file

******************************************************************************/