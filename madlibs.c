//Authors: Zion Gomez, Jacob Becerra, Sophia Koshy
//Final Group Project
//Date: 12/10/2024

#include <stdio.h>
#define FILENAME "madlib2.txt"
#define SIZE 200  
#define SIZE2 900

void readFile(FILE* fin, char fileString[]);
void enteredWord(char wordType[], char userWord[]);
void appendUserString(int* index, char userWord[], char fileString[]);
void appendFileString(int* index, char temp[], char fileString[]);
void addSpace(int* index, char temp[], char fileString[]);

int main(){

	FILE* fin;
    char fileString[SIZE2];

	fin = fopen(FILENAME,"r");
    
	if (fin == NULL){
        printf("Could not open file.\n");
        return 0;
    }

    readFile(fin, fileString);
    printf("%s\n", fileString);

    return 0;
}

void readFile(FILE* fin, char fileString[]){
    int index = 0;
    char temp[SIZE];
    char userWord[SIZE];

    while(fgets(temp, SIZE, fin) != NULL){
        switch(temp[1]){
            case '\n':
                enteredWord(temp, userWord);
                addSpace(&index, temp, fileString);
                appendUserString(&index, userWord, fileString);
                break;
            default:
                addSpace(&index, temp, fileString);
                appendFileString(&index, temp, fileString);
                break;
        }
    }
    fileString[index] = '\0';
}

void enteredWord(char wordType[], char userWord[]){
    switch(wordType[0]){
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

void appendUserString(int* index, char userWord[], char fileString[]){
    for(int i = 0; userWord[i] != '\0'; i++){
        fileString[*index] = userWord[i];
        *index += 1;
    }
}

void appendFileString(int* index, char temp[], char fileString[]){
    for(int i = 0; temp[i] != '\n'; i++){
        fileString[*index] = temp[i];
        *index += 1;
    }
}

void addSpace(int* index, char temp[], char fileString[]){
    if(*index != 0 && temp[0] != '.'){
        fileString[*index] = ' ';
        *index += 1;
    }
}
