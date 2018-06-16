#ifndef __Mapa_H_
#define __Mapa_H_

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
using namespace System;

class CMapa
{
private:
	int **Mapa;
	struct Aristas
	{
		int i;
		int j;
		int peso;
	};
	int fila;
	int columna;
public:	
	CMapa();
	~CMapa();


};

string Buscar_Cadena(string &s)
{
	string aux_cadena = "";
	int i;
	for (i = 0; i <s.size(); i++)
	{
		if ((int)s[i] == 32)
			break;
		aux_cadena = aux_cadena + s[i];
	}
	s.erase(0, i + 1);
	return aux_cadena;
}


CMapa::CMapa()
{
	string aux_cadena = "", s="";
	ifstream aux;
	aux.open("Inicio.txt");
	while(getline(aux,s))
		{
			aux_cadena = Buscar_Cadena(s);
			i = atoi(aux_cadena.c_str());
			aux_cadena = Buscar_Cadena(s);
			j = atoi(aux_cadena.c_str());
		}
}

CMapa::~CMapa()
{}
#endif 
