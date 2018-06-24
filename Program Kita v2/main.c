/* Deskripsi		:
 * Author			:
 * Tanggal / Versi	:
 * Kompilator		:
 ==================================================================== */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//#include "string/string.h"
//#include "count/count.h"
//#include "tree/tree.h"
//#define Nil NULL

//#include"count/count.h"
//#include"tree/tree.h"
//#include"string/string.h"

#include "include.h"

/* ============================= DATA STRUCTURE =============================== */

//typedef struct string {
//	char *string;
//  	int used;
//  	int size;
//} String;

//typedef struct count *adr;
//typedef struct count {
//	int idFile;
//	int value;
//	adr next;
//} Count;

//typedef struct count {
//	int *value;
//	int used;
//	int size;
//} Count;

//typedef struct node *address;
//typedef struct node {
//	String kata;
//	adr firstCount;
//	int height;
//	address left;
//	address right;
//	address parent;
//} Node;
//
//typedef struct tree {
//	address root;
//	address current;
//} Tree;

//typedef struct checkSet {
//	int idFile1;
//	int idFile2;
//	float sumOfGreater;
//	float sumOfSmaller;
//} CheckSet;

int countFile = 0;
/* ============================== MODUL SET ==================================== */
/* Memory */
//void createTree(Tree *tree);
//Count createCount (int initialSize);
//address allocNode(String s, int count, int fileIndex);
//String createString (int initialSize);

/* Count */
//void insertInt (int count, adr *firstNode, int fileIndex);
//int getCount (adr countNode, int fileIndex);

/* String */
//void insertChar(char c, String *s);
//void printString (String s);

/* Tree */
//int size(address P);
//int getBalancingFactor (address pivot);
//address rotateRight (address pivot);
//address rotateLeft (address pivot);
//address RR (address pivot);
//address RL (address pivot);
//address LL (address pivot);
//address LR (address pivot);
//int setHeight (address pivot);
//address insertTree (address pivot, String *s, int fileIndex);
//void printInOrder (address pivot, int fileIndex);
//address searchLR (address pivot, char* string);
//void makeTree (String *s, Tree *tree, int fileIndex); // siap hapus

/* File */
void openFile (String *s, address *pivTree, address pivStop, int fileIndex);

/* Similarity Check */
//float getSimilarityPercentage (CheckSet checkSet);
float similarityCheck (address pivot, CheckSet checkSet);

/* ========================= MEMORY CONTROLLER ================================= */
//void createTree(Tree *tree) {
//	/* Deskripsi Modul :  */
//	
//	tree->root = Nil;
//	tree->current = Nil;
//}

//adr allocCount (int count, int fileIndex) {
//	/* Deskripsi Modul :  */
//	
//	/* ------------- alloc yang baru ------------- */
//	adr c = (adr)malloc(sizeof(Count));
//	
//	if (c != Nil) {
//		c->idFile = fileIndex;
//		c->value = count;
//		c->next = Nil;
//	}
//	
//	/* ------------- Ini tutup dulu -----------------
//	
//	c.size = initialSize;
//	c.used = 0;
//	c.value = (int*)malloc(c.size*sizeof(int));
//	
//	for (i=0; i<c.size; i++)
//		c.value[0] = 0;
//		
//	------------------------------------------------- */	
//	return c;
//}

//address allocNode(String s, int count, int fileIndex) {
//	/* Deskripsi Modul :  */
//	
//	address P = (address)malloc(sizeof(Node));
//	
//	if (P != Nil){
//		P->kata.string = (char*)malloc(sizeof(char) * (s.used+1));
//		strcpy(P->kata.string, s.string);
//		
////		count++;
////		printf ("Alokasi ke-%d \nP kata : %s \nS string : %s \n\n", count, P->kata.string, s.string);
//		P->firstCount = allocCount(count, fileIndex);
////		insertInt(count, &P->count, fileIndex);
//		P->parent = Nil;
//		P->left = Nil;
//		P->right = Nil;
//	}
//	return P;
//}

