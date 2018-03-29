#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getAlphaIndex(char c);

int main (int argc, string argv[]) {

    if (argc != 2) {
        printf("error: no key provided\n");
        printf("./vigenere [string]\n");
        return 1;
    }

    string key = argv[1];
    // printf("key: %s\n", key);
    for (int i = 0; i < strlen(key); i++) {
        if (isdigit(key[i])) {
            printf("error: key should only consist of alphabetical characters\n");
            printf("./vigenere [string]\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    while (plaintext[0] == '\0') {
        plaintext = get_string("plaintext: ");
    }

    printf("ciphertext: ");

    int k = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            int alpha_i = getAlphaIndex(c) + getAlphaIndex(key[k]);
            if (isupper(c)) {
                printf("%c", (alpha_i % 26) + 65);
            } else {
                printf("%c", (alpha_i % 26) + 97);
            }
            k = k + 1;
            k = k % strlen(key);
        } else {
            printf("%c", plaintext[i]);
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
    return 1;
}


