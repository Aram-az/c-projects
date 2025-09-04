#ifndef GLOBALS_H
#define GLOBALS_H

#define SIZE 8

typedef struct {
    int x, y;
} Segment;

extern char board[SIZE][SIZE];
extern int status;
extern char direction;
extern int foodx, foody;
extern Segment snake[100];
extern int length;
extern int score;

#endif