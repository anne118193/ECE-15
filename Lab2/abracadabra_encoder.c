/******************************************************************************
*
* File name: abracadabra_encoder.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:2
* Problem #:3
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
#define KEY_NUM 5
#define WORD_NUM 7

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here):
  Write a C program, called abracadabra encoder.c, that encrypts words in the ABRACADABRA
language. The program should prompt the user to enter a secret key and a word. You can assume that
the secret key will consist of the five characters a,b,c,d,r listed in some order, each appearing exactly
once, with no spaces. The leftmost letter is the first letter of the secret key (hence it should replace
the letter a in your encryption), and so on. The word should be a valid word in the ABRACADABRA
language, consisting of seven letters. If the user enters anything after the seven letters, you should
ignore this input. On the other hand, if the first seven characters typed in by the user do not constitute
a valid word in the ABRACADABRA language, the program should print an appropriate error message
and terminate (remember to verify the success of the input functions scanf() and/or getchar()).
The output of the program should be the encrypted word

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
  char key[KEY_NUM], word[WORD_NUM], encrypted[WORD_NUM];

  printf("Enter key: ");
  for(int i=0; i<KEY_NUM; i++)
  	scanf(" %c", &key[i]);

  printf("Enter word: ");
  for(int i=0; i<WORD_NUM; i++)
  	scanf(" %c", &word[i]);

  for(int i=0; i<WORD_NUM; i++)
  {
  	if(!(word[i] == 'a'|| word[i] == 'b' || word[i] == 'c' || word[i] == 'd' || word[i] == 'r'))
  	{
  		printf("You did not speak in ABRACADABRA to me!\n");
  		return 1;
  	}
  }

  for(int i=0; i<WORD_NUM; i++)
  {
  	 switch (word[i])
  	 {
  	 	case 'a':
  	 	{
  	 		encrypted[i] = key[0];
  	 		break;
  	 	}
  	 	case 'b':
  	 	{
  	 		encrypted[i] = key[1];
  	 		break;
  	 	}
  	 	case 'c':
  	 	{
  	 		encrypted[i] = key[2];
  	 		break;
  	 	}
  	 	case 'd':
  	 	{
  	 		encrypted[i] = key[3];
  	 		break;
  	 	}
  	 	case 'r':
  	 	{
  	 		encrypted[i] = key[4];
  	 		break;
  	 	}
  	 }
  }

  printf("Encrypted word: ");
  for(int i=0; i<WORD_NUM; i++)
  	printf("%c", encrypted[i]);

  printf("\n");
  return 0;
}



/******************************************************************************
                                End of file
******************************************************************************/