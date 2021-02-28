/*
 * Created by Robert Davis
 * Program 1 Vigenere Cipher
 * Spring 2021 CIS 3360
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 512

//Encrypts the text using the key file
char* encrypt(char* plainText, char* keyText);
//Strips non-alpha characters, converts to lowercase and adds padding
char* processFile(FILE* fp, int param);
//Display the text in a row of 80 characters
void displayText(char* text);

int main(int argc, char *argv[]) {


    //Variable declarations
    FILE* txtFile, *keyFile;
    char *plainText, *encryptionKey, *cipherText;

    //Open Files
    keyFile = fopen(argv[1], "r");
    txtFile = fopen(argv[2], "r");
    if(!txtFile || !keyFile){
        printf("\nAt least one file did not open\n");
        exit(-1);
    }

    printf("Vigenere Key:\n\n");
    encryptionKey = processFile(keyFile, 1);
    displayText(encryptionKey);

    printf("\nPlaintext:\n\n");
    plainText = processFile(txtFile, 2);
    displayText(plainText);

    printf("\nCiphertext:\n\n");
    cipherText = encrypt(plainText, encryptionKey);
    displayText(cipherText);



}

char* processFile(FILE* fp, int param){
    char* retChar = (char*)malloc((MAXCHAR + 1) * sizeof(char));
    //Store char for checks
    char singleChar;

    for(int i = 0; i < MAXCHAR; i++){


        singleChar = fgetc(fp);
        while(singleChar != EOF) {
            if (isalpha(singleChar)) {
                singleChar = tolower(singleChar);
                //printf("char %c placed in spot %d \n", singleChar, i);
                retChar[i] = singleChar;

                if(param == 1)
                    retChar[i+1] = '\0';

                i++;
            }
            singleChar = fgetc(fp);
        }

            if(param == 2) {
                retChar[i] = 'x';
                //printf("char x placed in spot %d \n", i);
            }

    }

    retChar[MAXCHAR] = '\0';
    return retChar;
}

void displayText(char* text){
    //Loop through the file and print each char
    for(int i = 0; i < MAXCHAR; i++){
        printf("%c", text[i]);
        //Move to a new line every 80 characters
        if( i>2 && ((i+1)%80 == 0))
            printf("\n");
    }
}

char* encrypt(char* plainText, char* keyText){
    char* retArr = (char*) malloc((MAXCHAR +1) * sizeof(char));

    int keyLength = strlen(keyText);
    for(int i = 0; i < MAXCHAR; i++){
        retArr[i] = (((plainText[i] - 97) + (keyText[i % keyLength]) -97) % 26) + 97;
    }
    retArr[MAXCHAR] = '\0';
    return retArr;
}