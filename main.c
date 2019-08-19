#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{
 /*MY_STRING hMy_string1 = NULL;
 hMy_string1 = my_string_init_c_string("Hello");
 
 printf("String original: ");
 print_my_string(hMy_string1);
 
 my_string_push_back(hMy_string1, 'r');
 printf("String after pushback 'r': ");
 print_my_string(hMy_string1);

 my_string_pop_back(hMy_string1);
 printf("String after popback: ");
 print_my_string(hMy_string1);

 printf("cstring: ");
 char* tempstr = my_string_c_str(hMy_string1);
 for(int i = 0; tempstr[i] != '\0';i++){
   printf("%c", tempstr[i]);
 }
 printf("\n");

MY_STRING hMy_string2 = NULL;
hMy_string2 = my_string_init_c_string(" Apple");
my_string_concat(hMy_string1, hMy_string2);
 printf("Mystring1 after concat: ");
 print_my_string(hMy_string1);
 printf("Mystring2 after concat: ");
 print_my_string(hMy_string2);

 MY_STRING hEmpty_string = my_string_init_default();
 if(my_string_empty(hEmpty_string)){
   printf("Confirmed Empty string is Empty\n");
 }
 if(!my_string_empty(hMy_string1)){
   printf("Confirmed hMy_string1 is not empty\n");
 }
 
  my_string_destroy(&hMy_string1);
  my_string_destroy(&hMy_string2);
  my_string_destroy(&hEmpty_string);*/



//Checkpoint 1 for lab 8

  MY_STRING currFam = NULL;
  currFam = my_string_init_c_string("---");
  MY_STRING new_key = NULL;
 new_key = my_string_init_c_string("---");
  MY_STRING word = NULL;
  word = my_string_init_c_string("The");
  char guess = 'T';
  get_word_key_value(currFam,new_key,word,guess);
  printf("Old Key: ");
  my_string_insertion(currFam, stdout);
  printf("  Word: ");
  my_string_insertion(word, stdout);
  printf("  Guess: %c   New Key: ",guess);
  my_string_insertion(new_key, stdout);
  my_string_destroy(&currFam);
  my_string_destroy(&new_key);
  my_string_destroy(&word);
  printf("\n");

  currFam = NULL;
  currFam = my_string_init_c_string("-----");
  new_key = NULL;
 new_key = my_string_init_default();
  word = NULL;
  word = my_string_init_c_string("Truck");
  guess = 'r';
  get_word_key_value(currFam,new_key,word,guess);
  printf("Old Key: ");
  my_string_insertion(currFam, stdout);
  printf("  Word: ");
  my_string_insertion(word, stdout);
  printf("  Guess: %c   New Key: ",guess);
  my_string_insertion(new_key, stdout);
  my_string_destroy(&currFam);
  my_string_destroy(&new_key);
  my_string_destroy(&word);
  printf("\n");

 currFam = NULL;
  currFam = my_string_init_c_string("--ppy");
  new_key = NULL;
 new_key = my_string_init_c_string("-----");
  word = NULL;
  word = my_string_init_c_string("happy");
  guess = 'h';
  get_word_key_value(currFam,new_key,word,guess);
  printf("Old Key: ");
  my_string_insertion(currFam, stdout);
  printf("  Word: ");
  my_string_insertion(word, stdout);
  printf("  Guess: %c   New Key: ",guess);
  my_string_insertion(new_key, stdout);
  my_string_destroy(&currFam);
  my_string_destroy(&new_key);
  my_string_destroy(&word);
  printf("\n");

currFam = NULL;
  currFam = my_string_init_c_string("--e---e");
  new_key = NULL;
 new_key = my_string_init_c_string("-------");
  word = NULL;
  word = my_string_init_c_string("awesome");
  guess = 'z';
  get_word_key_value(currFam,new_key,word,guess);
  printf("Old Key: ");
  my_string_insertion(currFam, stdout);
  printf("  Word: ");
  my_string_insertion(word, stdout);
  printf("  Guess: %c   New Key: ",guess);
  my_string_insertion(new_key, stdout);
  my_string_destroy(&currFam);
  my_string_destroy(&new_key);
  my_string_destroy(&word);
  printf("\n");

  return 0;
}

