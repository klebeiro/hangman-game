#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxAttempts 5
#define MaxLength 50

int attempts;
char guessedChar;
char secretWord[MaxLength];
char secretWordMask[MaxLength];

int letterExistInSecretWord();
void getSecretWord();
void generateSecretWordMask();
void updateSecretWordMask();
void checkWinCondition();
void printHud();

int main() { 

    getSecretWord();

    do {

        printHud();

        scanf(" %c", &guessedChar);

        if (letterExistInSecretWord() == 1) {
            updateSecretWordMask();
        } else {
            attempts++;
        }

        checkWinCondition();

    } while(attempts < MaxAttempts);

    return 0;
}

int letterExistInSecretWord() {

	for(int i = 0; i < strlen(secretWord); i++) {
		if(guessedChar == secretWord[i]) {
            return 1;
		}
	}

	return 0;
}

void getSecretWord() {
    
    printf(
    "\t--------------------\n"
    "\tEnter the secret word\n"
    "\t--------------------\n"
    "> ");

    scanf("%s", &secretWord);    

    generateSecretWordMask();

    system("cls");

}

void generateSecretWordMask() {

    for(int i = 0; i < strlen(secretWord); i++) {
        strcat(secretWordMask, "x");
    }

}

void updateSecretWordMask() {

    for(int i = 0; i < strlen(secretWord); i++) {
        if(secretWord[i] == guessedChar) {
            secretWordMask[i] = guessedChar;
        }
    }
    
}

void checkWinCondition() {
    if(strcmp(secretWord, secretWordMask) == 0) {
        system("cls");

        printf(
            "\t------------------------\n"
            "\tThe word was: '%s'\n"
            "\t------------------------\n"
            "\t> You Win!\n", secretWord);
        exit(0);
    } else if(attempts == MaxAttempts) {
        system("cls");

        printf(
            "\t------------------------\n"
            "\tThe word was: '%s'\n"
            "\t------------------------\n"
            "\t> You Lose!\n", secretWord);
        exit(0);
    }
}

void printHud() {
    
    system("cls");
    
    printf(
    "\t------------------------\n"
    "\tAttempts remaining: %d\n"
    "\tResult: %s\n"
    "\tTry to guess a letter\n"
    "\t------------------------\n"
    "> ", MaxAttempts - attempts, secretWordMask);

}