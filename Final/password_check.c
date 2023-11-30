/******************************************************************************
*
* File name: password_check.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
* Problem #: 1
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
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// If you need to use standard library functions other than those declared 
// in <stdio.h>, you may #include the corresponding header files here.


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                 Symbolic Constants and Type Definitions                     @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

// If you need to define symbolic constants or if you would like to define 
// new types, you may put the corresponding #defines and typedefs here.
#define NUM_RULES 6
#define MAX_LETTERS 42


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                           Global Variables                                  @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

// If you would like to use global variables, declare them here.
FILE *input=NULL;
FILE *output=NULL;

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                      Forward Function Declarations                          @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

// Put forward declarations of all the functions (other than main) here.
void get_password(char *password);
bool is_END(char *password);
int last_rule(int *rules);
bool rule1(char *password, int *rules);
bool rule2(char *password, int *rules);
bool rule3(char *password, int *rules);
bool rule4(char *password, int *rules);
bool rule5(char *password, int *rules);
bool rule6(char *password, int *rules);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function: describe what your program does here.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main(void) 
{
  input=fopen("passwords.dat", "r");
  output=fopen("passwords.out", "w");
  char *password;
  int rules[NUM_RULES]={0};
  int violations;

  if((input=fopen("passwords.dat","r"))==NULL)
  {
  	fprintf(output,"Unable to read input file passwords.dat!\n");
  	return 1;
  }

  password = (char *)malloc(MAX_LETTERS * sizeof(char));
  if(password==NULL)
  	exit(1);

  do
  {
  	for(int i=0; i<NUM_RULES; i++)
  	{
  		rules[i]=0;
  	}
  	violations=0;
  	get_password(password);

  	if(is_END(password))
  		return 0;
  	
  	rule1(password, rules);
  	rule2(password, rules);
  	rule3(password, rules);
  	rule4(password, rules);
  	rule5(password, rules);
  	rule6(password, rules);

  	for(int i=0; i<strlen(password); i++)
  	{
  		fprintf(output, "%c", password[i]);
  	}

  	for(int i=0; i<NUM_RULES; i++)
  	{
  		if(rules[i]!=0)
  			violations++;
  	}
  	if(violations==0)
  	{
  		fprintf(output, " is acceptable.\n");
  	}
  	else if(violations>1)
  	{
  		fprintf(output, " is not acceptable. Rules");
  		for(int i=0; i<NUM_RULES; i++)
  		{
  			if(rules[i]!=0)
  			{
  				if(last_rule(rules)==i)
  					fprintf(output, " %d", rules[i]);
  				else
  					fprintf(output, " %d,",rules[i]);
  			}
  		}
  		fprintf(output, " violated.\n");
  	}
  	else
  	{
  		fprintf(output, "  is not acceptable. Rule");
  		for(int i=0; i<NUM_RULES; i++)
  		{
  			if(rules[i]!=0)
  			{
  				fprintf(output, " %d", rules[i]);
  			}
  		}
  		fprintf(output, " violated.\n");
  	}
  }
  while(!is_END(password));

  free(password);
  fclose(input);
  fclose(output);
  return 0;
}


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                            Function Definitions                             @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

// Define (implement) all the functions here; document each function.
void get_password(char *password)
{
	fscanf(input, "%s", password);
}

bool is_END(char *password)
{
	if(password[0]=='E' && password[1]=='N' && password[2]=='D')
		return 1;

	return 0;
}

int last_rule(int *rules)
{
	for(int i=NUM_RULES-1; i>=0; i--)
	{
		if(rules[i]!=0)
			return i;
	}
	return 0;
}

bool rule1(char *password, int *rules)
{
	if(strlen(password)>4)
	{
		return 0;
	}
	else
	{
		rules[0]=1;
		return 1;
	}
}

bool rule2(char *password, int *rules)
{
	int lowercase=0;
	int uppercase=0;
	int number=0;
	int special=0;
	int sum=0;

	for(int i=0; i<strlen(password); i++)
	{
		if(password[i]>='a' && password[i]<='z')
		{
			lowercase=1;
		}
		else if(password[i]>='A' && password[i]<='Z')
		{
			uppercase=1;
		}
		else if(password[i]>='0' && password[i]<='9')
		{
			number=1;
		}
		else if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='&' || password[i]=='*')
		{
			special=1;
		}
	}

	sum = lowercase + uppercase + number + special;
	if(sum==3 || sum==4)
	{
		return 0;
	}
	else
	{
		rules[1]=2;
		return 1;
	}
}

bool rule3(char *password, int *rules)
{
	for(int i=0; i<strlen(password); i++)
	{
		if(password[i]>='a' && password[i]<='z')
		{
		
		}
		else if(password[i]>='A' && password[i]<='Z')
		{
			
		}
		else if(password[i]>='0' && password[i]<='9')
		{
			
		}
		else if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='&' || password[i]=='*')
		{
			
		}
		else 
		{
			rules[2]=3;
			return 1;
		}
		
	}
	return 0;
}

bool rule4(char *password, int *rules)
{
	for(int i=0; i<strlen(password)-1; i++)
	{
		if(password[i]==password[i+1])
		{
			if(password[i]=='e' || password[i]=='E' || password[i]=='o' || password[i]=='O' || password[i]=='0' || password[i]=='3')
			{
				return 0;
			}
			else
			{
				rules[3]=4;
				return 1;
			}
		}
	}
	return 0;
}

bool rule5(char *password, int *rules)
{
	int vowels=0;

	for(int i=0; i<strlen(password); i++)
	{
		if(password[i]=='a' || password[i]=='e' || password[i]=='i' || password[i]=='o' || password[i]=='u')
		{
			vowels++;
		}
		else if(password[i]=='A' || password[i]=='E' || password[i]=='I' || password[i]=='O' || password[i]=='U')
		{
			vowels++;
		} 
		else if(password[i]=='0' || password[i]=='1' || password[i]=='3' || password[i]=='!' || password[i]=='@')
		{
			vowels++;
		}
	}

	if(vowels>1)
	{
		return 0;
	}
	else
	{
		rules[4]=5;
		return 1;
	}
}

bool rule6(char *password, int *rules)
{
	int vowel=1;
	int other=2;
	int not_allowed=3;
	int test[strlen(password)]; 

	for(int i=0; i<strlen(password); i++)
	{
		if(password[i]=='a' || password[i]=='e' || password[i]=='i' || password[i]=='o' || password[i]=='u')
		{
			test[i]=vowel;
		}
		else if(password[i]=='A' || password[i]=='E' || password[i]=='I' || password[i]=='O' || password[i]=='U')
		{
			test[i]=vowel;
		} 
		else if(password[i]=='0' || password[i]=='1' || password[i]=='3' || password[i]=='!' || password[i]=='@')
		{
			test[i]=vowel;
		}
		else if(password[i]>='a' && password[i]<='z')
		{
			test[i]=other;
		}
		else if(password[i]>='A' && password[i]<='Z')
		{
			test[i]=other;
		}
		else if(password[i]>='0' && password[i]<='9')
		{
			test[i]=other;
		}
		else if(password[i]=='#' || password[i]=='$' || password[i]=='&' || password[i]=='*')
		{
			test[i]=other;
		}
		else
		{
			test[i]=not_allowed;
		}
	}

	for(int i=0; i<strlen(password)-2; i++)
	{
		if(test[i]==test[i+1] && test[i+1]==test[i+2] && test[i]!=not_allowed)
		{
			rules[5]=6;
			return 1;
		}
	}
	return 0;
}

/******************************************************************************

                                End of file

******************************************************************************/