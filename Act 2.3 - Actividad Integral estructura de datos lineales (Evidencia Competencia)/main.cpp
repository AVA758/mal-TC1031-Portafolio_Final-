// =================================================================
//
// Archivo: main.cpp
// Autor: Alain Vicencio Arizabalo
// Fecha: 18/10/2022
//
// =================================================================
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "header.h"
#include "barco.h"
#include "ordenamiento.h"
#include "list.h"
using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile; //Declaración de valores: uso del inputfile
	ofstream outputFile; //uso del outputfile
	int num; //númer de barcos a ordenar y revisar
	char puntoe; //Entrada del barco: del Mediterráneo (M) o del Rojo (R)
	string prefix, fecha, tiempo, ubi; //conversión de valores a string.
	vector<Barco> barcos; //Vector de barcos con el cual se trabajará

	if (argc != 3) { //Aseguración de escritura correcta de comandos.
	cout << "usage: " << argv[0] << " input_file output_file\n";
	return -1;
	}

	inputFile.open(argv[1]); //En caso de que el archivo de entrada no exista o tenga el nombre mal escrito.
	if (!inputFile.is_open()) {
	cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
	return -1;
	}

	outputFile.open(argv[2]); //Apertura del archivo
	inputFile >> num >> prefix;

	barcos.resize(num); //reformación de vector según cuántos barcos sean en la lista.

	for (int i = 0; i < num; i++){ //Acomodo de la información del inputfile al vector.
	inputFile >> fecha >> tiempo >> puntoe >> ubi;
	barcos[i] = Barco(fecha, tiempo, puntoe, ubi);
	}

	selectionSort(barcos); //Método de ordenamiento.

	//MÉTODO DE BÚSQUEDA: SECUENCIAL 

	//Primero se hacen los contadores para cada mes de cada entrada, al final
	//habrá dos contadores para enero, uno que es del Mediterráneo y otro que es del Rojo.
	int Mjan = 0;
	DoubleLinkedList<string> M1; //Se declaran los nodos para las listas doblemente ligadas, según el Mar (M o R) y el mes (del 1 al 12).
	int Mfeb = 0;
	DoubleLinkedList<string> M2;
	int Mmar = 0;
	DoubleLinkedList<string> M3;
	int Mapr = 0;
	DoubleLinkedList<string> M4;
	int Mmay = 0;
	DoubleLinkedList<string> M5;
	int Mjun = 0;
	DoubleLinkedList<string> M6;
	int Mjul = 0;
	DoubleLinkedList<string> M7;
	int Mago = 0;
	DoubleLinkedList<string> M8;
	int Msep = 0;
	DoubleLinkedList<string> M9;
	int Moct = 0;
	DoubleLinkedList<string> M1O;
	int Mnov = 0;
	DoubleLinkedList<string> M11;
	int Mdic = 0;
	DoubleLinkedList<string> M12;
	int Rjan = 0;
	DoubleLinkedList<string> R1;
	int Rfeb = 0;
	DoubleLinkedList<string> R2;
	int Rmar = 0;
	DoubleLinkedList<string> R3;
	int Rapr = 0;
	DoubleLinkedList<string> R4;
	int Rmay = 0;
	DoubleLinkedList<string> R5;
	int Rjun = 0;
	DoubleLinkedList<string> R6;
	int Rjul = 0;
	DoubleLinkedList<string> R7;
	int Rago = 0;
	DoubleLinkedList<string> R8;
	int Rsep = 0;
	DoubleLinkedList<string> R9;
	int Roct = 0;
	DoubleLinkedList<string> R10;
	int Rnov = 0;
	DoubleLinkedList<string> R11;
	int Rdic = 0;
	DoubleLinkedList<string> R12;

	for (int i = 0; i < num; i++){ //Se hace el recorrido por todos los barcos ya ordenados.
		string ubi = barcos[i].ubi; //Se guarda la UBI como lo es indicado en la información del barco, según el recorrido (cada barco).
		string prefixBuscar = ubi.substr(0,3); //Se hace la búsqueda, comparando el prefijo a buscar según el documento con las primeras 3 letras del UBI del barco.
		if (prefixBuscar == prefix){ //En el caso de que sí encuentre el prifijo...
			if (barcos[i].mes == 1){ //Según el ciclo for, compara el mes para saber si es de enero (o de algún otro mes según siga el código)
				if (barcos[i].puntoe == 'M'){ //En el caso de que sí es el mes correspondiente, compara si el barco viene del Mediterráneo.
					Mjan++; //Se suma 1 al contador respectivo.
					M1.push_back(ubi); //Se manda a llamar al nodo y a su función push_back con la infromación string del UBI.
				}
				else{ //Se asume que si no es del mediterráneo, es del mar Rojo.
					Rjan++; //Suma 1 al contador respectivo.
					R1.push_back(ubi); //LLama al nodo para hacer el pushback con el string del UBI.
				}	
			}
			else if (barcos[i].mes == 2){ //Se repite el mismo proceso para los demás meses, según lo marque el ciclo for.
				if (barcos[i].puntoe == 'M'){
					Mfeb++;
					M2.push_back(ubi);
				}
				else{
					Rfeb++;
					R2.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 3){
				if (barcos[i].puntoe == 'M'){
					Mmar++;
					M3.push_back(ubi);
				}
				else{
					Rmar++;
					R3.push_back(ubi);
				}	
			}
			else if (barcos[i].mes == 4){
				if (barcos[i].puntoe == 'M'){
					Mapr++;
					M4.push_back(ubi);
				}
				else{
					Rapr++;
					R4.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 5){
				if (barcos[i].puntoe == 'M'){
					Mmay++;
					M5.push_back(ubi);
				}
				else{
					Rmay++;
					R5.push_back(ubi);
				}	
			}
			else if (barcos[i].mes == 6){
				if (barcos[i].puntoe == 'M'){
					Mjun++;
					M6.push_back(ubi);
				}
				else{
					Rjun++;
					R6.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 7){
				if (barcos[i].puntoe == 'M'){
					Mjul++;
					M7.push_back(ubi);
				}
				else{
					Rjul++;
					R7.push_back(ubi);
				}	
			}
			else if (barcos[i].mes == 8){
				if (barcos[i].puntoe == 'M'){
					Mago++;
					M8.push_back(ubi);
				}
				else{
					Rago++;
					R8.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 9){
				if (barcos[i].puntoe == 'M'){
					Msep++;
					M9.push_back(ubi);
				}
				else{
					Rsep++;
					R9.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 10){
				if (barcos[i].puntoe == 'M'){
					Moct++;
					M1O.push_back(ubi);
				}
				else{
					Roct++;
					R10.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 11){
				if (barcos[i].puntoe == 'M'){
					Mnov++;
					M11.push_back(ubi);
				}
				else{
					Rnov++;
					R11.push_back(ubi);
				}
			}
			else if (barcos[i].mes == 12){
				if (barcos[i].puntoe == 'M'){
					Mdic++;
					M12.push_back(ubi);
				}
				else{
					Rdic++;
					R12.push_back(ubi);
				}
			}
		}
	}
	//Empieza el despliegue de información.
	if(Mjan !=0 || Rjan !=0){ //Primero debe saber si hay barcos que cumplen con la caracterísitca, para ello, compara los contadores,
	                          //si el contador no cambio, significa que nunca hubo un barco que considerar.
							  //este filtro se puede lograr también con un método de nodos (el empty()), donde se compara (en true o false) si el nodo está vacío.
		outputFile<<"jan"<< endl; //marca el mes
		if (Mjan != 0){       //En caso de ser 0, no se despliega la información.
		outputFile << "M " << Mjan << ": " << M1.toString() << endl;
		}
		if (Rjan != 0){ //En el output file, se escribe el mar de donde proviene el barco, el número de barcos que vienen de ese mar y la lista de UBIs de los barcos que vienen del mar.
		outputFile << "R " << Rjan << ": " << R1.toString() << endl;
		}
	}
	if(Mfeb != 0 || Rfeb != 0){ //Se repite el mismo proceso para el resto de los meses.
		outputFile <<"feb"<< endl;
		if (Mfeb != 0){
		outputFile << "M " << Mfeb << ": " << M2.toString() << endl;;
		}
		if (Rfeb != 0){
		outputFile << "R " << Rfeb << ": " << R2.toString() << endl;;
		}
	}
	if(Mmar !=0 || Rmar != 0){
		outputFile << "mar" << endl;;
		if (Mmar != 0){
		outputFile << "M " << Mmar << ": " << M3.toString() << endl;
		}
		if (Rmar != 0){
		outputFile << "R " << Rmar << ": " << R3.toString() << endl;
		}
	}
	if (Mapr != 0 || Rapr != 0){
		outputFile << "apr" << endl;
		if (Mapr != 0){
		outputFile << "M " << Mapr << ": " << M4.toString() << endl;
		}
		if (Rapr != 0){
		outputFile << "R " << Rapr << ": " << R4.toString() << endl;
		}	
	}
	if (Mmay != 0 || Rmay != 0){
		outputFile << "may" << endl;
		if (Mmay != 0){
		outputFile << "M " << Mmay << ": " << M5.toString() << endl;
		}
		if (Rmay != 0){
		outputFile << "R " << Rmay << ": " << R5.toString() << endl;
		}
	}
	if (Mjun != 0 || Rjun != 0){
		outputFile <<"jun" << endl;
		if (Mjun != 0){
		outputFile << "M " << Mjun << ": " << M6.toString() << endl;
		}
		if (Rjun != 0){
		outputFile << "R " << Rjun << ": " << R6.toString() << endl;
		}
	}
	if (Mjul !=0 || Rjul != 0){
		outputFile << "jul" << endl;
		if (Mjul != 0){
		outputFile << "M " << Mjul << ": " << M7.toString() << endl;
		}
		if (Rjul != 0){
		outputFile << "R " << Rjul << ": " << R7.toString() << endl;
		}
	}
	if(Mago !=0 || Rago != 0){
		outputFile << "aug" << endl;
		if (Mago != 0){
		outputFile << "M " << Mago << ": " << M8.toString() << endl;
		}
		if (Rago != 0){
		outputFile << "R " << Rago << ": " << R8.toString() << endl;
		}
	}
	if (Msep != 0 || Rsep != 0){
		outputFile << "sep" << endl;
		if (Msep != 0){
		outputFile << "M " << Msep << ": " << M9.toString() << endl;
		}
		if (Rsep != 0){
		outputFile << "R " << Rsep << ": " << R9.toString() << endl;
		}
	}
	if (Moct != 0 || Roct != 0){
		outputFile << "oct" << endl;
		if (Moct != 0){
		outputFile << "M " << Moct << ": " << M1O.toString() << endl;
		}
		if (Roct != 0){
		outputFile << "R " << Roct << ": " << R10.toString() << endl;
		}
	}
	if(Mnov != 0 || Rnov != 0){
		outputFile << "nov" << endl;
		if (Mnov != 0){
		outputFile << "M " << Mnov << ": " << M11.toString() << endl;
		}
		if (Rnov != 0){
		outputFile << "R " << Rnov << ": " << R11.toString() << endl;
		}
	}
	if(Mdic != 0 || Rdic != 0){
		outputFile << "dec" << endl;
		if (Mdic != 0){
		outputFile << "M " << Mdic << ": " << M12.toString() << endl;
		}
		if (Rdic != 0){
		outputFile << "R " << Rdic << ": " << R12.toString() << endl;
		}
	}
	inputFile.close(); //Cerrar inputfile
	outputFile.close(); //Cerrar outputfile. 
	return 0; //Regresar 0 para cerrar.
}
