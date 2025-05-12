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


