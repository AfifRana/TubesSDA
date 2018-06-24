//author: cahya, reyhan, manda
#include <string.h>
#include "stem.h"

address getTree(char* fileName)
{
	Tree pohon;
	createTree(&pohon);
	infotype X;
	
	FILE *fl;
	fl = fopen(fileName,"r");
	char inputChar;
	char inputWords[MAX_LETTER];
	int indexOfInputWords = 0;

	if(fl==NULL) { //Cek kosong file
		printf("\nFile "); printf("%s", fileName); printf(" Tidak Dapat dibuka!");
	} else {
		fread(&inputChar, 1, sizeof(inputChar), fl);
		while(!feof(fl)){
			if(inputChar >= 'a' && inputChar <= 'z') {
				inputWords[indexOfInputWords] = inputChar;
				indexOfInputWords++;
			} else if(inputChar >= 'A' && inputChar <= 'Z'){
				inputWords[indexOfInputWords] = inputChar ^ 0b00100000;
				indexOfInputWords++;
			} else if(inputChar == ' '){
				strcpy(X.words, inputWords);
				Root(pohon) = insertNode(Root(pohon), X, 0);
				memset(inputWords, '\0', sizeof(inputWords));
				indexOfInputWords = 0;
			}
			fread(&inputChar, 1, sizeof(inputChar), fl);
		}
	}

	return Root(pohon);
}

void createTreeBasicWords(Tree *tree){
	Root(*tree) = getTree("KataDasar.txt");
}

void createTreeStopWords(tree *tree){
	Root(*tree) = getTree("Stopword.txt");
}

bool first(char* words, int afiksLength, char* afiks){
	int count = 0, i;
	for(i = 0; i < afiksLength; i++){
		if(words[i] == afiks[i]){
			count++;
		}
	}
	if(count == afiksLength) return true; else return false;
}

bool ends(char* words, int afiksLength, char* afiks){
	int count = 0, i;
	int wordLength = strlen(words);
//	printf("%s - %d", words, wordLength);
	for(i = 0; i < afiksLength; i++){
		if(words[wordLength-afiksLength+i] == afiks[i]){
			count++;
		}
	}
//	printf("\t\t %d, %d", count, length);
	if(count == afiksLength) return true; else return false;
}

bool mid(char* words, int indexStart, char* afiks){
	int afiksLength = strlen(afiks);
	int wordLength = strlen(words);
	int count = 0, i;
	for(i = 0; i < afiksLength; i++){
		if(words[indexStart] == afiks[i]){
			count++;
			indexStart++;
		}
	}
	if(count == afiksLength) return true; else return false;
}

bool isVowel(char c){
	switch(c){
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
		return true; break;
	}
	return false;
}

void setPrefiks(char* words, StemTree stemTree){
/*	
*/
	int length = strlen(words);
	char temp[MAX_LETTER]; int i;
	bool ktsp = false; //awalan 'k', 't', 's', 'p'
	int afiksLength = 0;
	memset(temp, '\0', sizeof(temp));
	
	if(words[0] == 'b' || words[0] == 'p' || words[0] == 't' || words[0] == 'd' || words[0] == 'k' || words[0] == 'm' || words[0] == 'p')
	{
		if(first(&(*words), 3, "ber") || first(&(*words), 3,"per") || first(&(*words), 3, "ter")){
			afiksLength = 3;
		} else if(first(&(*words), 2, "di") || first(&(*words), 2, "ke")){ //kekasih OK, ketua !OK -- ketua dijadiin tua
			afiksLength = 2;
		} else if(first(&(*words), 6, "memper")){
			afiksLength = 6;
		} else if(first(&(*words), 5, "menge")){ 
			afiksLength = 5;
		} else if(first(&(*words), 4, "peng")){ //mengunci, menguliti
			afiksLength = 4;
		} else if(first(&(*words), 4, "meng")){ //mengunci, menguliti
			temp[0] = 'k';
			ktsp = true;
			afiksLength = 3;
		} else if(first(&(*words), 4, "meny") || first(&(*words), 4, "peny")){ 
			temp[0] = 's';
			ktsp = true;
			afiksLength = 3;
		} else if(first(&(*words), 3, "pen")){ 
			if(isVowel(words[3])){ //peninju, penunjuk, penerjemah
				temp[0] = 't';
				ktsp = true;
				afiksLength = 2;
			} else { //pencuri, penjudi
				afiksLength = 3;
			}
		} else if(first(&(*words), 3, "men")){ 
			if(!isVowel(words[3]) && !isVowel(words[4])){ //traktir
				afiksLength = 3;
			} else {
				temp[0] = 't';
				ktsp = true;
				afiksLength = 2;
			}
		} else if(first(&(*words), 3, "mem")){ 
			temp[0] = 'p';
			ktsp = true;
			afiksLength = 2;
		} else if(first(&(*words), 2, "me") || first(&(*words), 2, "pe")){ 
			afiksLength = 2;
		}

		if(ktsp){
			for(i = 1; i < length; i++){
				temp[i] = words[i+afiksLength];
			}
		} else {
			for(i = 0; i < length; i++){
				temp[i] = words[i+afiksLength];
			}
		}
		strcpy(words, temp);
	}
}

