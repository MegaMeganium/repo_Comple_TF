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
	void TimerTick(Graphics^ g);
};

Controlador_Juego::Controlador_Juego()
{
	Humano = new Jugador(2);
	Maquina = new Jugador(2);
}
Controlador_Juego::~Controlador_Juego(){}
void Controlador_Juego::TimerTick(Graphics^ g)
{
	Humano->prueba->DibujarNave(g);
}

#endif // !_Controlador_