#ifndef __Enemigo_H_
#define	__Enemigo_H_
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;


class CEnemigo
{
private:
	int x;
	int y;

	int vida;
public:
	CEnemigo();
	~CEnemigo();
	void Dibujar();
	void BorrarPersonaje();

	int Get_x();
	void Set_x(int x);

	int Get_y();
	void Set_y(int y);
	
	void Mover(int i);

	int Get_vida();
	void Set_vida(int vida);


};

CEnemigo::CEnemigo()
{
	x = 10;
	y = 5;
}
CEnemigo::~CEnemigo() {}

void CEnemigo::Mover(int  i)
	{
		if(i == 1)
			{
				x += 3;
				y += 2;
			}
		else 
			{
				x += 3;
				y -= 2;
			}
	}

void CEnemigo::Dibujar()
{
	System::Console::SetCursorPosition(x, y);
	cout << char(1);
}



void CEnemigo::BorrarPersonaje()
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}

int CEnemigo::Get_x() { return x; }
void CEnemigo::Set_x(int x) { this->x = this->x + x; }

int CEnemigo::Get_y() { return y; }
void CEnemigo::Set_y(int y) { this->y = this->y + y; }

int CEnemigo::Get_vida() { return vida; }
void CEnemigo::Set_vida(int vida) { this->vida = +vida; }





#endif 