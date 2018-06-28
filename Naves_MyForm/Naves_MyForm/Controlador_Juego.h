#ifndef _Controlador_
#define _Controlador_

#include "Jugador.h"
#include "Misil.h"
#define INF 9999999
#define FlotaMax 11

class Controlador_Juego
{
private:
	Jugador *Humano;
	Jugador *Maquina;
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
	
	Rastreador *rastreador= new Rastreador();
	switch (tecla)
	{
		case Keys::Q:
			Nave** Flota = Maquina->Get_Flota();
			double **Grafo = new double*[FlotaMax];
			for (int i = 0; i < FlotaMax; i++)
				Grafo[i] = new double[FlotaMax];

			for (int i = 0; i < FlotaMax; i++)
				for (int j = 0; j < FlotaMax; j++)
					Grafo[i][j] = FlotaMax;

			for (int i = 0; i < FlotaMax; i++)
				for (int j = 0; j < FlotaMax; j++)
					Grafo[i][j] = Flota[j]->Get_vida() != 0 && i != j &&
				/*	(Flota[j]->Get_y() !=  Flota[i]->Get_y()) &&*/(Flota[j]->Get_x() != Flota[i]->Get_x()) ?
					double(((Flota[j]->Get_y() - Flota[i]->Get_y())) / double((Flota[j]->Get_x() - Flota[i]->Get_x()))) : INF;

			vector<int> objetivos=rastreador->Algoritmo(Grafo, 0, 8, FlotaMax);
			for (int i = objetivos.size() - 1; i >= 0; i--)
				Humano->Calcular_Danio(objetivos[i], 30);
		break;
	}
  	

}

#endif // !_Controlador_