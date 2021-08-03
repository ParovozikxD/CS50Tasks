/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("You win!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int("");
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int numbers = (d*d);

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //Just fill it up to the last line
            if (i != d - 1)
                board[i][j] = --numbers;          
            
            //For last line 
            else          
                board[d-1][j-1] = numbers--;                          
        }
    }

    //If the dimension is even
    if (d % 2 == 0)
    {
        int temp;
        temp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;
    }
    //init empty cell                 _ -- 95 on ASCII
    board[d-1][d-1] = '_';   
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
     for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] > 9 && board[i][j] != '_')      
                    printf("| %i |", board[i][j]);
                
                else if (board[i][j] == '_')
                    printf("| _  |");
               
                else if (board[i][j] < 10)
                    printf("| %i  |", board[i][j]);
            }
            printf("\n");
        }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int position_i;
    int position_j;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {   
            //remember '_' position 
            if('_' == board[i][j])
            {
               position_i = i;
               position_j = j; 
            }
        }
    }

    for (int i = 0; i < d; i++)
    {
        
        for (int j = 0; j < d; j++)
        {   
            //Swapping places '_' and tile by Game rules
            if(tile == board[i][j] && (('_' == board[i][j+1]) || ('_' == board[i][j-1]) || ('_' == board[i+1][j]) || ('_' == board[i-1][j])) )
            {
                int temp;

                temp = board[i][j];
                board[i][j] = board[position_i][position_j];
                board[position_i][position_j] = temp;
                return true;
            }  
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int j = 0, k = 0;

    int j1 = 0, k1 = 1;

    for (int i = 0; i < d*d-1; i++)
    {   
        if (board[j][k] > board[j1][k1])
        {
            return false;
        } 

        else
        {
            //Move through two-dimensional array
            if (k == d - 1)
            {
                k = 0;
                j++;
            }  

            else
            {
                k++;               
            }

            if (k1 == d - 1)
            {
                k1 = 0;
                j1++;
            }

            else
            {
                k1++;
            } 
        }
    }
    return true;
}