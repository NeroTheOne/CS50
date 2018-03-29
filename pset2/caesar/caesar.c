#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getAlphaIndex(char c);

int main(int argc, string argv[]) {
    if (argc != 2 || atoi(argv[1]) == 0) {
        printf("try again: ./caesar k[int]\n");
        return 1;
    }

    int k = atoi(argv[1]);
    // printf("k: %i\n", k);

    string plaintext = get_string("plaintext: ");
    while (plaintext[0] == '\0') {
        plaintext = get_string("plaintext: ");
    }

    // printf("plaintext: %s\n", plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                int alpha_i = getAlphaIndex(c) + k;
                // printf("%i\n", alpha_i);
                printf("%c", (alpha_i % 26) + 65);
            } else {
                int alpha_i = getAlphaIndex(c) + k;
                printf("%c", (alpha_i % 26) + 97);
            }

        } else {
            printf("%c", c);
        }
    }

    printf("\n");

}

int getAlphaIndex(char c) {
    int ascii = c;
    if (isupper(c)) {
        return ascii - 65;
    } else if (islower(c)) {
        return ascii - 97;
    }
}