#ifndef string_h
#define string_h
//#include"../Tree/Tree.h"
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

#endif

