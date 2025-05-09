#ifndef _B_PLUS_H_
#define _B_PLUS_H_

#include <stdio.h>
#include <stdlib.h>

#define ORDER 5
#define MIN_KEYS 3
#define MAX_KEYS 5

// Node Definition

typedef struct {
	int key;
  void *data;
} KeyData;

typedef struct node{
  char is_leaf;
  char num_keys;
  KeyData keys[ORDER-1];
  struct node *pointers[ORDER];
  struct node *next;
} node;

typedef struct {
	node *root;			// Root of the B+ tree
} bPlusTree;

// Function Pointer typedef

typedef int (*CompareFunc)(const node* left, const node *right);

// Functions 

node* create_leaf_node(char is_leaf);
node* find_leaf(node *curr,char key);
int compare_nodes(const node *left, const node *right);


// 

#endif
