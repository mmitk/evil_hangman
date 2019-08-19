#include "my_string.h"


int main(int argc, char* argv[]){
	MY_STRING* stringArray = (MY_STRING*)malloc(sizeof(MY_STRING)*100);
	for(int i =0; i<100;++i){
		stringArray[i]=NULL;
	}
	stringArray[0]=my_string_init_c_string("COPY ME!");
	for(int i =1; i<100; ++i){
		my_string_assignment(&stringArray[i], stringArray[i-1]);
	}
	for(int i =0; i<100; ++i){
		my_string_insertion(stringArray[i],stdout);
		my_string_destroy(&stringArray[i]);
	}
	free(stringArray);
	return 0;
}
