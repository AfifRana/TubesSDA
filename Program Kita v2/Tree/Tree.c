#include<stdio.h>
#include<stdlib.h>
#include <String.h>
#include"tree.h"

/* ----------------------------------------------------- */
address allocNode(String s, int count, int fileIndex) {
	/* Deskripsi Modul :  */
	
	address P = (address)malloc(sizeof(Node));
	
	if (P != Nil){
		P->kata.string = (char*)malloc(sizeof(char) * (s.used+1));
		strcpy(P->kata.string, s.string);
		
//		count++;
//		printf ("Alokasi ke-%d \nP kata : %s \nS string : %s \n\n", count, P->kata.string, s.string);
		P->firstCount = allocCount(count, fileIndex);
//		insertInt(count, &P->count, fileIndex);
		P->parent = Nil;
		P->left = Nil;
		P->right = Nil;
	}
	return P;
}

void createTree(Tree *tree) {
	/* Deskripsi Modul :  */
	
	tree->root1 = Nil;
	tree->root2 = Nil;
}

/* ----------------------------------------------------- */
int size(address P) {
/* Menghitung jumlah size dari Tree */
	if(P->left==Nil && P->right==Nil){
		return 1; //leaves
	} else if (P->left !=Nil && P->right==Nil){
			return 1+size(P->left);
	} else if(P->right !=Nil && P->left==Nil){
			return 1+size(P->right);
	} else {
		return 1+size(P->left)+size(P->right);
	}
}

int getBalancingFactor (address pivot) {
	/* Deskripsi Modul :  */
	int rightHeight, leftHeight;
	
	if (pivot == Nil)
		return 0;
	else {
		if (pivot->right == Nil)
			rightHeight = 0;
		else 
			rightHeight = pivot->right->height + 1;
			
		if (pivot->left == Nil)
			leftHeight = 0;
		else 
			leftHeight = pivot->left->height + 1;
		
		return leftHeight - rightHeight;
	}
}

address rotateRight (address pivot) {
	/* Deskripsi Modul :  */
	address P;
	
	P = pivot->left;
	pivot->left = P->right;
	P->right = pivot;
	pivot->height = setHeight(pivot);
	P->height = setHeight (P);
	
	return P;
}

address rotateLeft (address pivot) {
	/* Deskripsi Modul :  */
	address P;
	
	P = pivot->right;
	pivot->right = P->left;
	P->left = pivot;
	pivot->height = setHeight (pivot);
	P->height = setHeight (P);
	
	return P;
}

address RR (address pivot) {
	/* Deskripsi Modul :  */
	
	pivot = rotateLeft (pivot);
	return pivot;
}

address RL (address pivot) {
	/* Deskripsi Modul :  */
	
	pivot->right = rotateRight (pivot->right);
	pivot = rotateLeft (pivot);
	return pivot;
}

address LL (address pivot) {
	/* Deskripsi Modul :  */
	
	pivot = rotateRight (pivot);
	return pivot;
}

address LR (address pivot) {
	/* Deskripsi Modul :  */
	
	pivot->left = rotateLeft (pivot->left);
	pivot = rotateRight (pivot);
	return pivot;
}

int setHeight (address pivot) {
	/* Deskripsi Modul :  */
	int rightHeight, leftHeight;
	
	if (pivot == Nil)
		return 0;
	else {
		if (pivot->right == Nil)
			rightHeight = 0;
		else 
			rightHeight = pivot->right->height + 1;
			
		if (pivot->left == Nil)
			leftHeight = 0;
		else 
			leftHeight = pivot->left->height + 1;
		
		return (rightHeight > leftHeight) ? rightHeight : leftHeight;
	}
}

