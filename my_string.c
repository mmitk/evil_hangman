#ifndef MY_STRING_C
#define MY_STRING_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

typedef struct My_string {
	int size;
	int capacity;
	char* data;

}My_string;



MY_STRING my_string_init_default(void){
  My_string* pString =(My_string*)malloc(sizeof(My_string));
  pString->size = 0;
  pString->capacity=7;
  pString->data =(char*)malloc(sizeof(char)*pString->capacity);
  if (pString->data == NULL) {
	   free(pString);
	   return NULL;
  }
  
  return(MY_STRING)pString;
}//end  my_string_init_default

void my_string_destroy(MY_STRING* phMy_string){
  My_string* pString = (My_string*)*phMy_string;
  if(pString){
    if(pString->data){
      free(pString->data);
      free(pString);
    }
  }
  *phMy_string = NULL;
}//end my_string_destroy

MY_STRING my_string_init_c_string(const char* c_string){
   My_string* pString =(My_string*)malloc(sizeof(My_string));
	if(pString==NULL){
		printf("my_string_init_c_string failed to allocate memory\n");
	}
    pString->size = strlen(c_string);
  pString->capacity= strlen(c_string)+1;
  pString->data =(char*)malloc(sizeof(char)*(pString->capacity));
	if(pString->data==NULL){
		printf("my_string_init_c_string failed to allocate memory(for string array)\n");
	}
  int i;
  for(i = 0; i<pString->size; i++){
    pString->data[i]=c_string[i];
  }
  pString->data[pString->size]='\0';
  return(MY_STRING)pString;
}//end my_string_init_c_string

int my_string_get_capacity(MY_STRING hMy_string){
  My_string* pString =(My_string*)hMy_string;
  return pString->capacity;
}//end my_string_get_capacity

int my_string_get_size(MY_STRING hMy_string){
  My_string* pString =(My_string*)hMy_string;
  return pString->size;
}//end my_string_get_size

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
  My_string* leftString =(My_string*)hLeft_string;
  My_string* rightString =(My_string*)hRight_string;
  int i=0;
  if(leftString->data[i]==rightString->data[i]){
  while(leftString->data[i]==rightString->data[i]){
    if (leftString->data[i] == '\0'){
            return 0;
    }
    i++;
  }}
   return (int) (leftString->data[i] - rightString->data[i]);
}//end my_string_compare

void print_my_string(MY_STRING phMy_string){
  My_string* pString = (My_string*)phMy_string;
  for(int i = 0; i<pString->size;i++){
    printf("%c", pString->data[i]);
  }
   printf("\n");
}//print_my_string

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
 
  My_string* pString = (My_string*)hMy_string;
 
  if(fp == NULL||feof(fp)||pString==NULL){
    return FAILURE; 
  }

  //clear data in hMy_string
  char* tempString = (char*)malloc(sizeof(char)*7);
  free(pString->data);
  pString->data = tempString;
  pString->capacity = 7;
  pString->size = 0;
    
  char c;
  c = fgetc(fp);
  // printf("Char %c\n",c);
  //Check for whitespace
  while((c==' ') ||(c=='\t')||(c=='\n')||(c=='\v') || (c == '\r')){
    if(c == EOF){
    return FAILURE;
     }
    c = fgetc(fp);
    
  }

  char* tempData;

  //
  int i = 0;
  while(c!=' ' && c!='\t' && c!= EOF && (c!='\n')&&(c!='\v')&&(c != '\r')){

    pString->size++;

    //checks if pString->data is large enough
    if(pString->size + 1 >= pString->capacity){
      //create temp char array
      tempData = (char*)malloc(sizeof(char)*(pString->size * 2));
      if(tempData == NULL){
	return FAILURE;
      }//end inner if
      
      for(int j = 0; j < pString->size;j++){
	tempData[j] = pString->data[j];
      }//end for loop
      free(pString->data);
      pString->data = tempData;
      pString->capacity = (pString->size*2);
     
      //free(tempData);
      
      }//end if

    pString->data[i] = c;
    c = fgetc(fp);
    i++;
  }//end while loop
  
  pString->data[i] = '\0';
  //pString->size++;
  if(c != EOF){
    int pos = ftell(fp);
    // printf("pos %d\n", pos);
    fseek(fp,pos-1,SEEK_SET);
  }
  //print_my_string(hMy_string);
  //printf("size: %d", pString->size);
  // print_my_string(hMy_string);
  return SUCCESS;
}//end my_string_extraction

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
  My_string* pString = (My_string*)hMy_string;
  if(pString == NULL){
    return FAILURE;
  }//end if
  
  for(int i = 0; i<pString->size;i++){
    fputc(pString->data[i],fp);
  }//end for loop
  return SUCCESS;
}//end my_string_insertion

Status my_string_push_back(MY_STRING hMy_string, char item){
  My_string* pString = (My_string*)hMy_string;
  int s_size = pString->size;
  if(s_size>=pString->capacity-1){
    char* temp_string = (char*)malloc(sizeof(char)*(pString->capacity*2));
    if(temp_string == NULL){
      return FAILURE;
    }//end inner if statement
    for(int i =0; i<pString->size;i++){
      temp_string[i]=pString->data[i];
    }//end for loop
    free(pString->data);
    pString->data=temp_string;
    pString->capacity = pString->capacity*2;
  }//end if

  pString->data[s_size] = item;
  pString->size++;
  if(!(pString->size==pString->capacity))
  	pString->data[pString->size]='\0';
  return SUCCESS;
}//my_string_push_back