//String createString (int initialSize) {
//	/* Deskripsi Modul :  */
//	String s;
//	int i;
//	
//	s.size = initialSize;
//	s.used = 0;
//	s.string = (char*)malloc(s.size * sizeof(char));
//	
//	for(i=0; i<s.size; i++)
//		s.string[i] = '\0'; // PENTING BANGET ASELI wkwk, kuduna mah make memset pun jadi
//		
//	return s;
//}

/* =========================== COUNT CONTROLLER ================================ */
//void insertInt (int count, adr *firstNode, int fileIndex) { // pengen dibuat priority queue
//	/* Deskripsi Modul :  */
//	adr preTrav = *firstNode, trav = *firstNode, pNew;
//	
//	/* ------------- Priority Queue -------------- */
//	if (trav == Nil) {
//		trav = allocCount(count, fileIndex);
//		*firstNode = trav;
//	} else if (fileIndex == trav->idFile) {
//		trav->value += count;
//	} else if (trav->idFile > fileIndex) {
//		/* insertFirst */
//		pNew = allocCount(count, fileIndex);
//		pNew->next = trav;
//		*firstNode = pNew;	
//	} else {
//		/* Insert After-Last */
//		while (trav != Nil && trav->idFile < fileIndex) {
//			preTrav = trav;
//			trav = trav->next;
//		}
//		
//		if (trav != Nil && trav->idFile == fileIndex) {
//			trav->value += count;
//		} else {
//			pNew = allocCount(count, fileIndex);
//			preTrav->next = pNew;
//			pNew->next = trav;	
//		}	
//	}
//	
//	/* ---------------- Ini ditutup dulu ----------------
//	if (fileIndex > c->used) {
//		c->used = fileIndex;
//		printf ("Used : %d\n", c->used);
//		printf ("FileIndex : %d\n", fileIndex);
//	}
//	
//	if (c->used == c->size || c->used > c->size) {
//		c->size = c->used + 1;
//		printf ("Size : %d\n", c->size);
//		c->value = (int*)realloc(c->value, c->size * sizeof(int));
//		c->value[c->used] = 0;
//	}
//	
//	if (idMaxFile < fileIndex) {
//		idMaxFile = fileIndex;
//		printf ("IdMax : %d\n", idMaxFile);
//		printf ("IdFile : %d\n", fileIndex);	
//	}
//	c->value[fileIndex] += number;
//	printf ("\n");
//	---------------------------------------------------- */
//}
//
//int getCount (adr countNode, int fileIndex) {
//	/* Deskripsi Modul :  */
//	
//	/* -------------- Linear Search ---------------- */
//	if (countNode == Nil) {
////		printf ("\nTes 1 \t val : %d \n ", 0);
//		return 0;
//	} else if (countNode->idFile == fileIndex) {
////		printf ("\nTes 2 \t val : %d \n", countNode->value);
//		return countNode->value;
//	} else {
//		int a = getCount(countNode->next, fileIndex);
////		printf ("\nTes 3 \t val : %d \n", a);
//		return a;
//	}
//	
//	/* ------------ Ini tutup dulu --------------------
//	
//	if (c.value[fileIndex] != 0 && c.used >= fileIndex)
//		return c.value[fileIndex];
//	else return 0;	
//	
//	------------------------------------------------ */
//}

/* ========================== STRING CONTROLLER ================================ */
//void insertChar(char c, String *s) {
//	/* Deskripsi Modul :  */
//	
//	if (s->used == s->size) {
//   	 	s->size *= 2;
//    	s->string = (char*)realloc(s->string, (s->size * sizeof(char)) + 1 ); // ditambahin satu ya buat si null / '\0'
//  	}
//	(*s).string[(*s).used++] = c;
//	(*s).string[(*s).used] = '\0';
////	printf ("%c ", c);
//	
//	/* Sementara */
////	int i;
////	printf ("\nTes : \n");
////	for (i=0;i<=s->size;i++) {
////		printf ("%c ", s->string[i]);
////	}
////	printf ("\n");
//}
//
//void printString (String s) {
//	/* Deskripsi Modul :  */
//	
//	int i;
////	for (i = 0; i < s.used+1; i++) {
////		printf ("%c", s.string[i]);
////	}
//	printf ("print : %s\n", s.string);
//}