address insertTree (address pivot, String *s, int fileIndex) {
	/* Deskripsi Modul :  */
	int defaultCount = 1;
	
	if (pivot == Nil) { // get nothing in tree
		pivot = allocNode(*s, defaultCount, fileIndex);
		
	} else if (strcmp(s->string, pivot->kata.string) > 0) { // insert right subtree
		pivot->right = insertTree (pivot->right, s, fileIndex);
		if (getBalancingFactor(pivot) == -2) // Penentuan toleransi keseimbangan subtree kanan - kiri
			if (strcmp(s->string, pivot->right->kata.string) > 0) // 
				pivot = RR (pivot);
			else if (strcmp(s->string, pivot->right->kata.string) < 0) //
				pivot = RL (pivot);
				
	} else if (strcmp(s->string, pivot->kata.string) < 0) { // insert left subtree
		pivot->left = insertTree (pivot->left, s, fileIndex);
		if (getBalancingFactor(pivot) == 2)
			if (strcmp(s->string, pivot->left->kata.string) < 0) // 
				pivot = LL (pivot);
			else if (strcmp(s->string, pivot->left->kata.string) > 0) // 
				pivot = LR (pivot);
				
	} else if (strcmp(s->string, pivot->kata.string) == 0) { // the same value
		insertInt(1, &pivot->firstCount, fileIndex);
		
	}
	pivot->height = setHeight(pivot);
	
	return pivot;
}

void travInOrderStat (address pivot, CheckSet *checkSet) { // Modularitas benerin ya.. sama yang InOrder set lainnya
	/* Deskripsi Modul :  */
	
	/* Pertama, kita mulai dari predecessor InOrder root dan tentukan apakah root memiliki nilai count yang kita cari;
	 * Kedua, bila iya, maka masukkan ke field, jika tidak lanjut ke successornya;
	 */
//	printf ("\ntes..\n");
	if (pivot != Nil) {
//		printf ("\ntes.. please masuk..\n");
		travInOrderStat(pivot->left, checkSet);
		if (getCount(pivot->firstCount, checkSet->idFile1) > getCount(pivot->firstCount, checkSet->idFile2)) {
			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile1);
//			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile2);	
//			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
		} else if (getCount(pivot->firstCount, checkSet->idFile1) < getCount(pivot->firstCount, checkSet->idFile2)) {
			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile2);
//			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile1);	
//			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
		} else if (getCount(pivot->firstCount, checkSet->idFile1) == getCount(pivot->firstCount, checkSet->idFile2)) {
			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile2);
//			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile1);	
//			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
		}
		travInOrderStat(pivot->right, checkSet);
	}	
}

void printInOrder (address pivot, int fileIndex) {
	/* Deskripsi Modul :  */
	
	if (pivot != Nil) {
		printInOrder(pivot->left, fileIndex);
//		printf ("\nTes Print In Order : \n");
		if (getCount(pivot->firstCount, fileIndex) != 0)
			printf ("%s freq=> %d\n", pivot->kata.string, getCount(pivot->firstCount, fileIndex));
//		printf ("\n");
		printInOrder(pivot->right, fileIndex);
	}
}

address searchLR (address pivot, char* string) {
	/* Deskripsi Modul :  */
	address P;
	
	if (pivot == Nil) {
//		printf ("\nYes 4\n") ;
		P = Nil;	
	} else if (strcmp(string, pivot->kata.string) > 0) {
//		printf ("\nYes 1\n") ;
		P = searchLR (pivot->right, string);	
	} else if (strcmp(string, pivot->kata.string) < 0) {
//		printf ("\nYes 2\n") ;
		P = searchLR (pivot->left, string);	
	} else if (strcmp(string, pivot->kata.string) == 0) {
//		printf ("\nYes 3\n") ;
		P = pivot;	
	}
	return P;
}

address searchPosition (String s, address trav) {
	/* Deskripsi Modul :  */
	int cmp;
	
	if (trav == Nil) {
		return trav;
	} else {
		cmp = strcmp (trav->kata.string, s.string);
		
//		if (cmp == 0) {
//			return tStop->current;
//		} else if (cmp == -1 && tStop->current->left)
		
	 	switch (cmp) {
			case 0 :
//				tStop->current.count1 
				return trav;
				break;
			case -1 :
				if (trav->left == Nil)
					return trav;
					else return searchPosition (s,trav->left);				
				break;
			case 1 :
				if (trav->right == Nil)
					return trav;
					else return searchPosition (s,trav->right);
				break;		
		}
	}
}

void makeTree (String *s, Tree *tree, int fileIndex) {
	/* Deskripsi Modul :  */
	
//	if (P != Nil) {
//		if (tStop->root == Nil) {
//			tStop->root = allocNode(*s,1,0);
//		} else {
//			trav = searchPosition(*s, tStop->root); // akhir
//		}
//	}
}

