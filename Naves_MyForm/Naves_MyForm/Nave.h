#ifndef _Nave_
#define _Nave_

#include <string>
#include <string.h>
#include <sstream>
#include <ctime>
#include "Helpers.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace Helpers::Estados;
using namespace Helpers::Nave;

class Nave
{
private:
	int id;
	int x, y;
	const int vida_max = GetvidaMax(this->tipo); // auxiliar
	const int ancho = 65, largo = 80;
	int vida;
	int material;
	TipoNave tipo;
	EstadoNave estado;
	string sprite;
	Bando bando;

public:
	Nave();
	Nave(int id, int x, int y, TipoNave tipo, Bando bando);
	~Nave();

	int Get_id();
	int Get_x();
	int Get_y();
	const int Get_vida_max();
	int Get_vida();
	int Get_material();
	TipoNave Get_tipo();
	EstadoNave Get_estado();

	void Set_X_Y(int x, int y);
	void Set_Id(int id);
	void Set_x(int x);
	void Set_y(int y);
	void Set_vida(int vida);
	void Set_material(int material);
	void Set_tipo(TipoNave tipo);
	void Set_estado(EstadoNave estado);

	void Dibujar(Graphics^ g, int x, int y, int ancho, int largo);
	void DibujarNave(Graphics^ g);

};
Nave::Nave() 
{
	this->vida = this->vida_max;
	this->material = 0;
	this->tipo = TipoNave::Cazador;
	this->bando = Bando::Aliado;
	this->estado = EstadoNave::FueraCombate;
	this->sprite = GetSprite(this->tipo, this->bando);
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
const int Nave::Get_vida_max() { return this->vida_max; }
int Nave::Get_vida() { return this->vida; }
int Nave::Get_material() { return this->material; }
TipoNave Nave::Get_tipo() { return this->tipo; }
EstadoNave Nave::Get_estado() { return this->estado; }

void Nave::Set_X_Y(int x, int y) { this->x = x; this->y = y; }
void Nave::Set_Id(int id) { this->id = id; }
void Nave::Set_x(int x) { this->x = x; }
void Nave::Set_y(int y) { this->y = y; }
void Nave::Set_vida(int vida) { this->vida = vida; }
void Nave::Set_material(int material) { this->material = material; }
void Nave::Set_tipo(TipoNave tipo) { this->tipo = tipo; }
void Nave::Set_estado(EstadoNave estado) { this->estado = estado; }

void Nave::Dibujar(Graphics^g, int x, int y, int ancho, int largo)
{
	Pen^ tr = gcnew Pen(Brushes::Black, 5);
	g->DrawRectangle(tr, x, y, ancho, largo);
	g->FillRectangle(Brushes::Yellow, x, y, ancho, largo);
}

void Nave::DibujarNave(Graphics^ g)
{
	if (estado == EstadoNave::Vivo)
	{
		Bitmap^ img = gcnew Bitmap(gcnew String(sprite.c_str()));
		img->MakeTransparent(img->GetPixel(0, 0));
		g->DrawImage(img, x, y, ancho, largo);
		float a = this->vida;
		float b = this->vida_max;
		g->FillRectangle(Brushes::DarkRed, x, y + largo, ancho, 10);
		g->FillRectangle(Brushes::Red, x, y + largo, (int)(b / a * ancho), 10);
		delete img;
	}
}

#endif // !_Nave_