//Binary Search Tree Implementation

#include <stdlib.h>
#include <stdio.h>

struct BSTNode
{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
};

struct BSTNode* BSTConst(int rootValue)
{
	struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
	node->data = rootValue;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void BSTDest(struct BSTNode* node)
{
	if(node)
	{
		BSTDest(node->left);
		BSTDest(node->right);
		free(node);
	}
}

void BSTInsert(struct BSTNode* node, int value)
{
	if(value >= node->data)
	{
		if(node->right == NULL)
		{
			node->right = BSTConst(value);
		}
		else
		{
			BSTInsert(node->right, value);
		}
	}
	else
	{
		if(node->left == NULL)
		{
			node->left = BSTConst(value);
		}
		else
		{
			BSTInsert(node->left, value);
		}
	}
}

int BSTGetMax(struct BSTNode* root)
{
	struct BSTNode* current;
	struct BSTNode* next = root;
	int max = 0;

	while(next)
	{
		current = next;
		max = current->data;
		next = current->right;
	}

	return max;	
}

int BSTGetMin(struct BSTNode* root)
{
	struct BSTNode* current;
	struct BSTNode* next = root;
	int min = 0;

	while(next)
	{
		current = next;
		min = current->data;
		next = current->left;
	}

	return min;
}


int BSTSearch(struct BSTNode* node, int value)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		if(value > node->data)
		{
			BSTSearch(node->right, value);
		}
		else if(value < node->data)
		{
			BSTSearch(node->left, value);
		}
		else
		{
			return 1;
		}

	}
}

struct BSTNode* getInOrderSuccessor(struct BSTNode* subtree)
{
	struct BSTNode* current;
	struct BSTNode* next = subtree;

	while(next)
	{
		current = next;
		next = current->left;
	}

	return next;
}

void deleteNode(struct BSTNode* node)
{
	//If node has no children or only one
	if(node->left == NULL || node->right == NULL)
	{
		free(node);	
	}

	//If node has two children
	else
	{
	//	struct BSTNode* inOrderSuccessor = getInOrderSuccessor(node);
	//	node->data = inOrderSuccessor->data;
	//	free(inOrderSuccessor);
	}
}


int BSTDelete(struct BSTNode* node, int entity)
{
	struct BSTNode* current;
	struct BSTNode* next = node;

	while(next)
	{
		current = next;

		if(entity > current->data)
		{
			printf("larger\n");
		}

		if(entity < current->data)
		{
			printf("less\n");
		}

		if(entity == current->data)
		{
			printf("equal\n");
			printf("%d", current->data);
		}

		next = current->right;
	}
}

void BSTTraverseInOrder(struct BSTNode* node)
{
	if(node != NULL)
	{
		BSTTraverseInOrder(node->left);
		printf("%d\n", node->data);
		BSTTraverseInOrder(node->right);
	}
}