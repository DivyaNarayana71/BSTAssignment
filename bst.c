#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stddef.h>
#include "bst.h"
#include "queue.h"

BST bst_new()
{
	BST t = {NULL, 0};
	return t;
}

treeNode* _make_new_node(int32_t element)
{
	treeNode *new_tree_node = (treeNode*)malloc(sizeof(treeNode));
	new_tree_node->data = element;
	new_tree_node->left = NULL;
	new_tree_node->right = NULL;

	return new_tree_node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree != NULL);
	return tree->mass;
}

BST* bst_add_node(BST *tree, int32_t element)
{
	assert(tree != NULL);
	treeNode *cur, *parent;
	cur = parent = tree->root;
	while(cur != NULL && cur->data != element)
	{
		parent = cur;
		if(element < cur->data)
		{
			cur = cur->left;
		}
		else if(element > cur->data)
		{
			cur = cur->right;
		}
	}
	if(cur == NULL)
	{
		treeNode *tnode = _make_new_node(element);
		if(parent == NULL)
		{
			tree->root = tnode;
		}
		else if(element < parent->data)
		{
			parent->left = tnode;
		}
		else if(element > parent->data)
		{
			parent->right = tnode;
		}
		++tree->mass;
	}
	return tree;
}

uint32_t bst_lookup(BST *tree, int32_t key)
{
	assert(tree != NULL);
	treeNode *cur = tree->root;
	while(cur != NULL && cur -> data != key)
	{
		if(key < cur->data)
		{
			cur = cur->left;
		}
		else if(key >  cur->data)
		{
			cur = cur->right;
		}
		return (cur != NULL);
	}
}

BST* bst_delete(BST *tree, int32_t element)
{
	assert(tree != NULL);
	tree->root = _delete_(tree, tree->root, element);
	return tree;
}

static treeNode* _delete_(BST *tree, treeNode *node, int32_t key)
{
	treeNode *temp;
	if(node == NULL)
	{
		return node;
	}
	else if(key < node->data)
	{
		node->left = _delete_(tree, node -> left, key);
	}
	else if(key > node->data)
	{
		node->right = _delete_(tree, node -> right, key);
	}
	else if(node->left && node->right)
	{
		temp = _findmin_(node->right);
		node->data = temp->data;
		node->right = _delete_(tree, node->right, node->data);
	}
	else
	{
		temp = node;
		if(node->right == NULL)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
		free(temp);
		--tree->mass;
	}
	return node;
}

static treeNode* _findmin_(treeNode *node)
{
	if(node->left == NULL)
	{
		return node;
	}
	else
	{
		return(_findmin_(node->left));
	}
}

void bst_inorder(BST *tree)
{
	assert(tree->root != NULL);
	_inorder_(tree->root);
}

static void _inorder_(treeNode *node)
{
	if(node)
	{
		_inorder_(node->left);
		printf("%d\t", node->data);
		_inorder_(node->right);
	}
}

void bst_preorder(BST *tree)
{
	assert(tree->root != NULL);
	_preorder_(tree->root);
}

static void _preorder_(treeNode *node)
{
	if(node)
	{
		printf("%d\t", node->data);
		_preorder_(node->left);
		_preorder_(node->right);
	}
}

void bst_postorder(BST *tree)
{
	assert(tree->root != NULL);
	_postorder_(tree->root);
}

static void _postorder_(treeNode *node)
{
	if(node)
	{
		_postorder_(node->left);
		_postorder_(node->right);
		printf("%d\t", node->data);
	}
}


void tree_levelorder(BST *t)
{
	assert(t->root!=NULL);
	listOfNumbers *temp;
	Queue Tree_queue = queue_new(t->count);
	Queue *queue = &Tree_queue;
	Queue_Result *res = (Queue_Result*) malloc(sizeof(Queue_Result));
	queue = queue_add(queue,t->root,res);
	while(queue->count!=0)
	{
		queue_delete(queue,res);
		temp = res->data;

		// having issue accessing res->data
		if(temp->left!=NULL)
		{	
			queue_add(queue,temp->left,res);
		}
		if(temp->right!=NULL)
		{
			queue_add(queue,temp->right,res);
		}
		printf("%d \t",temp->data);
	}
	printf("\n");
}


static int32_t max_height(treeNode *n)
{
	int32_t left_height=0;
	int32_t right_height = 0;
	//printf("%d \n",n->data);
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		//printf("%d \n",left_height);
		if(n->left!=NULL){
		left_height = max_height(n->left);
	}
	if(n->right!=NULL){
		right_height = max_height(n->right);

	}
	if(left_height>right_height)
	{
		return left_height+1;
	}
	else
	{
	return right_height+1;
	}
}
}


int32_t tree_height(BST *t)
{
	assert(t!=NULL);
	//int left_height,right_height = 0;
	int32_t max = max_height(t->root);
	return max;
}


int32_t find_min(BST *t)
{
	assert(t!=NULL);
	treeNode *temp=t->root;
	while(temp->left!=NULL)
	{
		temp= temp->left;
	}
	return(temp->data);
}

int32_t find_max(BST *t)
{
	assert(t!=NULL);
	treeNode *temp=t->root;
	while(temp->right!=NULL)
	{
		temp = temp->right;
	}
	return(temp->data);
}

static void _ascending_(treeNode *n)
{
	if(n)
	{
		_ascending_(n->left);
		printf("%d\t",n->data);
		_ascending_(n->right);
	}
}

void tree_ascending(BST *t)
{
	assert(t!=NULL);
	_ascending_(t->root);
}

static void _descending_(treeNode *n)
{
	if(n)
	{
		_descending_(n->right);
		printf("%d\t",n->data);
		_descending_(n->left);
	}
}

void tree_descending(BST *t)
{
	assert(t!=NULL);
	_descending_(t->root);
}


static int32_t _terminals_(treeNode *n)
{
	int32_t count1 = 0;
	int32_t count2 = 0;
	
	if(n==NULL)
		{return 0;}
	if (n->left==NULL && n->right==NULL)
	{
		return 1;
	}
	else
	{
		if(n->left!=NULL)
		{
		count1 = _terminals_(n->left);
		}
		if(n->right!=NULL)
		{
			count2 = _terminals_(n->right);
		}			
		//count++;
		return count1+count2;
	}
}

int32_t terminal_nodes(BST *t)
{
	assert(t!=NULL);
	int32_t count=0;
}
	