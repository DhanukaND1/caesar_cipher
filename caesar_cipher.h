// caesar_cipher.h
#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#define MAXSIZE 26

// Function declarations
void createQueue();
char encryptCharacter(char ch, int key);
char decryptCharacter(char ch, int key);
void encryptMessage(char *message, int key, char *result);
void decryptMessage(char *message, int key, char *result);

#endif

