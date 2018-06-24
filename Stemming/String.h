#ifndef String_h
#define String_h
#include<stdbool.h>
#define Nil NULL

/* Struktur Data */
typedef struct string {
	char *string;
  	int used;
  	int size;
} String;

/* Modul Set */
String createString (int initialSize);
void insertChar(char c, String *s);
void printString (String s);
//bool cekStopword(String *s, Tree tStop);

#endif

