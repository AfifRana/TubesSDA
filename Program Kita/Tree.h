#ifndef tree_h
#define tree_h
#include "../String/String.h"
#define Nil NULL

typedef struct node *address;
typedef struct node {
	String kata;
	adr firstCount;
	int height;
	address left;
	address right;
	address parent;
} Node;

typedef struct tree {
	address root;
	address current;
} Tree;

/**/
void createTree(Tree *tree);
int size(address P);
int getBalancingFactor (address pivot);
address rotateRight (address pivot);
address rotateLeft (address pivot);
address RR (address pivot);
address RL (address pivot);
address LL (address pivot);
address LR (address pivot);
int setHeight (address pivot);
address insertTree (address pivot, String *s, int fileIndex);
void printInOrder (address pivot, int fileIndex);
address searchLR (address pivot, char* string);
void makeTree (String *s, Tree *tree, int fileIndex); // siap hapus


#endif
