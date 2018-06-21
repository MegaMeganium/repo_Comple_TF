#ifndef _JUGADOR_
#define _JUGADOR_

#include "Nave.h"
#include <map>

using namespace std;

class Jugador
{
private:
	int Material_Total;
	EstadoJugador estado;
	Nave **Flota;
	int *N;
public:
	Nave*prueba = new Nave(0, 30, 10,10, TipoNave::Nodriza, Bando::Enemigo);
	Jugador(int Material_Total);
	~Jugador();

	void Agregar_Nave(Nave* Nueva_Nave);
	void Calcular_Danio(int id, int danio);
	void Rehabilitar_Nave();
	void Cambiar_Estado_Nave();
};

Jugador::Jugador(int Material_Total)
{
	N = new int;
	*N = 8;
	Flota = new Nave*[*N];
	this->Material_Total = Material_Total;
	this->estado = EstadoJugador::Jugando;
}
Jugador::~Jugador() {}

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

#endif // !_JUGADOR_