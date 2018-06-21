#ifndef _Controlador_
#define _Controlador_

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

Controlador_Juego::Controlador_Juego(){}
Controlador_Juego::~Controlador_Juego(){}

#endif // !_Controlador_