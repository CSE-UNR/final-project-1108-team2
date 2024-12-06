//Final Project function

#include <stdio.h>
#define word_types 3 
#define word_repetition_adjective 3 
#define word_repetition_noun 2      
#define word_repetition_verb 2      

void enteredWords(char words[7][20], char *types[], int repetitions[]) {
    int index = 0; 
    for (int i = 0; i < word_types; i++) {
        for (int j = 0; j < repetitions[i]; j++) {
            printf("Enter %s (%d): ", types[i], j + 1);
            scanf("%19s", words[index]); 
            index++;
        }
    }
}

int main() {
    char words[7][20]; 
    char *types[word_types] = {
        "an adjective",
        "a noun",
        "a verb"
    };
    int repetitions[word_types] = {
        word_repetition_adjective,
        word_repetition_noun,
        word_repetition_verb
    };

    enteredWords(words, types, repetitions);

    return 0;
}

	
	

	
