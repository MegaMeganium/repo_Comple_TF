#ifndef _JUGADOR_
#define _JUGADOR_

#include "Nave.h"
#include <map>

#define FlotaMax 8

using namespace std;

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
	void Agregar_Nave(Nave* Nueva_Nave);
	void PosicionarNave(int x, int y);
	void Calcular_Danio(int id, int danio);
	void Rehabilitar_Nave();
	void Cambiar_Estado_Nave();
	void DibujarFlota(Graphics^ g);
};

Jugador::Jugador()
{
	N = new int;
	*N = 8;
	InicializarFlota();
	this->Material_Total = 0;
	this->contadorFlota = 0;
	this->estado = EstadoJugador::Jugando;
}
Jugador::~Jugador() {}

void Jugador::InicializarFlota()
{
	Flota = new Nave*[*N];
	for (auto i = 0; i < *N; i++)
	{
		Flota[i] = new Nave();
		Flota[i]->Set_Id(i);
	}
}

void Jugador::Agregar_Nave(Nave* Nueva_Nave)
{
	Nave** aux = new Nave*[*N + 1];
	for (int i = 0; i < *N; i++)
		aux[i] = Flota[i];
	aux[*N] = Nueva_Nave;
	delete Flota;
	Flota = aux;
	*N = *N + 1;
}

void Jugador::PosicionarNave(int x, int y)
{
	if (!(contadorFlota < FlotaMax)) return;
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
				Cambiar_Estado_Nave();
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
	for (int i = 0; i < *N; i++)
		if (Flota[i]->Get_vida() == 0)
			Flota[i]->Set_estado(EstadoNave::FueraCombate);
		else
			Flota[i]->Set_estado(EstadoNave::Vivo);
}

void Jugador::DibujarFlota(Graphics^ g)
{
	for (auto i = 0; i < *N; i++) 
	{
		Flota[i]->DibujarNave(g);
	}
}

#endif // !_JUGADOR_