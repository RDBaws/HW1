/*
 * Created by Robert Davis
 * Program 1 Vigenere Cipher
 * Spring 2021 CIS 3360
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 512

//Encrypts the text using the key file
char* encrypt(char* plainText, char* keyFile);
//Strips non-alpha characters, converts to lowercase and adds padding
char* processFile(FILE* fp);
//Display the text in a row of 80 characters
void displayText(char* text);

int main(int argc, char *argv[]) {


    //Variable declarations
    FILE* txtFile, *keyFile;
    char *plainText, *encryptionKey, *cypherText;

    //Open Files
    //todo Change to command line input
    keyFile = fopen("k1.txt", "r");
    txtFile = fopen("p1a.txt", "r");
    if(!txtFile || !keyFile){
        printf("\nAt least one file did not open\n");
        exit(-1);
    }

    printf("Plaintext:\n");

    plainText = processFile(txtFile);
    displayText(plainText);



}

char* processFile(FILE* fp){
    char* retChar = (char*)malloc((MAXCHAR + 1) * sizeof(char));
    //Store char for checks
    char singleChar;

    for(int i = 0; i < MAXCHAR; i++){
        singleChar = fgetc(fp);

        if(isalpha(singleChar)){
            printf("char %c placed in spot %d \n", singleChar, i);
            retChar[i] = tolower(singleChar);
        }

        if(fgetc(fp) == EOF){
            retChar[i] = 'x';
        }
    }

    retChar[MAXCHAR] = "/0";
    return retChar;
}

void displayText(char* text){
    for(int i = 0; i < MAXCHAR; i++){
        printf("%s", text[i]);
    }
}

char* encrypt(char* plainText, char* keyFile){

}