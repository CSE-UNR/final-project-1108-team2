//Authors: Zion Gomez, Jacob Becerra, Sophia Koshy
//Final Group Project
//Date: 12/10/2024

#include <stdio.h>
#include <stdbool.h>
#define FILENAME "madlib1.txt"
#define SIZE 200  

void readFile(FILE* fin, char fileString[][SIZE]);
void enteredWord(char wordType, char userWord[]);
void replaceWithUserString(char arrayNAV[], char fileString[][SIZE]);
void storeNAV(char arrayNAV[], char fileString[][SIZE]);
void displayMadlib(char fileString[][SIZE]);

int main(){

    FILE* fin;
    char fileString[SIZE][SIZE];
    char arrayNAV[SIZE];

    arrayNAV[0] = 'N';
    arrayNAV[1] = 'V';
    arrayNAV[2] = '\0';

    fin = fopen(FILENAME,"r");

    if (fin == NULL){
        printf("Could not open file.\n");
        return 0;
    }

    readFile(fin, fileString);
    replaceWithUserString(arrayNAV, fileString);
    displayMadlib(fileString);
    fclose(fin);
    return 0;
}

void readFile(FILE* fin, char fileString[][SIZE]){
    int index = 0;
    char temp[SIZE];

    while(fgets(temp, SIZE, fin) != NULL){
        for(int i = 0; temp[i] != '\n'; i++){
            fileString[index][i] = temp[i];
            if(temp[i+1] == '\n' || temp[i+1] == '\0'){
                fileString[index][i+1] = '\0';
            }
        }
        index++;
    }

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
        bool foundNAV = 0;

        for(int j = 0; foundNAV != 1; j++){
            if(fileString[j][0] == arrayNAV[i]){
                foundNAV = 1;

                for(int c = 0; userWord[c] != '\0'; c++){
                    fileString[j][c] = userWord[c];

                    if(userWord[c+1] == '\0'){
                        fileString[j][c+1] = '\0';
                    }
                }
            }
        }
    }
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
