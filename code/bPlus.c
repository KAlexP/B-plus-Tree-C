#include "bPlus.h"

node* create_leaf_node(char is_leaf){
	node* NewNode = (node*)malloc(sizeof(node));
  NewNode->is_leaf = is_leaf;
  NewNode->num_keys=0;
  NewNode->next = NULL;
  for(int i = 0; i < ORDER; ++i) NewNode->pointers[i] = NULL;
  return NewNode;
}

node* insert(bPlusTree* tree, char key, void* data){
	if(!tree->root){
		tree->root = create_leaf_node(0);
    tree->root->keys[0] = (KeyData){key,data};
    tree->root->num_keys = 1;
    return tree->root;
  }
  node *leaf = find_leaf(tree->root, key);
   if (leaf->num_keys < ORDER - 1) {
		int i = leaf->num_keys - 1;
    while(i >= 0 && leaf->keys[i].key > key){
			leaf->keys[i+1] = (KeyData){key, data};
      --i;
    }
    leaf->keys[i+1] = (KeyData){key, data};
    leaf->num_keys++;
   }

   node *new_leaf = create_leaf_node(0);
   KeyData temp[ORDER];
   for(int i = 0; i < ORDER -1; ++i) temp[i] = leaf->keys[i];
   temp[ORDER - 1] = (KeyData){key, data};

   leaf->num_keys = ORDER / 2;
   new_leaf->num_keys = ORDER - (ORDER / 2);
   for(int i=0;i < ORDER - 1; ++i) leaf->keys[i] = temp[i];

}
