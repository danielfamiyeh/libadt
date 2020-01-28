#include <stdio.h>
#include <stdlib.h>

struct BST
{
    struct BSTNode* root;
};

struct BSTNode
{
    int val;
    struct BSTNode* left;
    struct BSTNode* rught;
};;
