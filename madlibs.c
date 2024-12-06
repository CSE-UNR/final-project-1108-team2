//Sophia Koshy
//Final Group Project

#include<stdio.h>
#define FILENAME "madlib2.txt"
#define LINE_SIZE 200  
#define NUM_LINES 20

void readFile(FILE*fin);

int main(){

	FILE*fin;
	fin = fopen(FILENAME,"r");
	if (fin == NULL){
		printf("Could not open file.\n");
		return 0;
	}
	readFile(fin);

return 0;
}

void readFile(FILE*fin){
	char line[200];
	while(fgets(line,LINE_SIZE,fin)){
		if(line[1]=='\n'){
			printf("Found\n");
			//userInputArray();
		}
	
	}
}