bool cekStopword(String *s, address pivot) {
	/* Deskripsi Modul :  */
	address P;
	
	P = searchLR(pivot, s->string);
	if (P != Nil)
		return true;
	else 
		return false;	
}

/* ============================ TREE CONTROLLER ============================== */

/* Sementara */
//int size(address P) {
///* Menghitung jumlah size dari Tree */
//	if(P->left==Nil && P->right==Nil){
//		return 1; //leaves
//	} else if (P->left !=Nil && P->right==Nil){
//			return 1+size(P->left);
//	} else if(P->right !=Nil && P->left==Nil){
//			return 1+size(P->right);
//	} else {
//		return 1+size(P->left)+size(P->right);
//	}
//}
//
//int getBalancingFactor (address pivot) {
//	/* Deskripsi Modul :  */
//	int rightHeight, leftHeight;
//	
//	if (pivot == Nil)
//		return 0;
//	else {
//		if (pivot->right == Nil)
//			rightHeight = 0;
//		else 
//			rightHeight = pivot->right->height + 1;
//			
//		if (pivot->left == Nil)
//			leftHeight = 0;
//		else 
//			leftHeight = pivot->left->height + 1;
//		
//		return leftHeight - rightHeight;
//	}
//}
//
//address rotateRight (address pivot) {
//	/* Deskripsi Modul :  */
//	address P;
//	
//	P = pivot->left;
//	pivot->left = P->right;
//	P->right = pivot;
//	pivot->height = setHeight(pivot);
//	P->height = setHeight (P);
//	
//	return P;
//}
//
//address rotateLeft (address pivot) {
//	/* Deskripsi Modul :  */
//	address P;
//	
//	P = pivot->right;
//	pivot->right = P->left;
//	P->left = pivot;
//	pivot->height = setHeight (pivot);
//	P->height = setHeight (P);
//	
//	return P;
//}
//
//address RR (address pivot) {
//	/* Deskripsi Modul :  */
//	
//	pivot = rotateLeft (pivot);
//	return pivot;
//}
//
//address RL (address pivot) {
//	/* Deskripsi Modul :  */
//	
//	pivot->right = rotateRight (pivot->right);
//	pivot = rotateLeft (pivot);
//	return pivot;
//}
//
//address LL (address pivot) {
//	/* Deskripsi Modul :  */
//	
//	pivot = rotateRight (pivot);
//	return pivot;
//}
//
//address LR (address pivot) {
//	/* Deskripsi Modul :  */
//	
//	pivot->left = rotateLeft (pivot->left);
//	pivot = rotateRight (pivot);
//	return pivot;
//}
//
//int setHeight (address pivot) {
//	/* Deskripsi Modul :  */
//	int rightHeight, leftHeight;
//	
//	if (pivot == Nil)
//		return 0;
//	else {
//		if (pivot->right == Nil)
//			rightHeight = 0;
//		else 
//			rightHeight = pivot->right->height + 1;
//			
//		if (pivot->left == Nil)
//			leftHeight = 0;
//		else 
//			leftHeight = pivot->left->height + 1;
//		
//		return (rightHeight > leftHeight) ? rightHeight : leftHeight;
//	}
//}
//
//address insertTree (address pivot, String *s, int fileIndex) {
//	/* Deskripsi Modul :  */
//	int defaultCount = 1;
//	
//	if (pivot == Nil) { // get nothing in tree
//		pivot = allocNode(*s, defaultCount, fileIndex);
//		
//	} else if (strcmp(s->string, pivot->kata.string) > 0) { // insert right subtree
//		pivot->right = insertTree (pivot->right, s, fileIndex);
//		if (getBalancingFactor(pivot) == -2) // Penentuan toleransi keseimbangan subtree kanan - kiri
//			if (strcmp(s->string, pivot->right->kata.string) > 0) // 
//				pivot = RR (pivot);
//			else if (strcmp(s->string, pivot->right->kata.string) < 0) //
//				pivot = RL (pivot);
//				
//	} else if (strcmp(s->string, pivot->kata.string) < 0) { // insert left subtree
//		pivot->left = insertTree (pivot->left, s, fileIndex);
//		if (getBalancingFactor(pivot) == 2)
//			if (strcmp(s->string, pivot->left->kata.string) < 0) // 
//				pivot = LL (pivot);
//			else if (strcmp(s->string, pivot->left->kata.string) > 0) // 
//				pivot = LR (pivot);
//				
//	} else if (strcmp(s->string, pivot->kata.string) == 0) { // the same value
//		insertInt(1, &pivot->firstCount, fileIndex);
//		
//	}
//	pivot->height = setHeight(pivot);
//	
//	return pivot;
//}
//
//void travInOrderStat (address pivot, CheckSet *checkSet) { // Modularitas benerin ya.. sama yang InOrder set lainnya
//	/* Deskripsi Modul :  */
//	
//	/* Pertama, kita mulai dari predecessor InOrder root dan tentukan apakah root memiliki nilai count yang kita cari;
//	 * Kedua, bila iya, maka masukkan ke field, jika tidak lanjut ke successornya;
//	 */
////	printf ("\ntes..\n");
//	if (pivot != Nil) {
////		printf ("\ntes.. please masuk..\n");
//		travInOrderStat(pivot->left, checkSet);
//		if (getCount(pivot->firstCount, checkSet->idFile1) > getCount(pivot->firstCount, checkSet->idFile2)) {
//			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile1);
////			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
//			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile2);	
////			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
//		} else if (getCount(pivot->firstCount, checkSet->idFile1) < getCount(pivot->firstCount, checkSet->idFile2)) {
//			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile2);
////			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
//			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile1);	
////			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
//		} else if (getCount(pivot->firstCount, checkSet->idFile1) == getCount(pivot->firstCount, checkSet->idFile2)) {
//			checkSet->sumOfGreater += getCount(pivot->firstCount, checkSet->idFile2);
////			printf ("\nGreater : %d\n", checkSet->sumOfGreater);
//			checkSet->sumOfSmaller += getCount(pivot->firstCount, checkSet->idFile1);	
////			printf ("\nSmaller : %d\n", checkSet->sumOfSmaller);
//		}
//		travInOrderStat(pivot->right, checkSet);
//	}	
//}
//
//void printInOrder (address pivot, int fileIndex) {
//	/* Deskripsi Modul :  */
//	
//	if (pivot != Nil) {
//		printInOrder(pivot->left, fileIndex);
////		printf ("\nTes Print In Order : \n");
//		if (getCount(pivot->firstCount, fileIndex) != 0)
//			printf ("%s freq=> %d\n", pivot->kata.string, getCount(pivot->firstCount, fileIndex));
////		printf ("\n");
//		printInOrder(pivot->right, fileIndex);
//	}
//}
//
//address searchLR (address pivot, char* string) {
//	/* Deskripsi Modul :  */
//	address P;
//	
//	if (pivot == Nil) {
////		printf ("\nYes 4\n") ;
//		P = Nil;	
//	} else if (strcmp(string, pivot->kata.string) > 0) {
////		printf ("\nYes 1\n") ;
//		P = searchLR (pivot->right, string);	
//	} else if (strcmp(string, pivot->kata.string) < 0) {
////		printf ("\nYes 2\n") ;
//		P = searchLR (pivot->left, string);	
//	} else if (strcmp(string, pivot->kata.string) == 0) {
////		printf ("\nYes 3\n") ;
//		P = pivot;	
//	}
//	return P;
//}
//
//address searchPosition (String s, address trav) {
//	/* Deskripsi Modul :  */
//	int cmp;
//	
//	if (trav == Nil) {
//		return trav;
//	} else {
//		cmp = strcmp (trav->kata.string, s.string);
//		
////		if (cmp == 0) {
////			return tStop->current;
////		} else if (cmp == -1 && tStop->current->left)
//		
//	 	switch (cmp) {
//			case 0 :
////				tStop->current.count1 
//				return trav;
//				break;
//			case -1 :
//				if (trav->left == Nil)
//					return trav;
//					else return searchPosition (s,trav->left);				
//				break;
//			case 1 :
//				if (trav->right == Nil)
//					return trav;
//					else return searchPosition (s,trav->right);
//				break;		
//		}
//	}
//}
//
//void makeTree (String *s, Tree *tree, int fileIndex) {
//	/* Deskripsi Modul :  */
//	
////	if (P != Nil) {
////		if (tStop->root == Nil) {
////			tStop->root = allocNode(*s,1,0);
////		} else {
////			trav = searchPosition(*s, tStop->root); // akhir
////		}
////	}
//	tree->root = insertTree (tree->root, &(*s), fileIndex);
//	*s = createString(1);
//}

