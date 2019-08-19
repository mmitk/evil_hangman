#include "vector.h"
#include "generic.h"

int main(int argc, char* argv[]){
	///////////////////////////TEST 1:
	/*printf("VECTOR MAIN:\n");
	VECTOR v = NULL;
	v= init_default();
	MY_STRING s = NULL;
	s = my_string_init_c_string("Hello ");
	
	MY_STRING t = NULL;
	t = my_string_init_c_string("My ");

	MY_STRING u = NULL;
	u = my_string_init_c_string("Name ");

	MY_STRING x = NULL;
	x = my_string_init_c_string("is ");

	MY_STRING w = NULL;
	w = my_string_init_c_string("Roy ");
	if(
	!vector_push_back_MY_STRING(v,s)||
	!vector_push_back_MY_STRING(v,t)||
	!vector_push_back_MY_STRING(v,u)||
	!vector_push_back_MY_STRING(v,x)||
	!vector_push_back_MY_STRING(v,w)){
		printf("FUUUUUUUUUUUUUUUCK\n");
}

	for(int i =0;i<getSize(v);++i){
		my_string_insertion(return_data_at_as_MY_STRING(v,i),stdout);
	}
	destroy(&v);
	my_string_destroy(&s);
	my_string_destroy(&t);
	my_string_destroy(&u);
	my_string_destroy(&x);
	my_string_destroy(&w);*/
/********************LAB 8 CHECKPOINT 1
///////////////////////////////*/
	FILE* fp = fopen("dictionary.txt","r");
	MY_STRING tempOBJ = NULL;
	tempOBJ = my_string_init_default();
	
	VECTOR* vectorArray = (VECTOR*)malloc(sizeof(VECTOR)*30);
	for(int i =0; i<30;++i){
		vectorArray[i] = init_default();
	}
	
	int stringSize;
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
	int sum = 0;
	for(int i=0;i<30;++i){
		printf("number of words in vector of Length %d: %d\n",i+1,getSize(vectorArray[i]));
		//printVector(vectorArray[i]);
		sum +=getSize(vectorArray[i]);
		destroy(&vectorArray[i]);
	}
	printf("Total: %d\n",sum);
	my_string_destroy(&tempOBJ);
	free(vectorArray);
	fclose(fp);
	return 0;
}

