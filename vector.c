
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "my_string.h"
#include "vector.h"


//Known type
typedef struct Vector {
	int size; //num items in array
	int capacity; //total length of array
	MY_STRING* data;
}Vector;


VECTOR init_default(void){
	Vector* pVector;
	pVector = (Vector*)malloc(sizeof(Vector));
	if (pVector != NULL) {
		pVector->size = 0;
		pVector->capacity = 10;
		pVector->data = (MY_STRING*)malloc(sizeof(MY_STRING)*(pVector->capacity));
		for(int i = 0; i<pVector->capacity; ++i){
			pVector->data[i]=my_string_init_default;
		}
	}
	return (VECTOR)pVector;
}

Boolean is_Empty(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;
	if(pVector->size==0){
		printf("%d\n",pVector->size);
		return FALSE;
	}
	return TRUE;
	
}

char* return_data_at_as_c_str(VECTOR hVector, int index) {
	Vector* pVector = (Vector*)hVector;
	if (!is_Empty(hVector)) {
			//my_string_insertion(pVector->data[index],stdout);
		return my_string_c_str(pVector->data[index]);
	}
return NULL;
}
MY_STRING return_data_at_as_MY_STRING(VECTOR hVector, int index) {
	Vector* pVector = (Vector*)hVector;
	
			//my_string_insertion(pVector->data[index],stdout);
		return (pVector->data[index]);

}
void print_data_at(VECTOR hVector, int index) {
	Vector* pVector = (Vector*)hVector;
	if (!is_Empty(hVector)) {
		my_string_insertion(pVector->data[index],stdout);
		//return hVector->data[index];
	}
return;
}

void destroy(VECTOR* phVector) {
	Vector* pVector = (Vector*)*phVector;
	//free((pVector)->data);
	if(phVector==NULL)
		return;
	for(int i = 0; i<pVector->size;++i){
		my_string_destroy(&(pVector->data[i]));
	}
	free(pVector->data);
	free(pVector);
}

int getCapacity(VECTOR phVector) {
	Vector* pVector = (Vector*)phVector;
	return pVector->capacity;
}

int getSize(VECTOR phVector) {
	Vector* pVector = (Vector*)phVector;
	return pVector->size;
}

Status vector_push_back_c_str(VECTOR phVector, char* item) {
	Vector* pVector = (Vector*)phVector;
	MY_STRING *t_data=NULL;
	printf("Size: %d\n",pVector->size);
	if (pVector->size >= pVector->capacity) {
		t_data = (MY_STRING*)malloc(sizeof(MY_STRING)*pVector->capacity * 2)
;
		if (t_data == NULL) {
			return FAILURE;
		}
		int index = 0;
		for (int i = 0; pVector->data[i]!=NULL; ++i) {
			t_data[i] = my_string_init_default();
			//t_data[i] = pVector->data[i];//may need revision
			my_string_assignment(&(t_data[i]),pVector->data[i]);
			index = i;
		}
		for(int j = index;j<pVector->capacity;++j){
			pVector->data[j]= my_string_init_default();
		}
		free(pVector->data);
		pVector->data = t_data;
		pVector->capacity *= 2;
	}
	//add the data
	pVector->data[pVector->size] = my_string_init_c_string(item);
	if(strcmp(my_string_c_str(pVector->data[pVector->size]), item)!=0){
		return FAILURE;
	}
	
	pVector->size += 1;

	return SUCCESS;
}


Status vector_push_back_MY_STRING(VECTOR phVector, MY_STRING item) {
	Vector* pVector = (Vector*)phVector;
	MY_STRING *t_data= NULL;
	char* toAdd;
	if(item!=NULL){
		toAdd= my_string_c_str(item);
	}
	else{
		return FAILURE;
	}

	if (pVector->size >= pVector->capacity) {
                //printf("REALLOCATING VECTOR, size %d\n",pVector->size );
		//printVector(phVector);
		t_data = (MY_STRING*)malloc(sizeof(MY_STRING)*pVector->capacity * 2);
		if (t_data == NULL || item==NULL) {
			return FAILURE;
		}

		for (int i = 0; i < pVector->size; i++) {
			//t_data[i] = pVector->data[i];//may need revision
			t_data[i] = NULL;
			my_string_assignment(&(t_data[i]),(Item)pVector->data[i]);
			my_string_destroy(&pVector->data[i]);
			
		}
		
		free(pVector->data);
		pVector->data = t_data;
		pVector->capacity *= 2;
                //printVector(phVector);

	}
	//add the data
	pVector->data[pVector->size] = my_string_init_c_string(toAdd);
	/*if(strcmp(my_string_c_str(pVector->data[pVector->size]), item)!=0){
		return FAILURE;
	}*/

	pVector->size += 1;

	return SUCCESS;
}
void printVector(VECTOR phVector){
	Vector* pVector = (Vector*)phVector;
	if(pVector!=NULL){
		for(int i=0;i<pVector->size;i++){
			my_string_insertion(return_data_at_as_MY_STRING(phVector,i),stdout);
			printf("\n");
		}
	}
}

void copy_vector(VECTOR* hVector, VECTOR rVector){
	for(int i = 0; i<getSize(rVector);++i){
		vector_push_back_MY_STRING(*hVector,return_data_at_as_MY_STRING(rVector,i));
	}
}
