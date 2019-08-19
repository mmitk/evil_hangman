#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"


//create opaque object
typedef void* VECTOR;


VECTOR init_default(void);
void destroy(VECTOR* phVector);//ph: pointer handler

//accessor 
int getCapacity(VECTOR phVector);
int getSize(VECTOR phVector);
void printVector(VECTOR phVector);
char* return_data_at_as_c_str(VECTOR phVector, int index); 
MY_STRING return_data_at_as_MY_STRING(VECTOR hVector, int index);
void print_data_at(VECTOR hVector, int index);

//
Status vector_push_back_c_str(VECTOR phVector, char* item); 
Status vector_push_back_MY_STRING(VECTOR phVector, MY_STRING item);
void pop(VECTOR phVector);
Boolean is_Empty(VECTOR phVector);
void copy_vector(VECTOR* hVector, VECTOR rVector);
#endif
