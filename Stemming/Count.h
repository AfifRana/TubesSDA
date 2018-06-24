#ifndef count_h
#define count_h
#define Nil NULL

/*  */
typedef struct count *adr;
typedef struct count {
	int idFile;
	int value;
	adr next;
} Count;

/* Modul */
adr allocCount (int count, int fileIndex);
void insertInt (int number, Count *c, int fileIndex);
int getCount (adr countNode, int fileIndex);

#endif
