//Authors: Zion Gomez, Jacob Becerra, Sophia Koshy
//Final Group Project
//Date: 12/10/2024

#include <stdio.h>
#include <stdbool.h>
#define FILENAME "madlib2.txt"
#define SIZE 200  

void readFile(FILE* fin, char arrayNAV[], char fileString[][SIZE]);
void enteredWord(char wordType, char userWord[]);
void replaceWithUserString(char arrayNAV[], char fileString[][SIZE]);
void displayMadlib(char fileString[][SIZE]);
int lookForNAV(char fileString[][SIZE], char wordType);

int main(){

    FILE* fin;
    char fileString[SIZE][SIZE];
    char arrayNAV[SIZE];

    fin = fopen(FILENAME,"r");

    if (fin == NULL){
        printf("Could not open file.\n");
        return 0;
    }

    readFile(fin, arrayNAV, fileString);

    fclose(fin);

    replaceWithUserString(arrayNAV, fileString);

    displayMadlib(fileString);

    return 0;
}

void readFile(FILE* fin, char arrayNAV[], char fileString[][SIZE]){
    int fileIndex = 0;
    int arrayNAVIndex = 0;
    char temp[SIZE];

    while(fgets(temp, SIZE, fin) != NULL){
        for(int i = 0; temp[i] != '\n'; i++){
            switch(temp[i+1]){
                case '\n':
                    fileString[fileIndex][i+1] = '\0';

                    if((temp[i] == 'N' || temp[i] == 'A' || temp[i] == 'V') && i == 0){
                        arrayNAV[arrayNAVIndex] = temp[i];
                        arrayNAVIndex++;
                    }
                default:
                    fileString[fileIndex][i] = temp[i];
                    break;
            }
        }
        fileIndex++;
    }
    arrayNAV[arrayNAVIndex] = '\0';
}

void enteredWord(char wordType, char userWord[]){
    switch(wordType){
        case 'A':
            printf("Enter an adjective: ");
            break;
        case 'N':
            printf("Enter a noun: ");
            break;
        case 'V':
            printf("Enter a verb: ");
            break;
    }

    scanf("%s", userWord);
}

void replaceWithUserString(char arrayNAV[], char fileString[][SIZE]){
    char userWord[SIZE];

    for(int i = 0; arrayNAV[i] != '\0'; i++){
        enteredWord(arrayNAV[i], userWord);

        int fRow = lookForNAV(fileString, arrayNAV[i]);

        for(int c = 0; userWord[c] != '\0'; c++){
            fileString[fRow][c] = userWord[c];

            if(userWord[c+1] == '\0'){
                fileString[fRow][c+1] = '\0';
            }
        }
    }
}

int lookForNAV(char fileString[][SIZE], char wordType){
    bool foundNAV = 0;
    int index = 0;

    for(int j = 0; foundNAV != 1; j++){
        if(fileString[j][0] == wordType && fileString[j][1] == '\0'){
            foundNAV = 1;
            index = j;
        }
    }

    return index;
}

void displayMadlib(char fileString[][SIZE]){
    for(int i = 0; fileString[i][0] != '\0'; i++){
        printf("%s", fileString[i]);
        if(fileString[i+1][0] != '\0' && fileString[i+1][0] != ',' && fileString[i+1][0] != '!' && fileString[i+1][0] != '.' && fileString[i+1][0] != ' '){
            printf(" ");
        }
    }
    printf("\n");
}
