#ifndef __Balas_H
#define	__Balas_H

#include <iostream>
using namespace std;

class CBalas
{
private:
	int x=0;
	int y=0;
	int tipo=0;

public:
	CBalas();
	~CBalas();
	void Set_Posicion(int x, int y);
	void Mover();
	void Borrar();
	void Dibujar();
	int Get_X();
	int Get_Y();

};


CBalas::CBalas()
{

}
CBalas::~CBalas() {}
void CBalas::Set_Posicion(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
void CBalas::Mover()
{
	y--;
}

void CBalas::Borrar()
{
	System::Console::SetCursorPosition(x, y);
	cout << " ";
}

void CBalas::Dibujar()
{
	System::Console::SetCursorPosition(x, y);
	cout << char(65);
}
int CBalas::Get_X() { return x; }
int CBalas::Get_Y() { return y; }



#endif
