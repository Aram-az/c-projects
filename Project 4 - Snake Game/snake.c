#include <conio.h>
#include <stdio.h>
#include "globals.h"
#include "food.h"

void collision() {
    if (snake[0].x >= SIZE || snake[0].x < 0 || snake[0].y >= SIZE || snake[0].y < 0) {
        printf("Game Over!\n");
        status = 1;
    }
    for (int i = 1; i < length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            printf("Game Over!\n");
            status = 1;
        }
    }
}

void movesnake() {
    for (int i = length-1; i > 0; i--) {
        snake[i] = snake[i-1];
    }

    if (kbhit()) {
        direction = getch();
    }
    switch (direction) {
        case 'w': snake[0].y--; break;
        case 'a': snake[0].x--; break;
        case 's': snake[0].y++; break;
        case 'd': snake[0].x++; break;
    }
    collision();

    if (snake[0].x == foodx && snake[0].y == foody) {
        Segment tail = snake[length - 1];
        length++;
        score += 10;
        snake[length - 1] = tail;
        placefood();
    }
}
