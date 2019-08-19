#ifndef HANGMAN_H
#define HANGMAN_H
#include <ctype.h>
#include "associative_array.h"
#include "vector.h"
#include "generic.h"

typedef struct game{
	VECTOR allWords;
	int maxAttempts;
	int currAttempts;
	MY_STRING charEntered;
	MY_STRING currFam;
	Node* root;
	Boolean display;
	
}game;

game* game_init(VECTOR all_words, int attempts,Boolean d_passed, int wordLength);

void display_size_list(game* Game);

void display_curr_fam(game* Game);

char get_next_guess(game* Game);

void display_entered_guesses(game* Game);

void clear_keyboard_buffer(void);

Boolean is_char_present(MY_STRING s, char c);


void run_round(game* Game);

Boolean isGameFinished(game* Game);

void destroy_game(game** Game);

/*int* return_offsets(MY_STRING word, char c){
	int* offsets = (int*)malloc(sizeof(int)*my_string_get_size(word));
	//populate array with -1
	for(int i = 0;i<my_string_get_size(word);++i){
		offsets[i] = -1;
	}
	char* tempString = my_string_c_str(word);
	int count = 0;
	//account for where in word occurence of char c are
	for(int i = 0; tempString[i]!='\0';++i){
		if(tempString[i]=c){
			offsets[count] = i;
			count++;
		}
	}
	return offsets;
	
}

MY_STRING create_new_key(game* Game, int* offsets){
	MY_STRING newKey = my_string_init_default();
	
}*/
#endif
