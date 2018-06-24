#ifndef string_h
#define string_h

/* Struktur Data */
typedef struct string {
	char *string;
  	int used;
  	int size;
} String;

/* Modul Set */
void insertChar(char c, String *s);
void printString (String s);
bool cekStopword(String *s, Tree tStop);

#endif