/* ============================= FILE CONTROLLER =============================== */

void openFile (String *s, address *pivTree, address pivStop, int fileIndex) {
	/* Deskripsi Modul :  */
	
	char c;
	FILE *f = fopen(s->string,"rb"); // Stopword(English).txt
	bool finish = false;
	
	fread (&c,sizeof(char),1,f);
	while (!finish) {
		c = tolower(c);
		if (feof(f)) {
			*pivTree = insertTree (*pivTree, &(*s), fileIndex);
			*s = createString(1);
			printf ("\nMau beres..\nStr : %s\n", (*pivTree)->kata.string);
			finish = true;
		} else if ((c > 96 && c < 123) || c == 45) { // antara a dan z, tanda '-'
			insertChar(c,&(*s));
//			printf ("%c ", c);
		} else if ((c == 10 || c == 32) && (*s).string[0] != 0 ) { // code of space
//			printf ("\n");
//			printString(*s);
//			printf ("\n");

			if (fileIndex <= 0 && cekStopword(&(*s), pivStop)) {
				*s = createString(1);
			} else {
				// stem
				*pivTree = insertTree (*pivTree, &(*s), fileIndex);
				*s = createString(1);
			}
		}
//		if (!finish)
			fread (&c,sizeof(char),1,f);
	}
}

