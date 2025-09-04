#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "globals.h"
#include "board.h"
#include "snake.h"
#include "food.h"

char board[SIZE][SIZE];
int status = 0;
char direction;
int foodx;
int foody;
Segment snake[100];
int length = 2;
int score = 0;

int main() {
    srand(time(NULL));
    direction = 'd';
    snake[0].x = 1; snake[0].y = 1;
    snake[1].x = 0; snake[1].y = 1;
    placefood();

    while (1) {
        movesnake();
        if (status) break;
        printf("\x1b[H\x1b[2J");
        printf("Score: %d\n\n", score);
        printboard();
        usleep(150000);
    }
    printf("\x1b[H\x1b[2J");
    printf("Score: %d\n\n", score);
    printboard();
    printf("\nGAME OVER! Final score: %d\n", score);

    return 0;
}
//to run line 1: gcc main.c board.c snake.c food.c -o snake.exe
// line 2: ./snake.exe