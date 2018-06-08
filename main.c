/* Deskripsi		:
 * Author			:
 * Tanggal / Versi	:
 * Kompilator		:
 ==================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Nil NULL

/* Struktur Data */

typedef struct {
	char *string;
  	int used;
  	int size;
} String;

typedef struct node{
	String kata;
	int count1;
	int count2;
	struct node* left;
	struct node* right;
	struct node* parent;
} Node;

typedef struct {
	struct node* root;
	struct node* current;
} TreeStopword;

/* Modul - Modul */

void createTree(TreeStopword ts) {
	ts->root = Nil;
	ts->current = Nil;
}

void insertChar(char c, String s) {
	if (s->used + 1 == s->size) {
   	 	s->size *= 2;
    	s->string = (unsigned char *)realloc(s->string, (s->size * sizeof(unsigned char)) +1 );
  	}
	s.string[++s.used] = c;
}

void openFile (String s, ) {
	char c, *s;
	FILE *f = fopen("TestCase.txt","rb");
	
	while (!feof(f)) {
		fread (&c,sizeof(char),1,f);
		c = tolower(c);
		if ((c > 96 && c < 123) || c == 45) {
			printf ("%c", c);	
			insertChar(c,&(*s));
//			cekStopword(&(*s),);
		} else if (c == 32 && s.string[0] != 0) {
			printf ("\n");
			makeTree(&(*s),)
		}
	}
}

int main() {
	String s;
	TreeStopword ts;
	
	s.size = 7;
	s.string = (char*)malloc(s.size * sizeof(char));
	
	createTree(ts);
	
//	char word[10] = "FAJAR";
 //	s.string = "fajar";
//s.string[0] = 'F';
//s.string[1] = 'a';
//s.string[2] = 'j';
//s.string[3] = 'a';
//s.string[4] = 'r';
//strcpy(s.string, word);
//	char a = 'a';
//	string = &a;
//	char apa = 'a';
//	strcpy(apa,string);
//	int *p = 100;
//	p = ""
//	int a = strcmp(apa,string);
//	openFile(&(*string));
//	printf ("%s\n" , s.string);
//	printf ("%c\n" , s.string[2]);
//	printf ("%c\n" , s.string[5]);
	
//	s.string[5] = 'J';
//	s.string[6] = 0;
//	s.used = 5;
//	printf ("%s\n" , s.string);
//	printf ("%c\n" , s.string[5]);
//	printf ("%x\n" , apa);
//	printf ("%d\n" , a);	
//	string = " Hamzah";
//	printf ("%d\n" , p);
openFile(s);
	
	
	return 0;
}
