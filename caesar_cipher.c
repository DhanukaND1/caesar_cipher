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

// Encrypt a single character
char encryptCharacter(char character, int shiftKey) {
    if (!isalpha(character)){
        return character;
    }
    
    character = toupper(character);
    int position = (character - 'A' + shiftKey + MAXSIZE) % MAXSIZE;
    return queue[position];
}

// Encrypt full message
void encryptMessage(char *message, int shiftKey, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = encryptCharacter(message[i], shiftKey);
    }
    result[strlen(message)] = '\0';
}

// Decrypt a single character(convert to orginal chracter)
char decryptCharacter(char character, int shiftKey) {
    if (!isalpha(character)) return character;

    character = toupper(character);
    int position = (character - 'A' - shiftKey + MAXSIZE) % MAXSIZE;
    return queue[position];
}

// Decrypt full message(convert to orginal message)
void decryptMessage(char *message, int shiftKey, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = decryptCharacter(message[i], shiftKey);
    }
    result[strlen(message)] = '\0';
}