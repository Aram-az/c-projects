#include <stdio.h>

int main() {
    while (1) {
        char pass[21];
        int chars = 0;
        int strength = 0;
        int lower = 0;
        int upper = 0;
        int num = 0;
        int symbol = 0;

        printf("Please Enter Your Password \n");
        scanf("%20s", pass);
        for(int i=0; i<21; i++) {
            if (pass[i] == '\0')
                break;
            chars++;
            if (pass[i] >= 'a' && pass[i] <= 'z') {
                lower = 1;
            }
            else if (pass[i] >= 'A' && pass[i] <= 'Z') {
                upper = 1;
            }
            else if (pass[i] >='0' && pass[i] <='9') {
                num = 1;
            }
            else {
                symbol = 1;
            }
        }
        
        if (chars < 6) {
            printf("Password is too short, please enter a new one.\n");
            continue;
        }
        else if (chars>=6 && chars<=12) {
            strength++;
        }
        else if (chars>12) {
            strength += 2;
        }

        strength += lower + upper + num + symbol;
        
        //printf("%d" "%d" "%d" "%d" "%d", chars, lower, upper, num, symbol);
        if (strength <= 2) {
            printf("Your password is Weak\n");
        }
        else if (strength > 2 && strength <= 4) {
            printf("Your password is Medium\n");
        }
        else if (strength > 4) {
            printf("Your password is Strong\n");
        }

        break;
    }

    return 0;
}