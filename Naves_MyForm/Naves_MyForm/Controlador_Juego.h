#pragma once
#include "Jugador.h"

class Controlador_Juego
	{
		private:
			Jugador *Humano;
			Jugador *Maquina;
			//Jugador **Jugadores;
		public:
			Controlador_Juego();
			~Controlador_Juego();
	};