/* ========================== SIMILARITY CHECK CONTROLLER ============================ */
float similarityCheck (address pivot, CheckSet checkSet) {
	/* Kita punya modal Tree dan CheckSet;
	 * Pertama, kita akan traversal inOrder untuk mencari node yang count pada index
	 * 		tertentunya (idFile1 dan idFle2) bernilai != 0;
	 * Kedua, setelah ditemukan node yang nilai count pada index tertentu itu != 0,
	 *		maka kita tentukan nilai terbesar dari kedua count itu untuk dimasukkan ke
	 *		field sumOfGreater. Sebaliknya dimasukkan ke sumOfSmaller;
	 * Ketiga, setelah terkumpul sumOfGreater dan sumOfSmaller maka tinggal diolah ke
	 * 		rumus getSimilarityPercentage :
	 *			 numberOfPercentage% = (sumOfSmaller / sumOfGreater) * 100;
	 * Keempat, kirim nilai getPercentage ke modul Utama / Main Module;
	 */
	 float percentage;
	 checkSet.sumOfGreater = 0;
	 checkSet.sumOfSmaller = 0;
	 
	 travInOrderStat(pivot, &checkSet);
	 percentage = getSimilarityPercentage (checkSet);
	 
	 return percentage;
}

//float getSimilarityPercentage (CheckSet checkSet) {
//	/* Deskripsi Modul :  */
//	printf ("\nGreater P : %f", checkSet.sumOfGreater);
//	printf ("\nSmaller P : %f", checkSet.sumOfSmaller);
//	printf ("\nDevided : %f\n", (checkSet.sumOfSmaller / checkSet.sumOfGreater));
//	printf ("\nPercent : %f\n", (checkSet.sumOfSmaller / checkSet.sumOfGreater)*100);
//	return (checkSet.sumOfSmaller / checkSet.sumOfGreater) * 100;
//}

