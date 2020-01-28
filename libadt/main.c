#include <stdio.h>
#include <stdlib.h>

#include "Tree/BST.h"

int main()
{
    struct BSTNode* root = BSTConst(3);

    BSTInsert(root, 5);
    BSTInsert(root, 2);
    //BSTInsert(root, 9);
    
    BSTTraverseInOrder(root);
    BSTDelete(root, 2);
    printf("\n");
    BSTTraverseInOrder(root);

    BSTDest(root);
    return 0;
}