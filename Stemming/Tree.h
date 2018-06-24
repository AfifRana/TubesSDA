#ifndef Tree_h
#define Tree_h
#include<string.h>
#include "Count.h"
#include "Count.c"
#include "String.h"
#include "String.c"
#define Nil NULL

#include "String.h"

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

typedef struct checkSet {
	int idFile1;
	int idFile2;
	int sumOfGreater;
	int sumOfSmaller;
} CheckSet;

/**/
address allocNode(String s, int count, int fileIndex);
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
