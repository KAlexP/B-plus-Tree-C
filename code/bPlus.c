#include "bPlus.h"



/*******************************************************************************
* Function Title: create_leaf_node
* Summary: This function creates a leaf node
*
* Inputs:
* 	char: this is just a small number that says if the node is a leaf or not
* Outputs:
* 	node *: a pointer to the newly created node
********************************************************************************
* Pseudocode
*   Begin
*			allocate memory 
*			set leaf to value passed in is_leaf
*			set num_keys to zero
*			set next to NULL 
*			loop through pointer with i
*				set pointer[i] to NULL
*			endloop 
*			return NewNode
*   End
*******************************************************************************/
node* create_leaf_node(char is_leaf){
	node* NewNode = (node*)malloc(sizeof(node));
  NewNode->is_leaf = is_leaf;
  NewNode->num_keys=0;
  NewNode->next = NULL;
  for(int i = 0; i < ORDER; ++i) NewNode->pointers[i] = NULL;
  return NewNode;
}


/*******************************************************************************
* Function Title: insert
* Summary: This function inserts a newly created node into the B+ tree.
*
* Inputs:
* 	bPlusTree *tree: the 'root' of the tree
* 	char key: the key for the data being stored
* 	void* data: the data being stored
* Outputs:
* 	node*: the new root if it had to change
********************************************************************************
* Pseudocode
*   Begin
*			if tree is empty
*				return new node as root
*			if new node is lower order 
*				set leaf keys 
*			
*   End
*******************************************************************************/
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
