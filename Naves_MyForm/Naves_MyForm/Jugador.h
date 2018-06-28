#ifndef _JUGADOR_
#define _JUGADOR_

#include "Helpers.h"
#include "Nave.h"
#include "Rastreador.h"
#include <map>

#define FlotaMax 11

class Jugador
{
private:
	int Material_Total;
	EstadoJugador estado;
	Nave **Flota;
	int contadorFlota;

public:
	Jugador(Bando bando);
	~Jugador();

	void InicializarFlota(Bando bando);
	void Agregar_Nave(int x, int y,int width, int height);
	void PosicionarNave(int x, int y, MouseButtons button);
	void Calcular_Danio(int id, int danio);
	void Rehabilitar_Nave();
	void Cambiar_Estado_Nave();
	

	Nave** Get_Flota();
	void DibujarFlota(Graphics^ g, char identificar);
	bool HayColisionEntreNaves(int x, int y);
	
};

Jugador::Jugador(Bando bando)
{
	InicializarFlota(bando);
	this->Material_Total = 0;
	this->contadorFlota = 0;
	this->estado = EstadoJugador::Jugando;
}
Jugador::~Jugador() 
{
	for (int i = 0; i < FlotaMax; i++)
		delete Flota[i];
	delete[] Flota;
}

void Jugador::InicializarFlota(Bando bando)
{
	Flota = new Nave*[FlotaMax];
	for (auto i = 0; i < FlotaMax; i++)
	{
		Flota[i] = new Nave(bando);
		Flota[i]->Set_Id(i);
	}
}

void Jugador::Agregar_Nave(int x, int y, int width, int heighty)
{
	/*
	int aux_x = width / 8;
	int aux_x2 = aux_x / 2;
	int aux_y = heighty - (heighty / 2)-100;
	for (int i = 0; i < FlotaMax; i++)
		{
			Flota[i]->Set_X_Y(aux_x2, aux_y);
			aux_x2 += aux_x;
			if (i  == 7)
				{	 
					aux_y -= (aux_y/2);
				//	aux_x2 = Flota[0]->Get_x();
					aux_x2 = aux_x / 2;
				}
			Flota[i]->Set_estado(EstadoNave::Vivo);
			if (i == 2 || i == 5 || i == 10 || i == 13)
				Flota[i]->Set_tipo(TipoNave::Escudo);
			else
				Flota[i]->Set_tipo(TipoNave::Cazador);
		}*/
	int aux_x = width / 10;
	int aux_x2 = aux_x / 2;
	int aux_y = heighty - (heighty / 2) - 100;
	int aux_y2 = aux_y;
	int ResSum = -1;
	for(int i = 0; i < FlotaMax;i++)
		{
			if(i!=10)
			{ 
				if (i == 5)
					aux_y = Flota[4]->Get_y();
				Flota[i]->Set_X_Y(aux_x2, aux_y);
			
				if (i == 2 || i == 4 || i==7)
					ResSum *= -1;
				Flota[i]->Set_estado(EstadoNave::Vivo);
				if (i == 1 || i == 3 || i == 6 || i == 8)
					Flota[i]->Set_tipo(TipoNave::Escudo);
				else
					Flota[i]->Set_tipo(TipoNave::Cazador);
				aux_x2 += aux_x;
				aux_y += (aux_y2 / 3)*ResSum;
			}
			else
				{ 
					Flota[i]->Set_X_Y(Flota[4]->Get_x() + aux_x / 2, Flota[2]->Get_y());
	//				Flota[i]->Set_xSprite
					Flota[i]->Set_estado(EstadoNave::Vivo);
					Flota[i]->Set_tipo(TipoNave::Nodriza);
				}
		}
}

void Jugador::PosicionarNave(int x, int y, MouseButtons button)
{
	if (!(contadorFlota < FlotaMax) || HayColisionEntreNaves(x, y)) return;
	Flota[contadorFlota]->Set_X_Y(x, y);
	Flota[contadorFlota]->Set_estado(EstadoNave::Vivo);
	Flota[contadorFlota]->Set_tipo(MouseButtons::Left == button? TipoNave::Cazador : TipoNave::Escudo);
	contadorFlota++;
}

void Jugador::Calcular_Danio(int id, int danio)
{
	int Vida_Actualizada = 0;
	for (int i = 0; i < FlotaMax; i++)
		if (Flota[i]->Get_id() == id)
		{
			Vida_Actualizada = Flota[i]->Get_vida() - danio;
			if (Vida_Actualizada < 0)
				Vida_Actualizada = 0;
			Flota[i]->Set_vida(Vida_Actualizada);
			if (Flota[i]->Get_vida() == 0)
				Flota[i]->Set_estado(EstadoNave::FueraCombate);
			break;
		}
}

void Jugador::Rehabilitar_Nave()
{
	for (int i = 0; i < FlotaMax; i++)
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

void Jugador::DibujarFlota(Graphics^ g,char identificar)
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

Nave** Jugador::Get_Flota()
{
	return Flota;
}

#endif // !_JUGADOR_