#include "associative_array.h"
#include "hangman.h"
#include "vector.h"
#include "generic.h"



int main(int argc, char* argv[]){
	
	FILE* fp = fopen("dictionary.txt","r");
	MY_STRING tempOBJ = NULL;
	tempOBJ = my_string_init_default();
	
	VECTOR* vectorArray = (VECTOR*)malloc(sizeof(VECTOR)*30);
	for(int i =0; i<30;++i){
		vectorArray[i] = init_default();
	}
	
	int stringSize = 0;
	/*my_string_extraction(tempOBJ,fp);
	my_string_insertion(tempOBJ,stdout);*/
        int nCount = 0;
	while(my_string_extraction(tempOBJ,fp)){
               
		stringSize = my_string_get_size(tempOBJ);
		if(stringSize==0)
			break;
                //printf("Count: %d, string size: %d\n",nCount,stringSize);
                nCount++;
		vector_push_back_MY_STRING(vectorArray[stringSize-1],tempOBJ);
		my_string_destroy(&tempOBJ);
		tempOBJ = my_string_init_default();
		
		
	}
	my_string_destroy(&tempOBJ);
	//free(vectorArray);
	fclose(fp);
	Boolean playAgain = TRUE;
	do{
	int numGuesses=-1;
	int wordLength=-1;
	while(wordLength<=0||wordLength>=30||wordLength==26||wordLength==27||wordLength==23){
		printf("Please enter a word lenght between 1 and 29(not 23, 26, 27, or 23):\n");
		scanf("%d",&wordLength);
	}
	while(numGuesses<=0){
		printf("Please enter a number of Guesses greater than zero:\n");
		scanf("%d",&numGuesses);
	}
	Boolean showListSize = FALSE;

	printf("Would you like to see remaining number of words in the list? yes(1) or no(0)?\n");
	int tempBool = 0;
	scanf("%d",&tempBool);
	showListSize = (Boolean)tempBool;
	game* Game = game_init(vectorArray[wordLength-1], numGuesses, showListSize,wordLength);
	do{
		run_round(Game);
	}while(!isGameFinished(Game));
	
	destroy_game(&Game);
	printf("would you like to play again? yes(1) or no(0)\n");
	int plgn = 0;
	scanf("%d",&plgn);
	playAgain = (Boolean)plgn;
	}while(playAgain);
	for(int i = 0; i<30;++i){
		destroy(&vectorArray[i]);
	}
	free(vectorArray);
	return 0;
}

//Game Functions:
game* game_init(VECTOR all_words, int attempts,Boolean d_passed, int wordLength){
	game* newGame = (game*)malloc(sizeof(game));
	newGame->allWords=init_default();
	for(int i = 0; i < getSize(all_words);++i){
		vector_push_back_MY_STRING(newGame->allWords,return_data_at_as_MY_STRING(all_words,i));
	}
	newGame->maxAttempts=attempts;
	newGame->currAttempts=0;
	newGame->charEntered = my_string_init_default();
	newGame->currFam = my_string_init_default();
	for(int i = 0; i<wordLength;++i){
		my_string_push_back(newGame->currFam, '-');
	}
	newGame->root=NULL;
	newGame->display=d_passed;
	return newGame;
	
}

void display_size_list(game* Game){
	if(Game->display)
		printf("Number of Remaining words: %d\n", getSize(Game->allWords));
	return;
}

void display_curr_fam(game* Game){
	my_string_insertion(Game->currFam,stdout);
	printf("\n");
}

char get_next_guess(game* Game){
	display_entered_guesses(Game);
	int conversions;
	char guess;
	Boolean isGuessed = FALSE;
	do{
		printf("Enter Next Guess:\n");
		clear_keyboard_buffer();
		conversions = scanf("%c",&guess);
		//clear_keyboard_buffer();
		if(conversions<1)
			continue;
		guess = tolower(guess);
		isGuessed=is_char_present(Game->charEntered, guess);
	}while(conversions<1||isGuessed);
	return guess;
	
}
void display_entered_guesses(game* Game){
	if(my_string_empty(Game->charEntered)||Game->charEntered==NULL){
		printf("\n");
		return;}
	printf("Past guesses: ");
	my_string_insertion(Game->charEntered,stdout);
	/*for(int i = 0; i<my_string_get_size(Game->charEntered);++i){
		printf("%c, ",*my_string_at(Game->charEntered, i));
	}*/
	printf("\n");
}


void clear_keyboard_buffer(void)
{
    char c;
    do
    {
        scanf("%c", &c);
    } while (c != '\n');
}
Boolean is_char_present(MY_STRING s, char c){
	Boolean isPresent=FALSE;
	for(int i = 0; i<my_string_get_size(s);++i){
		if(*my_string_at(s, i)==c){
			isPresent=TRUE;
			break;
		}
	}
	return isPresent;
}

void run_round(game* Game){
	display_curr_fam(Game);
	display_size_list(Game);
	char c= get_next_guess(Game);
	printf("Applying guess: %c\n", c);
	my_string_push_back(Game->charEntered,c);
	Game->currAttempts++;
	//sort all the words into new family
	for(int i = 0; i<getSize(Game->allWords);++i){
		MY_STRING word = return_data_at_as_MY_STRING(Game->allWords, i);
		MY_STRING newKey = my_string_init_default();
		get_word_key_value(Game->currFam,newKey,word,c);
		insert(&(Game->root),newKey,word);	
		///my_string_destroy(&newKey);
	}
	//find the largest family, reassign 
	Node* maxNode=NULL;
	find_largest_fam_key(Game->root, &maxNode);
	my_string_destroy(&(Game->currFam));
	Game->currFam=my_string_init_default();
	my_string_assignment(&Game->currFam,maxNode->key);
	destroy(&Game->allWords);
	Game->allWords = init_default();
	//Game->allWords = maxNode->words;
	copy_vector(&(Game->allWords),maxNode->words);
	//destroy_tree(&(Game->root));
	//destroy_node(&maxNode);
	Game->root=NULL;
}

Boolean isGameFinished(game* Game){
	//my_string_insertion(Game->currFam,stdout);
	//return FALSE;
	if(!is_char_present(Game->currFam, '-')){
		printf("YOU WON! THE WORD IS ");
		my_string_insertion(Game->currFam,stdout);
		printf("\n");
		return TRUE;
	}
	if(Game->currAttempts>= Game->maxAttempts){
		printf("You lost, no more attempts. The word was: ");
		my_string_insertion(return_data_at_as_MY_STRING(Game->allWords,0),stdout);
		printf("\n");
		return TRUE;
	}
	return FALSE;
}

void destroy_game(game** Game){
	if((*Game)->allWords!=NULL)
		destroy(&(*Game)->allWords);
	else if((*Game)->charEntered!=NULL)
		my_string_destroy(&(*Game)->charEntered);
	else if((*Game)->currFam != NULL)
		my_string_destroy(&(*Game)->currFam);
	else if((*Game)->root!=NULL)
		destroy_tree(&(*Game)->root);
	free(*Game);
	
}

