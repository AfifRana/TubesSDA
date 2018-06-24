#include<stdio.h>
#include<stdlib.h>
#include"count.h"

/* ---------------------------------------------------------------- */
adr allocCount (int count, int fileIndex) {
	/* Deskripsi Modul :  */
	
	/* ------------- alloc yang baru ------------- */
	adr c = (adr)malloc(sizeof(Count));
	
	if (c != Nil) {
		c->idFile = fileIndex;
		c->value = count;
		c->next = Nil;
	}
	
	/* ------------- Ini tutup dulu -----------------
	
	c.size = initialSize;
	c.used = 0;
	c.value = (int*)malloc(c.size*sizeof(int));
	
	for (i=0; i<c.size; i++)
		c.value[0] = 0;
		
	------------------------------------------------- */	
	return c;
}

/* ---------------------------------------------------------------- */
void insertInt (int count, adr *firstNode, int fileIndex) { // pengen dibuat priority queue
	/* Deskripsi Modul :  */
	adr preTrav = *firstNode, trav = *firstNode, pNew;
	
	/* ------------- Priority Queue -------------- */
	if (trav == Nil) {
		trav = allocCount(count, fileIndex);
		*firstNode = trav;
	} else if (fileIndex == trav->idFile) {
		trav->value += count;
	} else if (trav->idFile > fileIndex) {
		/* insertFirst */
		pNew = allocCount(count, fileIndex);
		pNew->next = trav;
		*firstNode = pNew;	
	} else {
		/* Insert After-Last */
		while (trav != Nil && trav->idFile < fileIndex) {
			preTrav = trav;
			trav = trav->next;
		}
		
		if (trav != Nil && trav->idFile == fileIndex) {
			trav->value += count;
		} else {
			pNew = allocCount(count, fileIndex);
			preTrav->next = pNew;
			pNew->next = trav;	
		}	
	}
	
	/* ---------------- Ini ditutup dulu ----------------
	if (fileIndex > c->used) {
		c->used = fileIndex;
		printf ("Used : %d\n", c->used);
		printf ("FileIndex : %d\n", fileIndex);
	}
	
	if (c->used == c->size || c->used > c->size) {
		c->size = c->used + 1;
		printf ("Size : %d\n", c->size);
		c->value = (int*)realloc(c->value, c->size * sizeof(int));
		c->value[c->used] = 0;
	}
	
	if (idMaxFile < fileIndex) {
		idMaxFile = fileIndex;
		printf ("IdMax : %d\n", idMaxFile);
		printf ("IdFile : %d\n", fileIndex);	
	}
	c->value[fileIndex] += number;
	printf ("\n");
	---------------------------------------------------- */
}

int getCount (adr countNode, int fileIndex) {
	/* Deskripsi Modul :  */
	
	/* -------------- Linear Search ---------------- */
	if (countNode == Nil) {
//		printf ("\nTes 1 \t val : %d \n ", 0);
		return 0;
	} else if (countNode->idFile == fileIndex) {
//		printf ("\nTes 2 \t val : %d \n", countNode->value);
		return countNode->value;
	} else {
		int a = getCount(countNode->next, fileIndex);
//		printf ("\nTes 3 \t val : %d \n", a);
		return a;
	}
	
	/* ------------ Ini tutup dulu --------------------
	
	if (c.value[fileIndex] != 0 && c.used >= fileIndex)
		return c.value[fileIndex];
	else return 0;	
	
	------------------------------------------------ */
}
