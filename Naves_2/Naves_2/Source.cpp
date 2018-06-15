#include "Personaje.h"
#include "Balas.h"
#include "Enemigo.h"
#include <list>


void Jugar(CPersonaje *personaje)
{
	int i = -1;
	int y = 0;
	CEnemigo *aux = new CEnemigo();
//	list<CBalas> Balas;
//	CBalas *aux = new CBalas();
	char movimiento;
	personaje->Dibujar();
	while (1)
		if (_kbhit())
		{
			i = i*-1;
			aux->Dibujar();
			personaje->BorrarPersonaje();
			movimiento = _getch();
			movimiento = toupper(movimiento);
			movimiento == 'A' ? personaje->Set_x(-1) : movimiento == 'S' ? personaje->Set_y(+1) :
				movimiento == 'D' ? personaje->Set_x(1) : movimiento == 'W' ? personaje->Set_y(-1) : 0;
	/*		if (movimiento == 'T')
				aux->Set_Posicion(personaje->Get_x(), personaje->Get_y());
			aux->Mover();
			aux->Dibujar();
			aux->Borrar();*/
			aux->Mover(i);
			aux->BorrarPersonaje();
			personaje->Dibujar();
		}

}

int main()
{
	CPersonaje *personaje = new CPersonaje();
	Jugar(personaje);
	_getch();
	return 0;
}