Status my_string_pop_back(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  if(pString->size==0){
    return FAILURE;
  }

  pString->size--;
  return SUCCESS;
}//my_string_pop_back

char* my_string_at(MY_STRING hMy_string, int index){
  My_string* pString = (My_string*)hMy_string;
  if (pString != NULL) {
    if ((index >= 0) && (index < pString->size)) {
      return &pString->data[index];
      }
  }
  return NULL; 
}//my_string_at

char* my_string_c_str(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  int size = pString->size;
  if(pString->data[size]!= '\0'){
    pString->data[size] = '\0';
  }

  return pString->data;
}//my_string_c_str

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;
  char* tempstr;
  if(pResult==NULL||pAppend==NULL){
	return FAILURE;
}
  int new_size = (pResult->size)+(pAppend->size);
  
  if(new_size>pResult->capacity-2){
    tempstr = (char*)malloc(sizeof(char)*(new_size*2));
    if(tempstr == NULL){
      return FAILURE;
    }//end inner if
    pResult->capacity = new_size * 2;
  }//end outer if
  else{
    tempstr = (char*)malloc(sizeof(char)*pResult->capacity);
    if(tempstr == NULL){
      return FAILURE;
    }//end if
  }//end else
  
  int tempIndex;
  for(int i=0; i<pResult->size; i++){
    tempstr[i] = pResult->data[i];
    //printf("%c",pResult->data[i]);
    tempIndex = i;
  }
  tempIndex++;
  for(int j = 0; j<pAppend->size;j++){
    tempstr[tempIndex]=pAppend->data[j];
    tempIndex++;
  }

  free(pResult->data);
  pResult->data = tempstr;
  pResult->size = new_size;
  pResult->data[pResult->size]='\0';
  return SUCCESS;
  
}//my_string_concat

Boolean my_string_empty(MY_STRING hMy_string){
  My_string* pString =(My_string*)hMy_string;
  if(pString->size == 0){
    return TRUE;
  }
  return FALSE;
}//my_string_empty


void my_string_assignment(Item* pLeft, Item Right){
	//My_string* pRight = (My_string*)Right;
	//if(pRight == NULL)
		//return;
	//My_string* phLeft=NULL;
	//int rSize = pRight->size;
	//int rCapacity = pRight->capacity;
	if(*pLeft==NULL){
		*pLeft=my_string_init_c_string(my_string_c_str(Right));
		/*phLeft = (My_string*)malloc(sizeof(My_string));
		phLeft->size=rSize;
		char* temp=(char*)malloc(sizeof(char)*rCapacity);
		for(int i =0; i< rSize; i++){
			temp[i] = pRight->data[i];
		}
		phLeft->data=temp;
		phLeft->capacity=rCapacity;
		*pLeft = (Item)phLeft;*/
                //printf("ERROR!!!! DESINATION POINTER IS NULL\n");
		return;
	}	
	else{
		//my_string_destroy(pLeft);
		*pLeft=my_string_init_c_string(my_string_c_str(Right));
		return;
		
	}
	//phLeft = (My_string*)pLeft;
	/*//if(rCapacity!= phLeft->capacity || rSize != phLeft->size){
		char* tempString = (char*)malloc(sizeof(char)*rCapacity);
		for(int i = 0; i < rSize;++i){
			tempString[i]=pRight->data[i];
		}
		free(phLeft->data);
		phLeft->data=tempString;
		phLeft->size=rSize;
		phLeft->capacity=rCapacity;
		return;
	//}
	
	else{
		char* tempData = (char*)malloc(sizeof(char)*rCapacity);
		for(int i = 0; i<rSize;++i){
			tempData[i]=pRight->data[i];
		}
		free(phLeft->data);
		phLeft->data = tempData;
		phLeft->size=rSize;
		phLeft->capacity=rCapacity;
	}
	*pLeft = (Item)phLeft;*/
	//return;
}


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess){
	My_string* curFam = (My_string*)current_word_family;
	My_string* hWord = (My_string*)word;
	My_string* nkey = (My_string*)new_key;
	
	
	my_string_assignment(&new_key,current_word_family);
   
	
	char* curFamcstr = my_string_c_str(curFam);
	char* wordcstr = my_string_c_str(hWord);
	char* tempString = (char*)malloc(sizeof(char)*(hWord->size+1));
	for(int i = 0; i < hWord->size; ++i){
		tempString[i] = curFamcstr[i];
	}
	tempString[hWord->size]='\0';
	//tempString = my_string_c_str(current_word_family);


	for(int i = 0; i<hWord->size; i++){
		if(wordcstr[i]==guess){
			tempString[i] = guess;
		}
	}


for(int i = 0; i < hWord->size; ++i){
		nkey->data[i]=tempString[i];
	}
	//MY_STRING tmpString =my_string_init_default();
	//tmpString=my_string_init_c_string(tempString);
	//my_string_assignment(&new_key,tempString);
	//nkey->data[hWord->size]='\0';
	//new_key=my_string_init_c_string(tempString);
	tempString[hWord->size]='\0';
	nkey->size=curFam->size;
	nkey->capacity = curFam->capacity;
	//my_string_destroy(&tmpString);
	free(tempString);
	new_key = nkey;
	return SUCCESS;
}//end get_word_key_value
#endif