/* ============================= MAIN MODULE - PROCESS =============================== */
int main() {
	/* Deskripsi Modul :  */
	int fileNumber = 1, idfileStop = 0;
	int finish = 1, idLang;
	char select;
	
	String s, s1;
	Tree tStop, tStat;
	CheckSet checkSet;
	address P, root1, root2, root3;
	
	/* Create String */	
	s = createString(12);
	createTree(&tStop);
	createTree(&tStat);
	
	/* Buat Tree Stopword - English */
	strcpy(s.string,"Stopword(English).txt");
	openFile(&s, &tStop.root1, tStop.root1, idfileStop);
//	printf ("\nIni Add Root Eng : %x \n", &tStop.root1);
	printf ("\nIni Root Eng : %s \n", tStop.root1->kata.string);
	printf ("Size tStop : %d \n\n", size(tStop.root1));
	
	/* Buat Tree Stopword - Indonesia */
	strcpy(s.string,"Stopword(indonesia).txt");
//	printf ("\nIni Add Root Ind : %x \n", &tStop.root2);
	openFile(&s, &tStop.root2, tStop.root1, idfileStop);
	printf ("\nIni Root Ind : %s \n", tStop.root2->kata.string);
	printf ("Size tStop : %d \n\n", size(tStop.root2));
	
	while (finish) {
		printf ("\nPilih jenis bahasa yang ingin digunakan :\n1. English\n2. Indonesia\nMasukkan No : ");
		scanf ("%d", &idLang);
		
		s = createString(12);
		printf ("\nMasukkan nama file yang ingin dicek : ");
		scanf(" %[^\n]", s.string);
		
		printf ("\nMasukkan nomor identitas file : ");
		scanf (" %d", &fileNumber);
		
		openFile(&s, &tStat.root1, idLang == 1 ? tStop.root1 : idLang == 2 ? tStop.root2 : Nil, fileNumber);
//		printf ("\nIni File Number : %d \n", fileNumber);
		printf ("\nIni Root tStat : %s \n", tStat.root1->kata.string);
		printf ("Size tStat : %d \n\n", size(tStat.root1));
		printInOrder(tStat.root1, fileNumber);
		countFile += 1;
		
//		printf ("\ncount 1 : %d\n", countFile);
		while(finish && countFile >= 2) {			
//			printf ("\ncount 2 : %d\n", countFile);
			printf ("\nMasukkan No File yang ingin di cek : \n");
			printf ("No File pertama : "); scanf ("%d", &checkSet.idFile1);
//			printInOrder(tStat.root, checkSet.idFile1);
			printf ("No File kedua : "); scanf ("%d", &checkSet.idFile2);
//			printInOrder(tStat.root, checkSet.idFile2);
			printf ("\nKesamaan dari dua file tersebut : %3.f %c\n", similarityCheck(tStat.root1, checkSet), 37);
			
			printf ("\nCoba lagi? (Y/N) "); scanf (" %c", &select);
			finish = (select == 'N') ? 0 : 1 ;
		}
		finish = 1;
		
		printf ("\nLanjut? (Y/N) "); scanf (" %c", &select);
		finish = (select == 'N') ? 0 : 1 ;
	}

	/* Sementara */
	char *kata = (char*)malloc(sizeof(char)*14);
	printf ("\nMasukkaun data : "); 
	scanf(" %[^\n]", kata);
	printf ("\n%s", kata);
//	gets(kata);
	P = searchLR(tStat.root1, kata);
	printf ("\nInfo : %s\n", P!=Nil ? P->kata.string : "Tidak Ada");
	printf ("\nLeft : %s\n", P!=Nil ? P->left->kata.string : "Tidak Ada");
	printf ("\nRight : %s\n", P!=Nil ? P->right->kata.string : "Tidak Ada");
	
	return 0;
}
