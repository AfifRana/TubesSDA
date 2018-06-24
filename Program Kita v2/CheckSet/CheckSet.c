#include <stdio.h>
#include "checkset.h"

float getSimilarityPercentage (CheckSet checkSet) {
	/* Deskripsi Modul :  */
	printf ("\nGreater P : %f", checkSet.sumOfGreater);
	printf ("\nSmaller P : %f", checkSet.sumOfSmaller);
	printf ("\nDevided : %f\n", (checkSet.sumOfSmaller / checkSet.sumOfGreater));
	printf ("\nPercent : %f\n", (checkSet.sumOfSmaller / checkSet.sumOfGreater)*100);
	return (checkSet.sumOfSmaller / checkSet.sumOfGreater) * 100;
}

//float similarityCheck (address pivot, CheckSet checkSet) {
//	/* Kita punya modal Tree dan CheckSet;
//	 * Pertama, kita akan traversal inOrder untuk mencari node yang count pada index
//	 * 		tertentunya (idFile1 dan idFle2) bernilai != 0;
//	 * Kedua, setelah ditemukan node yang nilai count pada index tertentu itu != 0,
//	 *		maka kita tentukan nilai terbesar dari kedua count itu untuk dimasukkan ke
//	 *		field sumOfGreater. Sebaliknya dimasukkan ke sumOfSmaller;
//	 * Ketiga, setelah terkumpul sumOfGreater dan sumOfSmaller maka tinggal diolah ke
//	 * 		rumus getSimilarityPercentage :
//	 *			 numberOfPercentage% = (sumOfSmaller / sumOfGreater) * 100;
//	 * Keempat, kirim nilai getPercentage ke modul Utama / Main Module;
//	 */
//	 float percentage;
//	 checkSet.sumOfGreater = 0;
//	 checkSet.sumOfSmaller = 0;
//	 
//	 travInOrderStat(pivot, &checkSet);
//	 percentage = getSimilarityPercentage (checkSet);
//	 
//	 return percentage;
//}
