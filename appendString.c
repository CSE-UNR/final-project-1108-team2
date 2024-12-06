//Author: Zion Gomez
//Date: 12/04/2024

#include <stdio.h>
#define SIZE 100
#define FILENAME "madlib2.txt"

void appendString(int* index, char userWord[], char fileString[]);

int main(){
    char fileString[SIZE];
    char temp[SIZE];
    char userWord[SIZE];
    int index = 0;

    FILE* fin;

    fin = fopen(FILENAME, "r");

    if(fin == NULL){
        printf("failed");
        return 0;
    }

    fgets(temp, SIZE, fin);

    printf("%s", temp);

    for(int i = 0; temp[i] != '\n'; i++){
        fileString[i] = temp[i];
        index++;
    }


    printf("%s\n", fileString);

    printf("Enter an adjective: ");
    scanf("%s", userWord);

    appendString(&index, userWord, fileString);

    return 0;
}


void appendString(int* index, char userWord[], char fileString[]){
    fileString[*index] = ' ';
    *index += 1;

    for(int i = 0; userWord[i] != '\0'; i++){
        fileString[*index] = userWord[i];
        *index += 1;
    }
    printf("%s", fileString);
}
