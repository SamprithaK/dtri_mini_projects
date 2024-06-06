#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 6

void checkWord(char *enteredWord, char *word);

int main() {
    char word[WORD_LENGTH + 1] = "great";
    char enteredWord[WORD_LENGTH + 1];
    int attempts = 0;
    printf("Welcome to WORDLE GAME!\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your word: ", attempts + 1);
        scanf("%s", enteredWord);

        if (strlen(enteredWord) != WORD_LENGTH) {
            printf("Invalid input! Please enter a 5-letter word.\n");
            continue;
        }

        checkWord(enteredWord, word);

        if (strcmp(enteredWord, word) == 0) {
            printf("Congratulations! You guessed the word correctly.\n");
            return 0;
        }

        attempts++;
    }

    printf("Sorry! You've used all attempts. The word was '%s'.\n", word);
    return 0;
}

void checkWord(char *enteredWord, char *word) {
    bool correct[WORD_LENGTH] = {false};
    bool checked[WORD_LENGTH] = {false};
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (enteredWord[i] == word[i]) {
            correct[i] = true;
            checked[i] = true;
        }
    }
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (!correct[i]) {
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (!checked[j] && enteredWord[i] == word[j]) {
                    checked[j] = true;
                    printf("Letter %c is in the word but in the wrong position.\n", enteredWord[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (correct[i]) {
            printf("Letter %c at position %d is correct.\n", enteredWord[i], i + 1);
        } else if (!checked[i]) {
            printf("Letter %c is not in the word.\n", enteredWord[i]);
        }
    }
}
