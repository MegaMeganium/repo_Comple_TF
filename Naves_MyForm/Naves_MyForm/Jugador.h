#ifndef _JUGADOR_
#define _JUGADOR_

#include "Nave.h"
#include <map>

#define FlotaMax 16

class Jugador
{
private:
	int Material_Total;
	EstadoJugador estado;
	Nave **Flota;
	int *N;
	int contadorFlota;
public:
	Nave*prueba = new Nave(0, 30, 10, TipoNave::Nodriza, Bando::Enemigo);
	Jugador();
	~Jugador();

	void InicializarFlota();
	void Agregar_Nave(/*Nave* Nueva_Nave*/int x, int y,int width, int height);
	void PosicionarNave(int x, int y);
	void Calcular_Danio(int id, int danio);
	void Rehabilitar_Nave();
	void Cambiar_Estado_Nave();
	void DibujarFlota(Graphics^ g);
	bool HayColisionEntreNaves(int x, int y);
};

Jugador::Jugador()
{
	N = new int;
	*N = 0;
	InicializarFlota();
	this->Material_Total = 0;
	this->contadorFlota = 0;
	this->estado = EstadoJugador::Jugando;
}
Jugador::~Jugador() {}

void Jugador::InicializarFlota()
{
	Flota = new Nave*[FlotaMax];
	for (auto i = 0; i < FlotaMax; i++)
	{
		Flota[i] = new Nave();
		Flota[i]->Set_Id(i);
	}
}

void Jugador::Agregar_Nave(/*Nave* Nueva_Nave*/int x, int y, int width, int heighty)
{
	int aux_x = width/8;
	int aux_x2 = aux_x / 2;
	int aux_y = heighty - (heighty / 2);
	for (int i = 0; i < FlotaMax; i++)
		{
			Flota[i]->Set_X_Y(aux_x2, aux_y);
			aux_x2 += aux_x;
			if ((i + 1 / 2) == 4)
				aux_y -= aux_y;
			Flota[i]->Set_estado(EstadoNave::Vivo);
		}
}

void Jugador::PosicionarNave(int x, int y)
{
	if (!(contadorFlota < FlotaMax) || HayColisionEntreNaves(x, y)) return;
	Flota[contadorFlota]->Set_X_Y(x, y);
	Flota[contadorFlota]->Set_estado(EstadoNave::Vivo);
	contadorFlota++;
}

void Jugador::Calcular_Danio(int id, int danio)
{
	int Vida_Actualizada = 0;
	for (int i = 0; i < *N; i++)
		if (Flota[i]->Get_id() == id)
		{
			Vida_Actualizada = Flota[i]->Get_vida() - danio;
			if (Vida_Actualizada < 0)
				Vida_Actualizada = 0;
			Flota[i]->Set_vida(Vida_Actualizada);
			if (Flota[i]->Get_vida() == 0)
				Flota[i]->Set_estado(EstadoNave::FueraCombate);
		}
}

void Jugador::Rehabilitar_Nave()
{
	for (int i = 0; i < *N; i++)
		if (Flota[i]->Get_vida() == 0)
		{
			Flota[i]->Set_vida(Flota[i]->Get_vida_max());
			Cambiar_Estado_Nave();
			break;
		}
}

void Jugador::Cambiar_Estado_Nave()
{
	for (int i = 0; i < FlotaMax; i++)
		if (Flota[i]->Get_vida() == 0)
			Flota[i]->Set_estado(EstadoNave::FueraCombate);
		else
			Flota[i]->Set_estado(EstadoNave::Vivo);
}

void Jugador::DibujarFlota(Graphics^ g)
{
	for (auto i = 0; i < FlotaMax; i++) 
	{
		Flota[i]->DibujarNave(g);
	}
}

bool Jugador::HayColisionEntreNaves(int x, int y)
{
	for (auto i = 0; i < contadorFlota; i++)
		if (Flota[i]->HayColision(x, y))
			return true;
	return false;
}

#endif // !_JUGADOR_