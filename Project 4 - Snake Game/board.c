#include <stdio.h>
#include "globals.h"

void printboard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }

    if (snake[0].x >= 0 && snake[0].x < SIZE && snake[0].y >= 0 && snake[0].y < SIZE)
        board[snake[0].y][snake[0].x] = '@';

    for (int i = 1; i < length; i++) {
        if (snake[i].x >= 0 && snake[i].x < SIZE && snake[i].y >= 0 && snake[i].y < SIZE)
            board[snake[i].y][snake[i].x] = '*';
    }

    if (foodx >= 0 && foodx < SIZE && foody >= 0 && foody < SIZE)
        board[foody][foodx] = 'O';

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
