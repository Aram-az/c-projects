#include <stdlib.h>
#include "globals.h"

void placefood() {
    int valid = 0;
    while (!valid) {
        foodx = rand() % SIZE;
        foody = rand() % SIZE;
        valid = 1;
        for (int i = 0; i < length; i++) {
            if (foodx == snake[i].x && foody == snake[i].y) {
                valid = 0;
                break;
            }
        }
    }
}
