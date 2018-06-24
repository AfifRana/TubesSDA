#ifndef checkset_h
#define checkset_h

typedef struct checkSet {
	int idFile1;
	int idFile2;
	float sumOfGreater;
	float sumOfSmaller;
} CheckSet;

float getSimilarityPercentage (CheckSet checkSet);
//float similarityCheck (address pivot, CheckSet checkSet);

#endif
