#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>

typedef struct _tree_node_ treeNode;
typedef struct _bst_ BST;

struct _tree_node_
{
	int32_t data;
	treeNode *left;
	treeNode *right;
};

struct _bst_
{
	treeNode *root;
	uint32_t mass;
};

BST bst_new();
treeNode* _make_new_node(int32_t element);
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree, int32_t element);
uint32_t bst_lookup(BST *tree, int32_t key);
BST* bst_delete(BST *tree, int32_t element);
static treeNode* _findmin_(treeNode *node);
static treeNode* _delete_(BST *tree, treeNode *node, int32_t key);
void bst_inorder(BST *tree);
static void _inorder_(treeNode *node);
void bst_preorder(BST *tree);
static void _preorder_(treeNode *node);
void bst_postorder(BST *tree);
static void _postorder_(treeNode *node);


#endif