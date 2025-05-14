#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"

// Initilize Circular queue
char queue[MAXSIZE];

// Create circular queue with A-Z
void createQueue() {
    for (int i = 0; i < MAXSIZE; i++) {
        queue[i] = 'A' + i;
    }
}

// Decrypt a single character
char decryptCharacter(char character, int shiftKey) {
    if (!isalpha(character)) return character;

    character = toupper(character);
    int position = (character - 'A' - shiftKey + MAXSIZE) % MAXSIZE;
    return queue[position];
}

// Decrypt full message
void decryptMessage(char *message, int shiftKey, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = decryptCharacter(message[i], shiftKey);
    }
    result[strlen(message)] = '\0';
}