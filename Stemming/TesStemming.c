#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stmr.c"
#include "stem.c"

void makeTree () {
	
}

int main() {
	String s;
	StemTree st;
	
	word = (char*)malloc(10 * sizeof(char));
	strcpy(word, "orange");
	
	/* ------------- Getting StemTree  Process ---------------- */
	/* Stopwords */
	strcpy(s.string, "KataDasar.txt");
	fileNumber = 0;
	openFile(&s, &st.stopword, st.stopword, fileNumber);
//	printf ("\nIni File Number : %d \n", fileNumber);
	printf ("\nIni Root tStat : %s \n", tStat.root->kata.string);
	printf ("Size tStat : %d \n\n", size(tStat.root));
	printInOrder(tStat.root, fileNumber);
	
	/* Basic Words */
	strcpy(s.string, "Stopword.txt");
	fileNumber = 1;
	openFile(&s, &st.basicWords, st.stopword, fileNumber);
//	printf ("\nIni File Number : %d \n", fileNumber);
	printf ("\nIni Root tStat : %s \n", tStat.root->kata.string);
	printf ("Size tStat : %d \n\n", size(tStat.root));
	printInOrder(tStat.root, fileNumber);
		
	/* ------------------ Stemming  Process ------------------- */
	stem(word, st);
//	word[stem(word,0,strlen(word)-1)+1] = '\0';
	
	printf ("%s", word);
	
	return 0;
}
