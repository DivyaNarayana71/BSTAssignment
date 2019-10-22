#include<stdio.h>
#include<assert.h>
#include "bst.c"

int main()
{
	BST b = bst_new();
	BST *bst = &b;

	int arrayOfEle[] = {50,70,30,20,45,65,80,90,25};
	for (int i = 0; i < 9; ++i)
	{
		bst = bst_add_node(bst, arrayOfEle[i]);
	}
	treeNode *tree = bst->root;
	printf("root of tree is %d %d\n", bst->mass, tree->data);
	printf("Inorder\n");
	bst_inorder(bst);
	printf("\npreorder\n");
	bst_preorder(bst);
	printf("\npostorder\n");
	bst_postorder(bst);
	return 0;
}