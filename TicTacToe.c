#include <stdio.h>
#include <stdlib.h>
//Playboard 
char playboard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
//Prototypes
void  playerX();
void playerO();
int game();
void reset();
int equalityCheck();
//Main function
int main()
{   
    //Function call for starting the game
    game();
    //Retry decision variable
    char dec;
    //Asking for retrying decision
    printf("Do you want to play again?\nType 1 for yes: ");
    scanf(" %c", &dec);
    if(dec == '1')
    {
        //To reset and replay the game
        reset();
        system("clear");
        game();
    }
    else
        //For ending the program
        exit(0);
}
int game()
{
        //To limit the Turns in the game
        for(int i = 0; i < 9; i++)
    {
        printf("  0 1 2\n0|%c|%c|%c|\n -------\n1|%c|%c|%c|\n -------\n2|%c|%c|%c|\n", playboard[0][0],playboard[0][1],playboard[0][2],playboard[1][0],playboard[1][1], playboard[1][2],playboard[2][0],playboard[2][1],playboard[2][2]);
        //Determining of player turns
        if(i%2 ==  0)
            playerX();
        else
            playerO();
        //To determine the victor or a draw in a case of it
        if(equalityCheck() == 1)
        {
            printf("  0 1 2\n0|%c|%c|%c|\n -------\n1|%c|%c|%c|\n -------\n2|%c|%c|%c|\n", playboard[0][0],playboard[0][1],playboard[0][2],playboard[1][0],playboard[1][1], playboard[1][2],playboard[2][0],playboard[2][1],playboard[2][2]);
            printf("Player X has won.\n");
            return 1;
        }
        else if (equalityCheck() == 0)
        {
            printf("  0 1 2\n0|%c|%c|%c|\n -------\n1|%c|%c|%c|\n -------\n2|%c|%c|%c|\n", playboard[0][0],playboard[0][1],playboard[0][2],playboard[1][0],playboard[1][1], playboard[1][2],playboard[2][0],playboard[2][1],playboard[2][2]);
            printf("Player O has won.\n");
            return 0; 
        }
        else
            printf("Draw\n");
    }
}
//funcitons for player gameplay(Can be merged in a later date)(same goes for  playerO function so I wont be adding comments to it)
void playerX()
{
    int row, column;
    //To tell which player is playing rn
    printf("You are player X.\n");
    //Choices of where the player 
    do
    {
        printf("Pleasee pick where you want to place your X: ");
        scanf("%d %d", &row, &column);
    //If the chosen place is occupied or the given number is negative
    }while((playboard[row][column] == 'x' || playboard[row][column] == 'o') || (row < 0 || column < 0));
    //Changing the playboard according to the instructions given above
    playboard[row][column] = 'x';
    //To make the output prettier 
    system("clear");
}

void playerO()
{
    int row, column;
    printf("You are player O.\n");
    do
    {
        printf("Pleasee pick where you want to place your O: ");
        scanf("%d %d", &row, &column);
    }while((playboard[row][column] == 'x' || playboard[row][column] == 'o') || (row < 0 || column < 0));
    playboard[row][column] = 'o';
    system("clear");
}
//End of player functions
//To check If the winning conditions are satisfied 
int equalityCheck()
{
    if((playboard[0][0] == playboard[1][0] && playboard[0][0] == playboard[2][0] && playboard[0][0] == 'x')||(playboard[0][1] == playboard[1][1] && playboard[0][1] == playboard[2][1] && playboard[0][1] == 'x')||(playboard[0][2] == playboard[1][2] && playboard[0][2] == playboard[2][2] && playboard[0][2] == 'x')||(playboard[0][0] == playboard[0][1] && playboard[0][0] == playboard[0][2] && playboard[0][0] == 'x')||(playboard[1][0] == playboard[1][1] && playboard[1][0] == playboard[1][2] && playboard[1][0] == 'x')||(playboard[2][0] == playboard[2][1] && playboard[2][0] == playboard[2][2] && playboard[2][0] == 'x')||(playboard[0][0] == playboard[1][1] && playboard[0][0] == playboard[2][2] && playboard[0][0] == 'x')||(playboard[0][2] == playboard[1][1] && playboard[0][2] == playboard[2][0] && playboard[0][2] == 'x'))
        return 1;
   else if((playboard[0][0] == playboard[1][0] && playboard[0][0] == playboard[2][0] && playboard[0][0] == 'o')||(playboard[0][1] == playboard[1][1] && playboard[0][1] == playboard[2][1] && playboard[0][1] == 'o')||(playboard[0][2] == playboard[1][2] && playboard[0][2] == playboard[2][2] && playboard[0][2] == 'o')||(playboard[0][0] == playboard[0][1] && playboard[0][0] == playboard[0][2] && playboard[0][0] == 'o')||(playboard[1][0] == playboard[1][1] && playboard[1][0] == playboard[1][2] && playboard[1][0] == 'o')||(playboard[2][0] == playboard[2][1] && playboard[2][0] == playboard[2][2] && playboard[2][0] == 'o')||(playboard[0][0] == playboard[1][1] && playboard[0][0] == playboard[2][2] && playboard[0][0] == 'o')||(playboard[0][2] == playboard[1][1] && playboard[0][2] == playboard[2][0] && playboard[0][2] == 'o'))
         return(0);
      //In the case of a draw
      return (2);
}
//To reset the board to its initial stage 
void reset()
{
    //For resetting rows
    for(int i = 0; i  <= 2; i++)
    {
        //For resetting columns
        for(int k = 0; k <= 2 ;k++)
            playboard[i][k] = ' ';
    }
}