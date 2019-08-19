
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "my_string.h"
#include "associative_array.h"
#define max(a,b) ((a)>(b) ? (a) : (b))



Node* node_init_default(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode!=NULL){
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->height=0;
		newNode->key = my_string_init_default();
		newNode->words=init_default();
		return newNode;
	}
	printf("Unable to allocate memory in node_init_default\n");
	return NULL;
}

Node* node_init_key(MY_STRING key_passed, MY_STRING word){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode!=NULL){
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->height=0;
		newNode->key = my_string_init_default();
		my_string_assignment(&(newNode->key),key_passed);
		newNode->words=init_default();
		vector_push_back_MY_STRING(newNode->words, word);
		return newNode;
	}
	printf("Unable to allocate memory in node_init_default\n");
	return NULL;
}


int calc_height(Node* N){
	int lh, rh;
	if(N==NULL){
		//printf("Node passed to get_height is NULL\n");
		return 0;
	}
	lh=calc_height(N->left)+1;
	rh=calc_height(N->right)+1;
	return(rh?rh>lh:lh);
}

int height(Node* N){
	if(N!=NULL){
		//return N->height;
		return calc_height(N);
	}
	return 0;
}


Node* right_rotate(Node* N)
{

    Node* x = N->left;
    Node* x_sub; 
    // Checking if sub tree is NULL
    if(NULL == x->right){
		x_sub = NULL;
	}
    else{
	x_sub= x->right;
	}
    // Perform rotation
    x->right = N;
    N->left = x_sub;
    // Update heights
    N->height = max(height(x->left), height(x->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // Return new root
    return x;

}


Node* left_rotate(Node* N)
{
    Node* y = N->right;
    Node* y_sub;//sub tree of
    // Are sub trees NULL?
    if(NULL == y->left){
	  y_sub =  NULL; 
	}
     else{
	   y_sub =  y->left;
          }
    // Perform rotation
    y->left = N;
    N->right = y_sub;
    // Update heights
    N->height = max(height(N->left), height(N->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // Return new root
    return y;

}

//finding balance factor:
int bf(Node* N)
{
    if (N== NULL) return 0;
    return height(N->right) - height(N->left);

}




Status insert(Node** N, MY_STRING key, MY_STRING word)
{
	//BST insertion(if root is null)
 	if((*N)==NULL){
		*N =node_init_key(key, word);
		return(SUCCESS?N!=NULL:FAILURE);
		}
	//BST insertion if root is not null
	if(my_string_compare(key,(*N)->key)<0){
			if(!(insert(&((*N)->left), key, word)))
				return FAILURE;
		}
	else if(my_string_compare(key,(*N)->key)>0){
			if(!insert(&((*N)->right), key, word))
				return FAILURE;
		}
	//if keys are equal, do not add new key to AVL tree, but add word to appropriate vector
	else{
		vector_push_back_MY_STRING((*N)->words, word);
		return SUCCESS;
	    }

	
	//Update height of parent node
	(*N)->height=height(*N);
	//Find balance factor
	int balance = bf(*N);

	//Check cases of balance
	//Left Left
	if (balance > 1 && (my_string_compare(key,(*N)->left->key)<0)) {
		*N=right_rotate(*N);
        	return SUCCESS; 
	}

	// Right Right  
        if (balance < -1 && (my_string_compare(key,(*N)->right->key)>0)) {
		*N=left_rotate(*N);
        	return SUCCESS; 
	}
  
	// Left Right  
    	if (balance > 1 && (my_string_compare(key,(*N)->left->key)>0)) 
    	{ 
        	(*N)->left =  left_rotate((*N)->left); 
        	*N=right_rotate(*N);
		return SUCCESS; 
    	} 
	
	 // Right Left 
    	if (balance < -1 && (my_string_compare(key,(*N)->right->key)<0)) 
    	{ 
        	(*N)->right = right_rotate((*N)->right);
		*N=left_rotate(*N); 
        	return SUCCESS; 
    	} 
  
	
	return SUCCESS;
}


void destroy_tree(Node** root){
	if(*root == NULL)
		return;
	destroy_tree(&((*root)->left));
	destroy_tree(&((*root)->right));
	destroy_node(root);
}

void destroy_node(Node** node){
	if(*node==NULL)
		return;
	//free((*node)->left);
	//free((*node)->right);
	my_string_destroy(&((*node)->key));
	destroy(&((*node)->words));
	free(*node);
}

//print tree in order
void print_tree_keys(Node* root){
	if(root==NULL)
		return
	print_tree_keys(root->left);
	printf("Key: ");
	my_string_insertion(root->key,stdout);
	printf("\n");
	print_tree_keys(root->right);
}

void print_tree_words(Node* root){
	if(root==NULL)
		return;
	print_tree_words(root->left);
	printf("Key: ");
	my_string_insertion(root->key,stdout);
	printf("..........Words:\n");
	printVector(root->words);
	print_tree_words(root->right);
}

void find_largest_fam_key(Node* root, Node** currMax){
	if(root==NULL){
		return;
	}
	if(*currMax == NULL)
		*currMax = root;
	else if(getSize((*currMax)->words)<getSize(root->words))
		*currMax = root;
	find_largest_fam_key(root->left, currMax);
	find_largest_fam_key(root->right, currMax);
	return;
}
/*int return_size_word_fam(MY_STRING key, Node* root){
	if(root==NULL)
		return -1;
	if(my_string_compare(key, root->key)==0)
		return (getSize(root->words));
	 int leftSearch =return_size_word_family(key,root->left); 
	 int rightSearch = return_size_word_family(key,root->right);
	return (leftSearch? leftSearch!=-1:rightSearch);
}*/

VECTOR return_largest_word_fam(Node* root){
	Node* tempMax;
	find_largest_fam_key(root, &tempMax);
	return tempMax->words;
}

