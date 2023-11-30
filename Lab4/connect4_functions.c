/******************************************************************************
*
* File name: connect4_functions.c
*
* Author:  Anne Lin
*          A16290169
*          asl006@ucsd.edu
*
*
*     Lab #: 4
* Problem #: 1
*
******************************************************************************/


/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/
#include "connect4_functions.h"

// If you would like to use standard library functions other than those
// declared in <stdio.h>, <stdlib.h>, <time.h>, <stdbool.h> (for which
// the #include directives are already given in connect4_functions.h), 
// you may #include the corresponding header files here.



/*=============================================================================
  Constants and definitions
=============================================================================*/

// If you would like to define constants other than BOARD_SIZE_HORIZ and 
// BOARD_SIZE_VERT, or if you would like to define new types, you may put 
// the corresponding #defines and typedefs here.



/*=============================================================================
  Global variables
=============================================================================*/

// If you would like to use global variables, declare them here.
int random1=1;

/*=============================================================================
  Forward function declarations
=============================================================================*/

// If you would like to use functions other than those already declared in
// connect4_functions.h, put the forward declarations of these functions here.




/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

                Function Definitions of Required Functions

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


/******************************************************************************
*                                                                             *
*                       Function print_welcome()                              *
*                                                                             *
******************************************************************************/
int print_welcome(void)
{
	char yes_no;
	printf("*** Welcome to the Connect Four game!!! ***\n");
	printf("Would you like to make the first move [y/n]: ");
	scanf("%c", &yes_no);
	while(getchar() != '\n'){}
	printf("\n");
	if(yes_no=='n' || yes_no=='N')
		return 2;
	else 
		return 1;

}

/******************************************************************************
*                                                                             *
*                      Function display_board()                               *
*                                                                             *
******************************************************************************/
void display_board(int board[][BOARD_SIZE_VERT])
{
	printf("\n");
	printf("+");
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		printf("---+");
	}
	printf("\n");
	for(int i=0; i<BOARD_SIZE_VERT; i++)
	{
		printf("|");
		for(int c=0; c<BOARD_SIZE_HORIZ; c++)
		{
			if(board[c][i]==0)
				printf(" %c |", ' ');
			else if(board[c][i]==1)
				printf(" %c |", 'X');
			else if(board[c][i]==2)
				printf(" %c |", 'O');
		}
		printf("\n+");
		for(int i=0; i<BOARD_SIZE_HORIZ; i++)
		{
			printf("---+");
		}
		printf("\n");
	}
	printf("  ");
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		if((i+1)==BOARD_SIZE_HORIZ)
			printf("%d  ", i+1);
		else
			printf("%d   ", i+1);
	}
	printf("\n");
	printf("\n");
}

/******************************************************************************
*                                                                             *
*                      Function random_move()                                 *
*                                                                             *
******************************************************************************/
int random_move(int board[][BOARD_SIZE_VERT], int computer_num)
{
	if(random1==1)
	{
		srand(time(0));
		random1++;
	}
	int m;
	m=rand()%(BOARD_SIZE_HORIZ+1);
	while(m==0 || m>7)
		m=rand()%(BOARD_SIZE_HORIZ+1);
	
	while(is_column_full(board, m))
	{
		m=rand()%(BOARD_SIZE_HORIZ+1);
		while(m==0 || m>7)
			m=rand()%(BOARD_SIZE_HORIZ+1);
	}
	update_board(board, m, computer_num);
	return m;
}

/******************************************************************************
*                                                                             *
*                      Function player_move()                                 *
*                                                                             *
******************************************************************************/
int player_move(int board[][BOARD_SIZE_VERT], int player_num)
{
	int m=1, test;
	printf("Please enter your move: ");
	test=scanf("%d", &m);
	while(getchar()!='\n'){}
	
	test1:
	while(m<1 || m>7 || test==0)
	{
		printf("Not a valid move. Enter a column number!\n");
		printf("Please enter your move: ");
		test=scanf("%d", &m);
		while(getchar()!='\n'){}
			//goto test1;
	}

	while(is_column_full(board, m))
	{
		printf("This column is full. Try again!\n");
		printf("Please enter your move: ");
		test=scanf("%d", &m);
		while(getchar()!='\n'){}
			//goto test1;
		if (test==0)
		{
			goto test1;
		}
		if(m<1 || m>7)
			goto test1;
	}
	update_board(board, m, player_num);
	return m;
}

