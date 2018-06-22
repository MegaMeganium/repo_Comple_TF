#ifndef _Nave_
#define _Nave_

#include <ctime>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace Helpers::Estados;
using namespace Helpers::Nave;

#include "Misil.h"

class Nave
{
private:
	int id;
	int x, y, xSprite, ySprite;
	int vida_max; // auxiliar
	const int ancho = 65, largo = 80;
	int vida;
	int material;
	TipoNave tipo;
	EstadoNave estado;
	string sprite;
	Bando bando;

public:
	Nave(Bando bando);
	Nave(int id, int x, int y, TipoNave tipo, Bando bando);
	~Nave();

	int Get_id();
	int Get_x();
	int Get_y();
	int Get_w();
	int Get_h();
	int Get_xSprite();
	int Get_ySprite();
	const int Get_vida_max();
	int Get_vida();
	int Get_material();
	Bando Get_bando();
	TipoNave Get_tipo();
	EstadoNave Get_estado();

	void Set_X_Y(int x, int y);
	void Set_Id(int id);
	void Set_x(int x);
	void Set_y(int y);
	void Set_xSprite(int x);
	void Set_ySprite(int y);
	void Set_vida(int vida);
	void Set_material(int material);
	void Set_bando(Bando bando);
	void Set_tipo(TipoNave tipo);
	void Set_estado(EstadoNave estado);

//	void Dibujar(Graphics^ g, int x, int y, int ancho, int largo);
	void DibujarNave(Graphics^ g);
	bool HayColision(int x, int y);
	bool HayColisionOptimizado(int x, int y);

};
Nave::Nave(Bando bando) 
{
	this->material = 0;
	this->bando = bando;
	this->tipo = TipoNave::Error;
	this->estado = EstadoNave::FueraCombate;
}
Nave::Nave(int id, int x, int y, TipoNave tipo, Bando bando)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->vida = this->vida_max;
	this->material = 0;
	this->tipo = tipo;
	this->estado = EstadoNave::FueraCombate;
	this->bando = bando;
	this->sprite = GetSprite(this->tipo, this->bando);
}
Nave::~Nave() {}

int Nave::Get_id() { return this->id; }
int Nave::Get_x() { return this->x; }
int Nave::Get_y() { return this->y; }
int Nave::Get_xSprite() { return this->xSprite; }
int Nave::Get_ySprite() { return this->ySprite; }
int Nave::Get_w() { return this->ancho; }
int Nave::Get_h() { return this->largo; }
const int Nave::Get_vida_max() { return this->vida_max; }
int Nave::Get_vida() { return this->vida; }
int Nave::Get_material() { return this->material; }
Bando Nave::Get_bando() { return this->bando; }
TipoNave Nave::Get_tipo() { return this->tipo; }
EstadoNave Nave::Get_estado() { return this->estado; }

void Nave::Set_X_Y(int x, int y) 
{
	this->x = x; 
	this->y = y; 
	this->xSprite = X_Recalculation(this->x, this->ancho);
	this->ySprite = Y_Recalculation(this->y, this->largo);
}
void Nave::Set_Id(int id) { this->id = id; }
void Nave::Set_x(int x) { this->x = x; }
void Nave::Set_y(int y) { this->y = y; }
void Nave::Set_xSprite(int x) { this->xSprite = X_Recalculation(this->x, this->ancho); }
void Nave::Set_ySprite(int x) { this->ySprite = Y_Recalculation(this->y, this->largo); }
void Nave::Set_vida(int vida) { this->vida = vida; }
void Nave::Set_material(int material) { this->material = material; }
void Nave::Set_bando(Bando bando) { this->bando = bando; }
void Nave::Set_tipo(TipoNave tipo) 
{ 
	this->tipo = tipo;
	this->vida_max = GetvidaMax(this->tipo);
	this->vida = this->vida_max;
	this->sprite = GetSprite(this->tipo, this->bando);
}
void Nave::Set_estado(EstadoNave estado) { this->estado = estado; }
/*
void Nave::Dibujar(Graphics^g, int x, int y, int ancho, int largo)
{
	Pen^ tr = gcnew Pen(Brushes::Black, 5);
	g->DrawRectangle(tr, x, y, ancho, largo);
	g->FillRectangle(Brushes::Yellow, x, y, ancho, largo);
}
*/

void Nave::DibujarNave(Graphics^ g)
{
	if (estado == EstadoNave::Vivo)
	{
		Bitmap^ img = gcnew Bitmap(gcnew String(sprite.c_str()));
		float a = (float)this->vida;
		float b = (float)this->vida_max;
		int aux = 0;
		img->MakeTransparent(img->GetPixel(0, 0));
		if (bando == Bando::Enemigo)
		{
			g->DrawImage(img, xSprite, ySprite + 50, ancho, -largo);
			aux = -35;
		}
		else 
		{
			g->DrawImage(img, xSprite, ySprite, ancho, largo);
			aux = this->largo;
		}
		g->FillRectangle(Brushes::DarkRed, xSprite, ySprite + aux, ancho, 10);
		g->FillRectangle(Brushes::Red, xSprite, ySprite + aux, (int)(b / a * ancho), 10);
		delete img;
	}
}

bool Nave::HayColision(int x, int y)
{
	Rectangle obj1 = Rectangle(X_Recalculation(this->x, this->ancho), Y_Recalculation(this->y, this->largo), this->ancho, this->largo);
	Rectangle obj2 = Rectangle(X_Recalculation(x, ancho), Y_Recalculation(y, largo), ancho, largo);

	return obj1.IntersectsWith(obj2);
}

bool Nave::HayColisionOptimizado(int x, int y)
{
	if (x >= this->x && x <= this->x + this->ancho && y >= this->y && y <= this->y + this->largo)
		return true;
	return false;
}

#endif // !_Nave_