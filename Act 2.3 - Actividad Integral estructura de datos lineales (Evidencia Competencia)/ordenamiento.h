#ifndef ORDENAMIENTO_H_
#define ORDENAMIENTO_H_

#include "header.h"
#include <vector>
#include "barco.h"

using namespace std;


// =================================================================
// MÉTODO DE SELECCIÓN PARA EL ORDENAMIENTO DE VALORES EN UN VECTOR
// =================================================================
void selectionSort(vector<Barco> &barcos) {
	int pos;
	for(int i=barcos.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(barcos[pos].comp(barcos[j])){
				pos = j;
			}
		}

		if (pos != i){
			swap(barcos, i, pos);
		}
	}
}


#endif