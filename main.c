#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void startGame();
void drawBoard(char arr[]);
bool endGameLogic(int moves, char score[], bool player);
void winner(bool gameWinner);
int getInput();
bool makeMove(bool, char[]);


int main()
{
    startGame();
    return 0;
}

void drawBoard(char arr[]){
    printf("\t\t   |   |   \n");
    printf("\t\t %c | %c | %c \n", arr[0], arr[1], arr[2]);
    printf("\t\t___|___|___\n");
    printf("\t\t   |   |   \n");
    printf("\t\t %c | %c | %c \n", arr[3], arr[4], arr[5]);
    printf("\t\t___|___|___\n");
    printf("\t\t   |   |   \n");
    printf("\t\t %c | %c | %c \n", arr[6], arr[7], arr[8]);
    printf("\t\t   |   |   \n");
}


void startGame(){

    char playField[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool playerOne = true;
    int countMoves = 0;
    bool endGame = false;


    while(true){

        endGame = endGameLogic(countMoves, playField, playerOne);
        if(endGame) break;
        bool validMove = false;

        while(!validMove){
            drawBoard(playField);
            if(makeMove(playerOne, playField)){
                playerOne = !playerOne;
                validMove =  true;
            }
        }

        countMoves++;
        system("clear");

    }

    drawBoard(playField);
}
// kto ide a uprava herneho pola
bool makeMove(bool player, char board[]){
    int input;
    printf("Player %s ", player ? "One(X)" : "Two(O)");
    scanf("%d", &input);
    if(input >= 1 && input <= 9){
        if((board[input-1] != 'X') && board[input-1] != 'O'){
                board[input-1] = player ? 'X' : 'O';
                return true;
        }
        system("clear");
        return false;
    }
system("clear");
    return false;
}

// endgame logic
bool endGameLogic(int moves, char score[], bool player){
    if(moves > 2 && moves < 8){
        // they are playing, someone might win the game
        // row win
        if((score[0] == score[1] && score[1] == score[2]) || (score[3] == score[4] && score[4] == score[5]) || (score[6] == score[7] && score[7] == score[8])){
            winner(player);
            return true;
        }
        // column win
        if((score[0] == score[3] && score[3] == score[6]) || (score[1] == score[4] && score[4] == score[7]) || (score[2] == score[5] && score[5] == score[8])){
            winner(player);
            return true;
        }
        // diagonal win
        if((score[0] == score[4] && score[4] == score[8]) || (score[6] == score[4] && score[4] == score[2])){
            winner(player);
            return true;
        }
    } else if(moves == 8){
        // draw
        printf("Draw!\n");
        return true;
    }
    return false;
}

// determine winner
void winner(bool gameWinner){
    switch(gameWinner){
        case true: {
            printf("Player Two won!\n");
            break;
        }
        case false: {
            printf("Player One won!\n");
            break;
        }
    }
}


