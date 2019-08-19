#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 if(hString == NULL)
 {
   strncpy(buffer, "test_init_default_returns_nonNULL\n"
   "my_string_init_default returns NULL", length);
   return FAILURE;
 }
 else
 {
   my_string_destroy(&hString);
   strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
   return SUCCESS;
 }
}//end test_init_default_returns_nonNULL

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
 {
   status = FAILURE;
   printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
   strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
   "Did not receive 0 from get_size after init_default\n", length);
 }
 else
 {
   status = SUCCESS;
   strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
   , length);
 }
 my_string_destroy(&hString);
 return status;
}//end test_get_size-on_init_default_returns_0


Status test_mmitkov_my_string_compare_returns_0_for_equal_strings(char* buffer, int length){
	Status status;
	MY_STRING leftString = NULL;
	leftString = my_string_init_c_string("hhh");
	MY_STRING rightString = NULL;
	rightString = my_string_init_c_string("hhh");
	if(my_string_compare(leftString, rightString) != 0){
		status = FAILURE;
   		printf("Expected a size of 0 but got %d\n", my_string_compare(leftString, 			rightString));
   		strncpy(buffer, "test_mmitkov_my_string_compare_returns_0_for_equal_strings\n"
   		"Did not receive 0 from my_string_compare with equal lexographic strings\n", 			length);
	}
	else
 	{
   		status = SUCCESS;
   		strncpy(buffer, "test_mmitkov_my_string_compare_returns_0_for_equal_strings\n"
   		, length);
 	}
 	my_string_destroy(&rightString);
	my_string_destroy(&leftString);
 	return status;

}//end test_mmitkov_my_string_compare_returns_0_for_equal_strings


Status test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhh");
	if(my_string_get_capacity(hString)!=4){
		status = FAILURE;
   		printf("Expected a capacity of 4 but got %d\n", my_string_get_capacity(hString));
   		strncpy(buffer, 		"test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string\n"
   		"Did not receive correct capacity(4) from get_capacity after init_c_string\n", 			length);
	}
	else
	{
  		status = SUCCESS;							       strncpy(buffer,"test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string\n"
   		, length);
  	}
 	my_string_destroy(&hString);
 	return status;
}//test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string


