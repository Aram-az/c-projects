#include <stdio.h>

int win(char board[3][3]) {
    for (int i = 0; i<3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
        }
    }
    for (int i = 0; i<3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
             return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
     return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
     return 1;
     else
     return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int pos;
    int turn;
    int winner;
    int row;
    int col;
    int haswin = 0;
    for (int i = 0; i < 9; i++) {
        while(1) {
            printf("Enter a Number 1-9: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > 9){
                printf("Please enter a number between 1 and 9.\n");
                continue;
            }
            row = (pos - 1) / 3;
            col = (pos - 1) % 3;
            if(board[row][col] != ' ') {
                printf("Please enter a slot which has not been taken.\n");
                continue;
            }
            else
            break;
        }
        if (i%2 == 0) 
            board[row][col] = 'X';
        else 
            board[row][col] = 'O';
        turn = i;
        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
        if (win(board) == 1) {
            haswin = 1;
            break;
        }
    }
    if (turn%2 == 0)
    winner = 1;
    else
    winner = 2;
    if (haswin == 1)
    printf("Congrats! Player %d Won!\n", winner);
    else
    printf("Draw!\n");
    return 0;
}