/******************************************************************************
*                                                                             *
*                      Function check_win_or_tie()                            *
*                                                                             *
******************************************************************************/
bool check_win_or_tie(int board[][BOARD_SIZE_VERT], int last_move)
{
	int winner;
	winner=check_winner(board, last_move);
	if(winner==1)
	{
		printf("*****************************\n");
		printf("* Player X won!!! Game over *\n");
		printf("*****************************\n");
		return true;
	}
	else if(winner==2)
	{
		printf("*****************************\n");
		printf("* Player O won!!! Game over *\n");
		printf("*****************************\n");
		return true;
	}
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==0)
				return false;
		}
	}
	printf("*****************************\n");
	printf("* Game is a tie!! No winner *\n");
	printf("*****************************\n");
	return true;
}

/******************************************************************************
*                                                                             *
*                     Function is_column_full()                               *
*                                                                             *
******************************************************************************/
bool is_column_full(int board[][BOARD_SIZE_VERT], int m)
{
	if(board[m-1][0]!=0)
		return 1;
	else if(board[m-1][0]==0)
		return 0;
	return 1;
}

/******************************************************************************
*                                                                             *
*                      Function update_board()                                *
*                                                                             *
******************************************************************************/
void update_board(int board[][BOARD_SIZE_VERT], int m, int player_num)
{
	for(int i=(BOARD_SIZE_VERT-1); i>=0; i--)
	{
		if(board[m-1][i]==0)
		{
			board[m-1][i]=player_num;
			break;
		}
	}
}

/******************************************************************************
*                                                                             *
*                      Function check_winner()                                *
*                                                                             *
******************************************************************************/
int check_winner(int board[][BOARD_SIZE_VERT], int last_move)
{
	//horizontal
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT-3; c++)
		{
			if(board[i][c]==board[i][c+1] && board[i][c+1]==board[i][c+2] && board[i][c+2]==board[i][c+3])
			{
				if(board[i][c]==1)
				{
					return 1;
				}
				else if(board[i][c]==2)
				{
					return 2;
				}
			}
		}
	}

	//vertical
	for(int i=0; i<BOARD_SIZE_VERT; i++)
	{
		for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
		{
			if(board[c][i]==board[c+1][i] && board[c+1][i]==board[c+2][i] && board[c+2][i]==board[c+3][i])
			{
				if(board[c][i]==1)
				{
					return 1;
				}
				else if(board[c][i]==2)
				{
					return 2;
				}
			}
		}
	}

	//diagonal
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
		{
			if(board[i][c]==board[i+1][c-1] && board[i+1][c-1]==board[i+2][c-2] && board[i+2][c-2]==board[i+3][c-3])
			{
				if(board[i][c]==1)
				{
					return 1;
				}
				else if(board[i][c]==2)
				{
					return 2;
				}
			}
		}
	}

	//diagonal 2
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT-3; c++)
		{
			if(board[i][c]==board[i+1][c+1] && board[i+1][c+1]==board[i+2][c+2] && board[i+2][c+2]==board[i+3][c+3])
			{
				if(board[i][c]==1)
				{
					return 1;
				}
				else if(board[i][c]==2)
				{
					return 2;
				}
			}
		}
	}

	return 0;
}

