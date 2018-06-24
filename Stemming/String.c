#include<stdlib.h>
#include<stdio.h>
#include<String.h>
#include"string.h"

String createString (int initialSize) {
	/* Deskripsi Modul :  */
	String s;
	int i;
	
	s.size = initialSize;
	s.used = 0;
	s.string = (char*)malloc(s.size * sizeof(char));
	
	for(i=0; i<s.size; i++)
		s.string[i] = '\0'; // PENTING BANGET ASELI wkwk
		
	return s;
}

void insertChar(char c, String *s) {
	/* Deskripsi Modul :  */
	
	if (s->used == s->size) {
   	 	s->size *= 2;
    	s->string = (char*)realloc(s->string, (s->size * sizeof(char)) + 1 ); // ditambahin satu ya buat si null / '\0'
  	}
	(*s).string[(*s).used++] = c;
	(*s).string[(*s).used] = '\0';
//	printf ("%c ", c);
	
	/* Sementara */
//	int i;
//	printf ("\nTes : \n");
//	for (i=0;i<=s->size;i++) {
//		printf ("%c ", s->string[i]);
//	}
//	printf ("\n");
}

void printString (String s) {
	/* Deskripsi Modul :  */
	
	int i;
//	for (i = 0; i < s.used+1; i++) {
//		printf ("%c", s.string[i]);
//	}
	printf ("print : %s\n", s.string);
}

//bool cekStopword(String *s, Tree tStop) {
//	/* Deskripsi Modul :  */
//	address P;
//	
//	P = searchLR(tStop.root, s->string);
//	if (P != Nil)
//		return true;
//	else 
//		return false;	
//}
