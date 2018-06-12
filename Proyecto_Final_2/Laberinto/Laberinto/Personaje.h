#ifndef __Personaje_H_
#define	__Personaje_H_
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class CPersonaje
{
private:
	int x;
	int y;

	int puntaje;
public:
	CPersonaje();
	~CPersonaje();
	void Dibujar();
	void BorrarPersonaje();

	int Get_x();
	void Set_x(int x);

	int Get_y();
	void Set_y(int y);

	int Get_Puntaje();
	void Set_Puntaje(int puntaje);


};

CPersonaje::CPersonaje() 
{
	x = 0;
	y = 0;
}
CPersonaje::~CPersonaje() {}
void CPersonaje::Dibujar()
{
	System::Console::SetCursorPosition(x, y);
	cout << 3;
}



void CPersonaje::BorrarPersonaje()
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}

int CPersonaje::Get_x() {return x; }
void CPersonaje::Set_x(int x) { this->x = this->x + x; }

int CPersonaje::Get_y() {return y; }
void CPersonaje::Set_y(int y) { this->y = this->y + y; }

int CPersonaje::Get_Puntaje() { return puntaje; }
void CPersonaje::Set_Puntaje(int puntaje) { this->puntaje =+ puntaje; }



#endif // 