/******************************************************************************
*                                                                             *
*                       Function best_move()                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  This is the EXTRA-CREDIT function to be used for the student competition.  *
*                                                                             *
******************************************************************************/
int best_move(int board[][BOARD_SIZE_VERT], int computer_num)
{
	int num;
	if(computer_num==1)
		num=2;
	else
		num=1;
	int count=0;
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
    	for(int c=0; c<BOARD_SIZE_VERT; c++)
    	{
    		if(board[i][c] != 0)
    			count++;
    	}
    }
   if(count==0)
    {
    	update_board(board, 4, computer_num);
    	return 4;
    }

    //horizontal
    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
    	{
    		if(board[c][i]==board[c+1][i] && board[c+1][i]==board[c+2][i] && board[c+3][i]==0 && board[c][i]==num)
    		{
    			if(board[c+4][i+1]!=0 || i==BOARD_SIZE_VERT-1)
    			{
    				if(!is_column_full(board, c+4))
    				{
    					update_board(board, c+4, computer_num);
    					return c+4;
    				}
    			}
    		}
    	}
    }

    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
    	{
    		if(board[c+1][i]==board[c+2][i] && board[c+2][i]==board[c+3][i] && board[c][i]==0 && board[c+1][i]==num)
    		{
    			if(board[c+1][i+1]!=0 || i==BOARD_SIZE_VERT-1)
    			{
    				if(!is_column_full(board, c+1))
    				{
    					update_board(board, c+1, computer_num);
    					return c+1;
    				}
    			} 
    		}
    	}
    }

	//vertical?
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i][c+1] && board[i][c+1]==board[i][c+2] && board[i][c]==num)
			{
				if(board[i][c+3]==0)
				{	
					if(!is_column_full(board, i+1))
					{
						update_board(board, i+1, computer_num);
						return i+1;
					}
				}
			}
		}
	}

    //vertical?
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
    	for(int c=BOARD_SIZE_VERT-3; c>=0; c--)
    	{
    		if(board[i][c]==board[i][c-1] && board[i][c-1]==board[i][c-2] && board[i][c-3]==0 && board[i][c]==num)
    		{
	    		if(board[i][c-3]==0)
	    		{
	    			if(!is_column_full(board, i+1))
	    			{
	    				update_board(board, i+1, computer_num);
	    				return i+1;
	    			}
	    		}
    		}
    	}
    }

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
		{
			if(board[i][c]==board[i+1][c-1] && board[i+1][c-1]==board[i+2][c-2] && board[i+3][c-3]==0 && board[i][c]==num) 
			{
				if(board[i+4][c-2]!=0 || (c-3)==BOARD_SIZE_VERT-1)
				{
					if(!is_column_full(board, i+4))
					{
						update_board(board, i+4, computer_num);
						return i+4;
					}
				}
			}
		}
	}

	//diagonal 2
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i+1][c+1] && board[i+1][c+1]==board[i+2][c+2] && board[i+3][c+3]==0 && board[i][c]==num)
			{
				if(board[i+4][c+2]!=0 || (c+3)==BOARD_SIZE_VERT-1)
				{
					if(!is_column_full(board, i+4))
					{
						update_board(board, i+4, computer_num);
						return i+4;
					}
				}
			}
		}
	}

	//defense
	//horizontal
	for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-2; c++)
    	{
    		if(board[c][i]==board[c+1][i] && board[c+2][i]==0 && board[c][i]==num)
    		{
	    		if(board[c+3][i-1]!=0 || i==BOARD_SIZE_VERT-1)
	    		{
	    			if(!is_column_full(board, c+3))
	    			{
	    				update_board(board, c+3, computer_num);
	    				return c+3;
	    			}
	    		}
    		}
    	}
    }

    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-2; c++)
    	{
    		if(board[c+1][i]==board[c+2][i] && board[c][i]==0 && board[c+1][i]==num)
    		{
	    		if(board[c+1][i-1]!=0 || i==BOARD_SIZE_VERT-1)
	    		{
	    			if(!is_column_full(board, c+1))
	    			{
	    				update_board(board, c+1, computer_num);
	    				return c+1;
	    			}
	    		} 
    		}
    	}
    }

    //vertical
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i][c+1] && board[i][c]==num)
			{
				if(board[i][c+2]==0)
				{
					if(!is_column_full(board, i+1))
					{
						update_board(board, i+1, computer_num);
						return i+1;
					}
				}
			}
		}
	}

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
		{
			if(board[i][c]==board[i+1][c-1] && board[i+2][c-2]==0 && board[i][c]==num) 
			{
				if(!is_column_full(board, i+3) )//&& board[i+2][c-1]!=0)
				{
					update_board(board, i+3, computer_num);
					return i+3;
				}
			}
		}
	}

	//diagonal 2
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i+1][c+1] && board[i+2][c+2]==0 && board[i][c]==num)
			{
				if(!is_column_full(board, i+3))// && board[i+2][c+3]!=0)
				{
					update_board(board, i+3, computer_num);
					return i+3;
				}
			}
		}
	}

    //hi
    //horizontal
    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
    	{
    		if(board[c][i]==board[c+1][i] && board[c+1][i]==board[c+2][i] && board[c+3][i]==0 && board[c][i]!=0)
    		{
    			if(board[c+4][i+1]!=0 || i==BOARD_SIZE_VERT-1)
    			{
    				if(!is_column_full(board, c+4))
    				{
    					update_board(board, c+4, computer_num);
    					return c+4;
    				}
    			}
    		}
    	}
    }

    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
    	{
    		if(board[c+1][i]==board[c+2][i] && board[c+2][i]==board[c+3][i] && board[c][i]==0 && board[c+1][i]!=0)
    		{
    			if(board[c+1][i+1]!=0 || i==BOARD_SIZE_VERT-1)
    			{
    				if(!is_column_full(board, c+1))
    				{
    					update_board(board, c+1, computer_num);
    					return c+1;
    				}
    			} 
    		}
    	}
    }

	//vertical?
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i][c+1] && board[i][c+1]==board[i][c+2] && board[i][c]!=0)
			{
				if(board[i][c+3]==0)
				{	
					if(!is_column_full(board, i+1))
					{
						update_board(board, i+1, computer_num);
						return i+1;
					}
				}
			}
		}
	}

    //vertical?
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
    	for(int c=BOARD_SIZE_VERT-3; c>=0; c--)
    	{
    		if(board[i][c]==board[i][c-1] && board[i][c-1]==board[i][c-2] && board[i][c-3]==0 && board[i][c]!=0)
    		{
	    		if(board[i][c-3]==0)
	    		{
	    			if(!is_column_full(board, i+1))
	    			{
	    				update_board(board, i+1, computer_num);
	    				return i+1;
	    			}
	    		}
    		}
    	}
    }

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
		{
			if(board[i][c]==board[i+1][c-1] && board[i+1][c-1]==board[i+2][c-2] && board[i+3][c-3]==0 && board[i][c]!=0) 
			{
				//if(board[i+3][c-2]!=0 || (c-3)==BOARD_SIZE_VERT-1)
				{
					if(!is_column_full(board, i+4))
					{
						update_board(board, i+4, computer_num);
						return i+4;
					}
				}
			}
		}
	}

	//diagonal 2
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i+1][c+1] && board[i+1][c+1]==board[i+2][c+2] && board[i+3][c+3]==0 && board[i][c]!=0)
			{
				//if(board[i+3][c+2]!=0 || (c+3)==BOARD_SIZE_VERT-1)
				{
					if(!is_column_full(board, i+4))
					{
						update_board(board, i+4, computer_num);
						return i+4;
					}
				}
			}
		}
	}

	//defense
	//horizontal
	for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-2; c++)
    	{
    		if(board[c][i]==board[c+1][i] && board[c+2][i]==0 && board[c][i]!=0)
    		{
	    		if(board[c+3][i+1]!=0 || i==BOARD_SIZE_VERT-1)
	    		{
	    			if(!is_column_full(board, c+3))
	    			{
	    				update_board(board, c+3, computer_num);
	    				return c+3;
	    			}
	    		}
    		}
    	}
    }

    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
    	for(int c=0; c<BOARD_SIZE_HORIZ-2; c++)
    	{
    		if(board[c+1][i]==board[c+2][i] && board[c][i]==0 && board[c+1][i]!=0)
    		{
	    		if(board[c+1][i+1]!=0 || i==BOARD_SIZE_VERT-1)
	    		{
	    			if(!is_column_full(board, c+1))
	    			{
	    				update_board(board, c+1, computer_num);
	    				return c+1;
	    			}
	    		} 
    		}
    	}
    }

    //vertical
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i][c+1] && board[i][c]!=0)
			{
				if(board[i+1][c+2]==0)
				{
					if(!is_column_full(board, i+1))
					{
						update_board(board, i+1, computer_num);
						return i+1;
					}
				}
			}
		}
	}

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
		{
			if(board[i][c]==board[i+1][c-1] && board[i+2][c-2]==0 && board[i][c]!=0) 
			{
				if(!is_column_full(board, i+2))
				{
					update_board(board, i+2, computer_num);
					return i+2;
				}
			}
		}
	}

	//diagonal 2
	for(int i=0; i<BOARD_SIZE_HORIZ; i++)
	{
		for(int c=0; c<BOARD_SIZE_VERT; c++)
		{
			if(board[i][c]==board[i+1][c+1] && board[i+2][c+2]==0 && board[i][c]!=0)
			{
				if(!is_column_full(board, i+2))
				{
					update_board(board, i+2, computer_num);
					return i+2;
				}
			}
		}
	}
	
	 //win
    //horizontal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT-3; c++)
        {
            if(board[i][c]==board[i][c+1] )
            {
                if(board[i-1][c]!=computer_num|| i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c+2, computer_num);
                    return c+2;
                }
            }
        }
    }

    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT-3; c++)
        {
            if(board[i][c+1]==board[i][c+2])
            {
                if(board[i-1][c]!=computer_num || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }

    //vertical
    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
        for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
        {
            if(board[c+1][i]==board[c+2][i])
            {
                if(board[c+1][i]!=computer_num)
                {
                	update_board(board, i, computer_num);
                    return i;
                }
            }
        }
    }

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
        {
            if(board[i+1][c-1]==board[i+2][c-2])
            {
                if(board[i-1][c]!=0 || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }

    //diagonal 2
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT; c++)
        {
            if(board[i+1][c+1]==board[i+2][c+2])
            {
                if(board[i-1][c] != 0 || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }

    //win1
    //horizontal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT-3; c++)
        {
            if(board[i][c] == computer_num)
            {
                if(board[i-1][c]!=computer_num|| i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c+2, computer_num);
                    return c+2;
                }
            }
        }
    }

    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT-3; c++)
        {
            if(board[i][c+1]==computer_num)
            {
                if(board[i-1][c]!=computer_num || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }

    //vertical
    for(int i=0; i<BOARD_SIZE_VERT; i++)
    {
        for(int c=0; c<BOARD_SIZE_HORIZ-3; c++)
        {
            if(board[c+1][i]==computer_num)
            {
               update_board(board, i, computer_num);
               return i;
            }
        }
    }

    //diagonal
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=BOARD_SIZE_VERT-1; c>=0; c--)
        {
            if(board[i+1][c-1]==computer_num)
            {
                if(board[i-1][c]!=0 || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }

    //diagonal 2
    for(int i=0; i<BOARD_SIZE_HORIZ; i++)
    {
        for(int c=0; c<BOARD_SIZE_VERT; c++)
        {
            if(board[i+1][c+1]==computer_num)
            {
                if(board[i-1][c] != 0 || i==BOARD_SIZE_HORIZ-1)
                {
                	update_board(board, c, computer_num);
                    return c;
                }
            }
        }
    }
	
	if(is_column_full(board, 4))
	{
		return random_move(board, computer_num);
	}
    update_board(board, 4, computer_num);
    return  4;
}

/*=============================================================================
  Function definitions of other functions
=============================================================================*/

// If you would like to use functions other than those declared in
// connect4_functions.h and implemented above, put the definitions
// of these functions here.


/******************************************************************************
                                End of file
******************************************************************************/
