#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {

    printf("Change owed: ");
    double f = get_float() * 100;
    int change_owed = round(f);

    while (change_owed < 0) {
        printf("Retry: ");
        f = get_float();
        change_owed = (int) f * 100;
    }

    int count = 0;

    while (change_owed > 0) {
        if (change_owed >= 25) {
            change_owed = change_owed - 25;
            count = count + 1;
        } else if (change_owed >= 10) {
            change_owed = change_owed - 10;
            count = count + 1;
        } else if (change_owed >= 05) {
            change_owed = change_owed - 5;
            count = count + 1;
        } else if ( change_owed >= 1) {
            change_owed = change_owed - 1;
            count = count + 1;
        }

    }

    printf("%i\n", count);
}