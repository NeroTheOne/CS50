#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("Height:");
    int n = get_int();

    while (n < 0 || n > 23) {
        printf("Retry:");
        n = get_int();
    }

    int whitespace = n + 1 - 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j < whitespace) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        whitespace--;
        printf("\n");
    }

}