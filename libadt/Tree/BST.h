struct BSTNode; //Opaque binary search tree node type definition

struct BSTNode* BSTConst(int rootValue); //Binary search tree constructor

void BSTDest(struct BSTNode* node); //Destructor

void BSTInsert(struct BSTNode* node, int entity); //Insert method

int BSTGetMax(struct BSTNode* root); //Get max value in binary search tree

int BSTGetMin(struct BSTNode* root); //Get min value in binary search tree

int BSTSearch(struct BSTNode* node, int value);

void BSTTraverseInOrder(struct BSTNode* node); //In-order traversal

int BSTDelete(struct BSTNode* node, int entity);