Status test_mmitkov_my_string_c_str_returns_valid_c_string(char* buffer, int length){
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("hhh");
	char* testString = (char*)malloc(sizeof(char)*4);
	for(int i=0; i<3;i++){
		testString[i] = 'h';
	}
	testString[3] = '\0';
	char* string_to_test = my_string_c_str(hString);
	if(strcmp(string_to_test, testString) == 0){
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_c_str_returns_valid_c_string\n",length);
	}
	else{
		status = FAILURE;
		
   		strncpy(buffer, "\ntest_mmitkov_my_string_c_str_returns_valid_c_string\n"
   		"Did not return valid cstring\n", length);
	}
	//free(string_to_test);
	free(testString);
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_my_string_c_str_returns_valid_c_string

Status test_mmitkov_my_string_push_back_pushes_char(char* buffer, int length){
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("hhh");
	my_string_push_back(hString, 'c');
	char* test_string = (char*)malloc(sizeof(char)*5);
	for(int i =0; i<3;i++){
		test_string[i] = 'h';
	}
	test_string[3] = 'c';
	test_string[4] = '\0';
	char* hmString = my_string_c_str(hString);
	if(strcmp(hmString, test_string) != 0){
		status = FAILURE;
		printf("Failed to push character c onto string: hhh\n");
	strncpy(buffer,"test_mmitkov_my_string_push_back_pushes_char_using_my_string_compare\n"
			"did not push back character onto my_string object\n", length);
	}
	else{
		status = SUCCESS;
	strncpy(buffer,"test_mmitkov_my_string_push_back_pushes_char_using_my_string_compare\n"
   		, length);
	}
	my_string_destroy(&hString);
	free(test_string);
	return status;
}//end test_mmitkov_my_string_push_back_pushes_char


Status test_mmitkov_my_string_push_back_allocates_extra_capacity(char* buffer, int length){
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("hhh");
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'c');
	if(my_string_get_capacity(hString)<7){
		status = FAILURE;
		printf("Expected get_capacity to return at least 6(up to 10) after allocation, 			instead returned %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mmitkov_my_string_push_back_allocates_extra_capacity\n"
				"my_string_push_back failed to allocate enough extra capacity\n", 			length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_push_back_allocates_extra_capacity\n", 			length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_my_string_push_back_allocates_extra_capacity

Status test_mmitkov_my_string_pop_back_pops_last_char_in_my_string(char* buffer, int length){
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("hhhc");
	my_string_pop_back(hString);
	char* test_string = (char*)malloc(sizeof(char)*4);
	for(int i = 0; i<3; i++){
		test_string[i] = 'h';
	}
	test_string[3] = '\0';
	char* mhString = my_string_c_str(hString);
	if(strcmp(test_string, mhString) != 0){
		status = FAILURE;
		printf("Expected cString after my_string_back: hhh Actual:");
		for(int i = 0; i<3;i++)
			printf("%c",mhString[i]);
		printf("\n");
		strncpy(buffer, "test_mmitkov_my_string_pop_back_pops_last_char_in_my_string\n"
				"my_string_pop_back failed to pop character in final index\n", 					length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_pop_back_pops_last_char_in_my_string\n", 			length);
	}
	my_string_destroy(&hString);
	free(test_string);
	return status;
}//end test_mmitkov_my_string_pop_back_pops_last_char_in_my_string

Status test_mmitkov_my_string_concat_returns_concatinated_my_string_object(char*buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	hString = my_string_init_c_string("hh");
	hString1 = my_string_init_c_string("cc");
	hString2 = my_string_init_c_string("hhcc");
	if(!my_string_concat(hString, hString1)){
		printf("concat returned failure\n");		strncpy(buffer,"test_mmitkov_my_string_concat_returns_concatinated_my_string_object\n"
			"my_string_concat failed to execute\n", length);
		return FAILURE;
	}
else{
	char* test1 = my_string_c_str(hString);
	char* test2 = my_string_c_str(hString2);
	if(strcmp(test1,test2)!=0){
		status = FAILURE;
		printf("Expected hString to have value hhcc after concat, instead had value: ");
		print_my_string(hString);
      strncpy(buffer,"test_mmitkov_my_string_concat_returns_concatinated_my_string_object\n"
			"my_string_concat failed to concatinate to my_string objects\n", length);
	}
	else{
		status = SUCCESS;
       strncpy(buffer, "test_mmitkov_my_string_concat_returns_concatinated_my_string_object\n", 			length);
	     }
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);	
}	
	return status;
}//end test_mmitkov_my_string_concat_returns_concatinated_my_string_object


Status test_mmitkov_my_string_concat_resizes_hResult(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	MY_STRING hString1 = NULL;
	hString = my_string_init_c_string("h");
	hString1 = my_string_init_c_string("hh");
	my_string_concat(hString, hString1);
	if(my_string_get_capacity(hString)<4){
		status = FAILURE;
		printf("Expected capacity of hString to be at least 4(up to 6) after concat, but"
			"was acually %d\n",my_string_get_capacity(hString));
		strncpy(buffer,"test_mmitkov_my_string_concat_resizes_hResult\n"
				"my_string_concat failed to resize hResult\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_concat_resizes_hResult\n",length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	return status;
	
}//end Status test_mmitkov_my_string_concat_resizes_hResult


Status test_mmitkov_my_string_concast_does_not_change_hAppend(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	MY_STRING hString1 = NULL;
	hString = my_string_init_c_string("h");
	hString1 = my_string_init_c_string("hh");
	char* test1 = my_string_c_str(hString1);
	my_string_concat(hString, hString1);
	char* test2 = my_string_c_str(hString1);
	if(strcmp(test1,test2)!=0){
		status = FAILURE;
		printf("Expected value of hString1 to be the same before and after string concat.\n");
		strncpy(buffer, "test_mmitkov_my_string_concast_does_not_change_hAppend\n"
				"concat failed to leave hAppend unchanged.\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_concast_does_not_change_hAppend\n", length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	return status;
}//end test_mmitkov_my_string_concast_does_not_change_hAppend


Status test_mmitkov_my_string_empty_returns_true_after_init_default(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	if(!(my_string_empty(hString))){
		status = FAILURE;
		printf("Expected my_string_empty to return true after init_default, returned false\n");
		strncpy(buffer, "test_mmitkov_my_string_empty_returns_true_after_init_default\n"
			"my_string_empty incorrectly evaluated empty my_string object\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_empty_returns_true_after_init_default\n", length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_my_string_empty_returns_true_after_init_default

Status test_mmitkov_my_string_at_returns_null_for_out_of_bounds(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhh");
	char* ptr = my_string_at(hString, 3);
	if(ptr!=NULL){
		status = FAILURE;
		printf("Expected my_string_at(hString, 3) to return NULL(out of bounds)\n");
		strncpy(buffer,"test_mmitkov_my_string_at_returns_null_for_out_of_bounds\n"
				"fails to return NULL pointer for out of bounds index.\n",length); 
	}
	else{
		status = SUCCESS;
	strncpy(buffer,"test_mmitkov_my_string_at_returns_null_for_out_of_bounds\n",length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_my_string_at_returns_null_for_out_of_bounds


Status test_mmitkov_my_string_at_returns_correct_char(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhhc");
	char* ptr = my_string_at(hString, 3);
	if(*ptr != 'c'){
		status = FAILURE;
		printf("Expected character: c. Instead returned: %c\n", *ptr);
		strncpy(buffer, "test_mmitkov_my_string_at_returns_correct_char\n"
				"Failed to return correct character at given index\n",length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer,"test_mmitkov_my_string_at_returns_correct_char\n",length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_my_string_at_returns_correct_char


Status test_mmitkov_my_string_empty_returns_false_after_init_c_str(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhh");
	if(my_string_empty(hString)){
		status = FAILURE;
		printf("Expected my_string_empty to return false after init_default, returned true\n");
		strncpy(buffer, "test_mmitkov_my_string_empty_returns_false_after_init_c_str\n"
			"my_string_empty incorrectly evaluated non-empty my_string object\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mmitkov_my_string_empty_returns_true_after_init_default\n", length);
	}
	my_string_destroy(&hString);
	return status;
}//test_mmitkov_my_string_empty_returns_false_after_init_c_str


Status test_mmitkov_my_string_c_str_returns_null_terminated_cstr(char*buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhh");
	char* testString = my_string_c_str(hString);
	if(testString[3]!='\0'){
		status = FAILURE;
		printf("Expected NULL terminator in index 3 (string length == 3),");
		printf("Instead got: %c\n", testString[3]);
		strncpy(buffer, "test_mmitkov_my_string_c_str_returns_null_terminated_cstr\n"
				"my_string_c_str did not return null terminate c string\n",length);
	}
	else{
		status = SUCCESS;			
          strncpy(buffer,"test_mmitkov_my_string_c_str_returns_null_terminated_cstr\n",length);
	}
	my_string_destroy(&hString);
	return status;

}//end test_mmitkov_my_string_c_str_returns_null_terminated_cstr

Status test_mmitkov_get_size_returns_accurate_on_innit_c_string(char*buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hhh");
	if(my_string_get_size(hString)!=3){
		status = FAILURE;
		printf("Expected size 3, instead returned size %d\n", my_string_get_size(hString));
	    strncpy(buffer,"test_mmitkov_get_size_returns_accurate_on_innit_c_string\n"
			"my_string_get_size failed to return accurate size\n",length);	
	}
	else{
		status = SUCCESS;
	   strncpy(buffer,"test_mmitkov_get_size_returns_accurate_on_innit_c_string\n",length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_mmitkov_get_size_returns_accurate_on_innit_c_string


Status test_mmitkov_hString_nullptr_after_init_and_my_string_destroy(char* buffer, int length){
	Status status;
	MY_STRING hString=NULL;
	hString = my_string_init_default();
	my_string_destroy(&hString);
	if(hString != NULL)
	{
	    status = FAILURE;
	    printf("Expected hString to be NULL after init, then destroy.\n");
	    strncpy(buffer,"test_mmitkov_hString_nullptr_after_init_and_my_string_destroy\n"
		     "my_string_destroy failed to replace my string object with NULL\n",length);
	}
	else{
		status = SUCCESS;	          strncpy(buffer,"test_mmitkov_hString_nullptr_after_init_and_my_string_destroy\n",length);
	}
	return status;
}//test_mmitkov_hString_nullptr_after_my_string_destroy

Status test_mmitkov_string_extraction_ignores_whitespace_from_str_insertion(char* buffer, int length){
      Status status;
      	MY_STRING hString=NULL;
 	MY_STRING hString1=NULL;
	FILE* fp = fopen("testText.txt", "w+");
	hString = my_string_init_c_string("   hhh");
	hString1 = my_string_init_default();
	if(!my_string_insertion(hString, fp)){//checks if my_string_insertion was failure
		status = FAILURE;
		printf("Failed insertion\n");
	  strncpy(buffer,"tring_extraction_ignores_whitespace_from_str_insertion\n"
			"Failed initial insertion, test invalid\n", length);
	   return status;
	}
	rewind(fp);
	if(!my_string_extraction(hString1,fp)){//checks if my_string_extraction was failure
		status = FAILURE;
		printf("Failed extraction (total failure)\n");
	  strncpy(buffer,"string_extraction_ignores_whitespace_from_str_insertion\n"
			"Failed extraction completely\n", length);
	   return status;
	}
	char* testString = my_string_c_str(hString1);
	/*char* compString = (char*)malloc(sizeof(char*4));
	for(int i =0;i<3;i++){
		compString[i] = 'h';
	}
	compString[3]='\0';*/
	//printf("hString1: ");
	//print_my_string(hString1);
	if(testString[0]!='h'){
		status = FAILURE;
		printf("Expected first char in extracted string to be h, instead was: %c\n", 				testString[0]);
		printf("Extracted String: ");
		for(int i =0;testString[i]!='\0';++i){
			printf("%c",testString[i]);
		}
		printf("\n");
              strncpy(buffer,"string_extraction_ignores_whitespace_from_str_insertion\n"
				"Failed to ignore whitespace(incorrectly registered)\n",length);
	}
	else{
		status = SUCCESS;
	   strncpy(buffer,"string_extraction_ignores_whitespace_from_str_insertion\n",length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	fclose(fp);
	return status;
	
}//test_mmitkov_string_extraction_ignores_whitespace_from_str_insertion

Status my_string_pop_back_returns_FAILURE_after_init_default(char* buffer, int length){
	Status status;
      	MY_STRING hString=NULL;
	hString = my_string_init_default();
	if(my_string_pop_back(hString)){
		status = FAILURE;
	 printf("Expected FAILURE from pop_back after size 0 my_string, instead returned success\n");
		strncpy(buffer," my_string_pop_back_returns_FAILURE_after_init_default\n"
				"Failed to return FAILURE after init_default\n", length);
	}
	else{
		status = SUCCESS;
	   strncpy(buffer," my_string_pop_back_returns_FAILURE_after_init_default\n",length);
	}
	my_string_destroy(&hString);
	return status;
}//test_string_insertion_returns_SUCCESS_on_insertion

Status my_string_insertion_succesfully_inserts_my_string_into_file(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("hh");
	FILE* fp = fopen("testText1.txt", "w+");
	my_string_insertion(hString, fp);
	char c;
	char* tempString = (char*)malloc(sizeof(char)*3);
	int i = 0;
	rewind(fp);
	do{
		c = fgetc(fp);
		tempString[i] = c;
		++i;
	}while(c!= EOF);
	tempString[2]='\0';
	char* stringToTest = my_string_c_str(hString);
	if(strcmp(stringToTest,tempString)!=0){
		status = FAILURE;
		printf("String in .txt did not match my_string object\n");
		printf("Extracted string: ");
		for(int i =0; i<2;++i){
			printf("%c",tempString[i]);
		}
		printf("\n");
	    strncpy(buffer,"my_string_insertion_succesfully_inserts_my_string_into_file\n"
			"Failed to succesfully insert my_string object into file\n",length);
	}
	else{
		status = SUCCESS;		strncpy(buffer,"my_string_insertion_succesfully_inserts_my_string_into_file\n",length);
	}
	my_string_destroy(&hString);
	free(tempString);
	fclose(fp);
	return status;
}//end my_string_insertion_succesfully_inserts_my_string_into_file

Status my_string_extraction_extracts_string_no_whitespace(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	FILE* fp = fopen("testText1.txt", "r");
	my_string_extraction(hString, fp);
	char* testString = (char*)malloc(sizeof(char)*3);
	for(int i=0; i<2;++i){
		testString[i]='h';
	}
	testString[2]='\0';
	if(strcmp(testString,my_string_c_str(hString))!=0){
		status = FAILURE;
		printf("String in hString did not match expected output after extract\n");
		strncpy(buffer,"my_string_extraction_extracts_string_no_whitespace\n"
			"Failed to succesfully extract my_string object from file\n",length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer,"my_string_extraction_extracts_string_no_whitespace\n",length);
	}
	free(testString);
	fclose(fp);
	my_string_destroy(&hString);
	return status;
}//end my_string_extraction_extracts_string_no_whitespace


Status My_string_compare_returns_negative_if_lefthand_smaller(char* buffer, int length){
	Status status;
	MY_STRING lString = NULL;
	MY_STRING rString = NULL;
	lString = my_string_init_c_string("a");
	rString = my_string_init_c_string("b");
	int x = my_string_compare(lString, rString);
	if(!(x<0)){
		status = FAILURE;
		printf("expected string_compare to return -, instead returned %d\n",x);
		strncpy(buffer,"My_string_compare_returns_negative_if_lefthand_smaller\n"
			"Failed to return negative when lefthand is lexo. smaller\n",length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer,"My_string_compare_returns_negative_if_lefthand_smaller\n",length);
	}
	my_string_destroy(&lString);
	my_string_destroy(&rString);
	return status;
}//end  My_string_compare_returns_negative_if_lefthand_smaller

Status My_string_compare_returns_positive_if_righthand_smaller(char* buffer, int length){
	Status status;
	MY_STRING lString = NULL;
	MY_STRING rString = NULL;
	lString = my_string_init_c_string("b");
	rString = my_string_init_c_string("a");
	int x = my_string_compare(lString, rString);
	if(!(x>0)){
		status = FAILURE;
		printf("expected string_compare to return +, instead returned %d\n",x);
		strncpy(buffer,"My_string_compare_returns_positive_if_righthand_smaller\n"
			"Failed to return negative when righthand is lexo. smaller\n",length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer,"My_string_compare_returns_positive_if_righthand_smaller\n",length);
	}
	my_string_destroy(&lString);
	my_string_destroy(&rString);
	return status;
}//end  My_string_compare_returns_negative_if_lefthand_smaller


Status my_string_extraction_replaces_data_in_my_string(char*buffer, int length){
	Status status;
	FILE* fp = fopen("testText1.txt", "r");
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("init");
	my_string_extraction(hString, fp);
	char* testString = (char*)malloc(sizeof(char)*3);
	for(int i =0; i<2; ++i){
		testString[i]='h';
	}
	testString[2]='\0';
	if(strcmp(testString,my_string_c_str(hString))!=0){
		status = FAILURE;
		printf("Expected existing data in hString to be overwritten.\n");
	   strncpy(buffer,"my_string_extraction_replaces_data_in_my_string\n"
			"Failed to overwrite existing data in hString\n",length);
	}
	else{
		status = SUCCESS;
		 strncpy(buffer,"my_string_extraction_replaces_data_in_my_string\n",length);
	}
	free(testString);
	fclose(fp);
	my_string_destroy(&hString);
	return status;
}//end my_string_extraction_replaces_data_in_my_string


Status test_get_capacity_on_init_default_returns_7(char* buffer, int length){
	Status status;
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	if(my_string_get_capacity(hString)!=7){
		status = FAILURE;
		printf("Expected capacity 7, instead got %d\n",(my_string_get_capacity(hString)));
	   strncpy(buffer,"test_get_capacity_on_init_default_returns_7\n"
			"Failed to return capacity 7\n",length);	
	}
	else{
		status = SUCCESS;
		strncpy(buffer,"test_get_capacity_on_init_default_returns_7\n",length);
	}
	my_string_destroy(&hString);
	return status;
}//end test_get_capacity_on_init_default_returns_7







