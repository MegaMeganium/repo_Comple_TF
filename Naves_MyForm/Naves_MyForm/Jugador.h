#pragma once
#include "Naves.h"

using namespace System;
using namespace System::Drawing;

class Jugador 
	{
		private:
			int Material_Total;
			char estado; // V=victoria, P=Perdio, S=Puede seguir jugando
			Naves **Flota;
			int *N;
		public:
			Jugador(int Material_Total, char estado);
			~Jugador();

			void Agregar_Nave(Naves* Nueva_Nave);
			void Calcular_Danio(int id, int danio);
			void Rehabilitar_Nave();
			void Cambiar_Estado_Nave();
	};

Jugador::Jugador(int Material_Total, char estado)
	{
		N = new int;
		*N = 0;
		Flota = new Naves*[*N];
		this->Material_Total = Material_Total;
		this->estado = estado;

	}
Jugador::~Jugador(){}

void Jugador::Agregar_Nave(Naves* Nueva_Nave)
	{
		Naves** aux = new Naves*[*N + 1];
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
			if(Flota[i]->Get_vida()==0)
				{
					Flota[i]->Set_vida(Flota[i]->Get_vida_constante());
					Cambiar_Estado_Nave();
					break;
				}
	}

void Jugador::Cambiar_Estado_Nave()
	{
		for (int i = 0; i < *N; i++)
			if (Flota[i]->Get_vida() == 0)
				Flota[i]->Set_estado('F');
			else
				Flota[i]->Set_estado('V');
	}