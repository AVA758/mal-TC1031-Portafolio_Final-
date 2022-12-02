// =================================================================
//
// File: main.cpp
// Author: Alain Vicencio A01620758
// 		   Fernnado Matute A00833375
// 		   Ricardo Navarro A01708825
// 
// Date: 18/11/2022
//
// =================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include "selection.h"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream input;
    ofstream mysolution;

	if (argc != 3){
		cout<< "Error"<<endl;
		return -1;
	}

	input.open(argv[1]);
	if (!input.is_open()){
		cout << "Error al abrir el archivo\n";
		return -1;
	}

	mysolution.open(argv[2]);

	unsigned int tam, sum;
	vector <int> numeros;
	vector <int> sumas;
	sum = 0;

	input >> tam;

	numeros.resize(tam);
	sumas.resize(tam - 1);

	for (int i = 0; i < tam; i++) {
		input >> numeros[i];
	}

	selectionSort(numeros);

	for (int j = 0; j < tam - 1; j++) {
		if (j == 0) {
			sumas[j] = numeros [0] + numeros[1] - 1;
		}
		else {
			sumas[j] = sumas [j - 1] + numeros [j + 1] - 1;
		}
	}

	for (int k = 0; k < tam -1; k++) {
		sum += sumas[k];
	}

	mysolution << sum;

	input.close();
	mysolution.close();

	return 0;
}
