#ifndef _Controlador_
#define _Controlador_

#include "Jugador.h"
#include "Misil.h"
#include <iostream>
#include <stdio.h>
#define INF 9999999
#define FlotaMax 11

using namespace std;

class Controlador_Juego
{
private:
	Jugador *Humano;
	Jugador *Maquina;
	Nave** Flota;
	int turno;
//	Rastreador *rastreador;
	//Jugador **Jugadores;
public:
	Controlador_Juego();
	~Controlador_Juego();

	Jugador* GetHumano();
	Jugador* GetMaquina();
	void Dibujar_Flota_Enemiga(int x, int y, int width, int height);
	void TimerTick(Graphics^ g);
	void Disparar_Misil(Keys tecla);
};

Controlador_Juego::Controlador_Juego()
{
	Humano = new Jugador(Bando::Aliado);
	Maquina = new Jugador(Bando::Enemigo);
	Flota = Maquina->Get_Flota();
}
Controlador_Juego::~Controlador_Juego()
{
	delete this->Humano;
	delete this->Maquina;
}

Jugador* Controlador_Juego::GetHumano() { return this->Humano; }
Jugador* Controlador_Juego::GetMaquina() { return this->Maquina; }

void Controlador_Juego::Dibujar_Flota_Enemiga(int x,int y,int width, int height)
	{
		Maquina->Agregar_Nave(x, y, width, height);
	}

void Controlador_Juego::TimerTick(Graphics^ g)
{
	Humano->DibujarFlota(g,'J');
	Maquina->DibujarFlota(g,'E');
}

void Controlador_Juego::Disparar_Misil(Keys tecla)
{	
//	freopen("out.txt", "wt", stdout);
	Rastreador *rastreador= new Rastreador();
	Teledirigido *teledirigido = new Teledirigido();

	int vida_menor = 99999;
	int vida_id;
	int Material_mayor = 0;
	int Material_id;
	switch (tecla)
	{
		case Keys::Q:
		{
			int origen;
			int destino;

			double **Grafo = new double*[FlotaMax];
			for (int i = 0; i < FlotaMax; i++)
				Grafo[i] = new double[FlotaMax];

			for (int i = 0; i < FlotaMax; i++)
				if (Flota[i]->Get_vida() != 0 && (vida_menor > Flota[i]->Get_vida()))
				{
					vida_menor = Flota[i]->Get_vida();
					vida_id = Flota[i]->Get_id();
				}
			for (int i = 0; i < FlotaMax; i++)
				if (Flota[i]->Get_vida() != 0 && (Flota[i]->Get_material() > Material_mayor))
				{
					Material_mayor = Flota[i]->Get_material();
					Material_id = Flota[i]->Get_id();
				}
			for (int i = 0; i < FlotaMax; i++)
				for (int j = 0; j < FlotaMax; j++)
					Grafo[i][j] = 0;

			for (int i = 0; i < FlotaMax; i++)
				for (int j = 0; j < FlotaMax; j++)
					Grafo[i][j] = Flota[j]->Get_vida() != 0 && i != j/* &&
					(Flota[j]->Get_y() !=  Flota[i]->Get_y()) &&(Flota[j]->Get_x() != Flota[i]->Get_x()) */ ?
					double(((Flota[j]->Get_y() - Flota[i]->Get_y())*((Flota[j]->Get_y() < Flota[i]->Get_y() ? -1 : 1))))
					/ double((Flota[j]->Get_x() - Flota[i]->Get_x())*((Flota[j]->Get_x() < Flota[i]->Get_x() ? -1 : 1)))
					: INF;
			/*
			for (int i = 0; i < FlotaMax; i++)
				for (int j = 0; j < FlotaMax; j++)
					Grafo[i][j] = Flota[j]->Get_vida() != 0 && i != j ?
					double(((Flota[j]->Get_y() - Flota[i]->Get_y())*((Flota[j]->Get_y() < Flota[i]->Get_y() ? -1 : 1))))
					+ double((Flota[j]->Get_x() - Flota[i]->Get_x())*((Flota[j]->Get_x() < Flota[i]->Get_x() ? -1 : 1)))
					: INF;
			*/
			vector<int> objetivos = rastreador->Algoritmo(Grafo, vida_id, Material_id, FlotaMax);
			for (int i = objetivos.size() - 1; i >= 0; i--)
				Maquina->Calcular_Danio(objetivos[i], 30);
			break;
		}
		case Keys::W:
		{
			vector<pair<int, iPair>>naves;
			int *Peso = new int[FlotaMax];
			int *Valor = new int[FlotaMax];
			int *indice = new int[FlotaMax];
			for (int i = 0; i < FlotaMax; i++)
			{
				naves.push_back({ i,{ Flota[i]->Get_vida(),Flota[i]->Get_material() } });
			}
			teledirigido->ordenar(naves);
			for (int i = 1; i <= FlotaMax; i++)
			{
				indice[i] = naves[i - 1].first;
				Peso[i] = naves[i - 1].second.first;
				Valor[i] = naves[i - 1].second.second;
			}
			break;
		}
	}
  	

}

#endif // !_Controlador_