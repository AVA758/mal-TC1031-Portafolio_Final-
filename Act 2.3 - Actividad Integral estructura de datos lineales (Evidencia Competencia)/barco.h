#ifndef BARCO_H_
#define BARCO_H_
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Barco{
public:
  int dia, mes, anio, hora, minuto;
  char puntoe;
  string ubi;

//constructor con desglose de fecha y tiempo
  Barco(string fecha, string tiempo, char puntoe, string ubi);
  Barco();
  Barco(const Barco &barco);

  bool comp(const Barco &);
  
};

//Constructor 1
Barco::Barco(string fecha, string tiempo, char puntoea, string ubia) {
    dia = (fecha[0]-'0')*10 + (fecha[1]-'0');
    mes = (fecha[3]-'0')*10 + (fecha[4]-'0');
    anio = (fecha[6]-'0')*10 + (fecha[7]-'0');

    hora = (tiempo[0]-'0')*10 + (tiempo[1]-'0');
    minuto = (tiempo[3]-'0')+10 + (tiempo[4]-'0');

    puntoe = puntoea;

    ubi = ubia;
  }

  //constructor 2
  Barco::Barco(){
    dia=0;
    mes=0;
    anio=0;
  
    hora= 0;
    minuto = 0;
  
    puntoe = ' ';
    
    ubi = ' ';
  }

  //constructor 3 para marcar los días, meses y años
  Barco::Barco(const Barco &barco){
    dia = barco.dia;
    mes = barco.mes;
    anio = barco.anio;

    hora = barco.hora;
    minuto = barco.minuto;

    puntoe = barco.puntoe;
    ubi = barco.ubi;
    
  }

  //comparación de barcos, según mes, día, hora y minuto en ese orden. Regresa true o false según si necesita ordenarlo después del barco previo.
  bool Barco::comp(const Barco & barco){
    if (mes < barco.mes) return true;
    else if (mes > barco.mes) return false;
    else{
      if (dia < barco.dia) return true;
      else if (dia > barco.dia) return false;
      else{
        if (hora < barco.hora) return true;
        else if (hora > barco.hora) return false;
        else{
          if (minuto < barco.minuto) return true;
          else if (minuto > barco.minuto) return false;
        }
      }
    }
    return false;
  
  }

#endif 
