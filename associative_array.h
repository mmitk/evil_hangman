#ifndef ASSOCIATIVE_ARRAY
#define ASSOCIATIVE_ARRAY
#include "my_string.h"
#include "vector.h"

typedef struct node Node;
struct node{
	Node* left;
	Node* right;
	int height;
	MY_STRING key;
	VECTOR words;
};


Node* node_init_default();
Node* node_init_key(MY_STRING key_passed, MY_STRING word);
int calc_height(Node* N);

int height(Node* N);

Node* right_rotate(Node* N);

Node* left_rotate(Node* N);

int bf(Node* N);
Status insert(Node** N, MY_STRING key, MY_STRING word);

void destroy_tree(Node** root);

void destroy_node(Node** node);

void print_tree_keys(Node* root);

void print_tree_words(Node* root);

void find_largest_fam_key(Node* root, Node** currMax);

VECTOR return_largest_word_fam(Node* root);

#endif
