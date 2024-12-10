//Authors: Zion Gomez, Jacob Becerra, Sophia Koshy
//Final Group Project
//Date: 12/10/2024

#include <stdio.h>
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

    fin = fopen(FILENAME,"r");

    if (fin == NULL){
        printf("Could not open file.\n");
        return 0;
    }

    readFile(fin, fileString);
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
    for(int i = 0; arrayNAV[i] != '\0'; i++){

    }
}


void displayMadlib(char fileString[][SIZE]){
    for(int i = 0; fileString[i][0] != '\0'; i++){
        printf("%s ", fileString[i]);
    }
}
