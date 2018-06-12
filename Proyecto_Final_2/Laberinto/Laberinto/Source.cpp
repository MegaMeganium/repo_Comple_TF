#include "Personaje.h"


void Jugar(CPersonaje *personaje)
	{
		int x = 0;
		int y = 0;
		char movimiento;
		while(1)
			if (_kbhit())
				{
					personaje->BorrarPersonaje();
					movimiento = _getch();
					movimiento = toupper(movimiento);
					movimiento == 'A' ? personaje->Set_x(-1) : movimiento == 'S' ? personaje->Set_y(+1) :
					movimiento == 'D' ? personaje->Set_x(1) : movimiento == 'W' ? personaje->Set_y(-1) : 0;
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