void setSufiks(char* words, StemTree stemTree){

	unsigned short int length = strlen(words);
	unsigned short int afiksLength = 0;
	char temp[MAX_LETTER]; unsigned short int i;
	memset(temp, '\0', sizeof(temp));
		
	if(words[length-1] == 'n'){
		if(ends(&(*words), 3, "kan") || ends(&(*words), 3,"pun")){
			afiksLength = 3;
		} else if(ends(&(*words), 2, "an")){
			afiksLength = 2;
		}
	} else if(words[length-1] == 'h'){
		if(ends(&(*words), 3, "kah") || ends(&(*words), 3,"lah") || ends(&(*words), 3, "tah")){
			afiksLength = 3;
		}
	} else if(words[length-1] == 'i'){
		if(ends(&(*words), 1, "i")){
			afiksLength = 1;
		}
	} else if(words[length-1] == 'u'){
		if(ends(&(*words), 2, "ku") || ends(&(*words), 2, "mu")){
			afiksLength = 2;
		}
	} else if(words[length-1] == 'a'){
		if(ends(&(*words), 3, "nya")){
			afiksLength = 3;
		}
	} else if(words[length-1] == 't' || words[length-1] == 's' || words[length-1] == 'e' || words[length-1] == 'g' || words[length-1] == 'r'){
		//N/A
		afiksLength = 0;
	}

	for(i = 0; i < length-afiksLength; i++){
		temp[i] = words[i];
	}
	strcpy(words, temp);
}

void setInfiks(char* words, StemTree stemTree){

	unsigned short int length = strlen(words);
	unsigned short int afiksLength = 0;
	char temp[MAX_LETTER]; unsigned short int i;
	memset(temp, '\0', sizeof(temp));
	unsigned short int indexStart = 1;
	unsigned short int j;
	
	if(mid(words, indexStart, "el")){
		afiksLength = 2;
	} else if(mid(words, indexStart, "er")){
		afiksLength = 2;
	} else if(mid(words, indexStart, "em")){
		afiksLength = 2;
	} else if(mid(words, indexStart, "in")){
		afiksLength = 2;
	} else if(mid(words, 2, "ha")){
		indexStart = 2;
		afiksLength = 2;
	}
	
	if(afiksLength > 0){
		
		for(i = 0; i < indexStart; i++){
			temp[i] = words[i];
		}
		j = i;
		for(i = indexStart+afiksLength; i < length; i++){
			temp[j] = words[i];
			j++;
		}
		strcpy(words, temp);
	}

}


void stem(char* words, StemTree stemTree){
	char temp[MAX_LETTER];
	memset(temp, '\0', sizeof(temp)); // brilliant !

 	strcpy(temp, words);
	setSufiks(words, stemTree);
	//kalo pas udah di stem ternyata bukan kata dasar, gak jadi stem
	if(!searchTree(Root(stemTree.basicWords), words)){
		setPrefiks(words, stemTree);
		//kalo pas udah di stem ternyata bukan kata dasar, gak jadi stem
		if(!searchTree(Root(stemTree.basicWords), words)){
			setInfiks(words, stemTree);
			if(!searchTree(Root(stemTree.basicWords), words)){
				strcpy(words,temp);
			}
		}
	}
	
}







