/******************************************************************************
*
* File name: write_encoder.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #:2
* Problem #:4
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


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  The main function (describe what your program does here):
  The program requested in the previous problem assumes that a word has exactly seven letters. However,
in reality, words in the ABRACADABRA language may have arbitrary length. Thus it would be nice to
modify this program so that it can support words of arbitrary length. Moreover, most ABRACADABRA
speakers have not taken ECE15 and cannot write C code themselves. Therefore, you are requested to
write a C program, called write encoder.c, that creates by itself the abracadbra encoder
program for any given word length. Your program should prompt the user for the desired word length,
and then output a C code of the abracadbra encoder program for the specified length.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main() 
{
	int word_num;
	printf("Enter the desired word length: ");
	scanf(" %d", &word_num);

	printf("#include <stdio.h>\n\n");
	printf("#define KEY_NUM 5\n\n");
	printf("int main()\n");
	printf("{\n");
	printf(" int word_num, i=0;\n");

	printf(" word_num = %d;\n", word_num);

	printf(" char key[KEY_NUM], word[word_num], encrypted[word_num];\n\n");
	printf(" printf(\"Enter key: \");\n");
	printf(" for(i=0; i<KEY_NUM; i++)\n");
	printf("	scanf(\" %%c\", &key[i]);\n\n");
	printf(" printf(\"Enter word: \");\n");
	printf(" for(i=0; i<word_num; i++)\n");
	printf("	scanf(\" %%c\", &word[i]);\n\n");
	printf(" for(i=0; i<word_num; i++)\n");
	printf(" {\n");
	printf("	if(!(word[i] == 'a'|| word[i] == 'b' || word[i] == 'c' || word[i] == 'd' || word[i] == 'r'))\n");
	printf("	{\n");
	printf("		printf(\"You did not speak in ABRACADABRA to me!\\n\");\n");
	printf("		return 1;\n");
	printf("	}\n");
	printf(" }\n\n");
	printf(" for(i=0; i<word_num; i++)\n");
	printf(" {\n");
	printf("	switch (word[i])\n");
	printf("	{\n");
	printf("		case 'a':\n");
	printf("		{\n");
	printf("			encrypted[i] = key[0];\n");
	printf("			break;\n");
	printf("		}\n");
	printf("		case 'b':\n");
	printf("		{\n");
	printf("			encrypted[i] = key[1];\n");
	printf("			break;\n");
	printf("		}\n");
	printf("		case 'c':\n");
	printf("		{\n");
	printf("			encrypted[i] = key[2];\n");
	printf("			break;\n");
	printf("		}\n");
	printf("		case 'd':\n");
	printf("		{\n");
	printf("			encrypted[i] = key[3];\n");
	printf("			break;\n");
	printf("		}\n");
	printf("		case 'r':\n");
	printf("		{\n");
	printf("			encrypted[i] = key[4];\n");
	printf("			break;\n");
	printf("		}\n");
	printf("	}\n");
	printf(" }\n\n");
	printf(" printf(\"Encrypted word: \");\n");
	printf(" for(i=0; i<word_num; i++)\n");
	printf("	printf(\"%%c\", encrypted[i]);\n\n");
	printf(" printf(\"\\n\");\n");
	printf(" return 0;\n");
	printf("}\n");

  return 0;
}



/******************************************************************************
                                End of file
******************************************************************************/