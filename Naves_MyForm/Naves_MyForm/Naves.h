#pragma once

using namespace System;
using namespace System::Drawing;

class Naves
	{
		private:
			int id;
			int x;
			int y;
			int vida;
			int material;
			char tipo; //A= Escudo, C=Nave_casador,B=Nodriza
			char estado; // V=vivo, M= Muerto, F=Fuera de combate 
		public:
			Naves(int id,int x, int y, int vida, int material, int tipo, int estado);
			~Naves();

			int Get_id();
			int Get_x();
			int Get_y();
			int Get_vida();
			int Get_material();
			char Get_tipo();
			char Get_estado();
			
			void Set_x(int x);
			void Set_y(int y);
			void Set_vida(int vida);
			void Set_material(int material);
			void Set_tipo(char tipo);
			void Set_estado(char estado);
			
			void Dibujar(Graphics^g, int x, int y,int estado,int ancho, int largo ,int tipo);


	};

Naves::Naves(int id,int x, int y, int vida, int material, int tipo, int estado)
	{
		this->id = id;
		this->x = x;
		this->y = y;
		this->vida = vida;
		this->material = material;
		this->tipo = tipo;
		this->estado = estado;
	}
Naves::~Naves(){}

int Naves:: Get_id() { return this->id; }
int Naves::Get_x() { return this->x; }
int Naves::Get_y(){ return this->y; }
int Naves::Get_vida(){ return this->vida; }
int Naves::Get_material(){ return this->material; }
char Naves::Get_tipo(){ return this->tipo; }
char Naves::Get_estado(){ return this->estado; }
	 
void Naves::Set_x(int x){ this->x = x; }
void Naves::Set_y(int y){ this->y = y; }
void Naves::Set_vida(int vida){ this->vida = vida; }
void Naves::Set_material(int material){ this->material = material; }
void Naves::Set_tipo(char tipo){ this->tipo = tipo; }
void Naves::Set_estado(char estado){ this->estado = estado; }

void Naves::Dibujar(Graphics^g, int x, int y, int estado,int ancho ,int largo ,int tipo)
	{
		Pen^ tr = gcnew Pen(Brushes::Black, 5);
		g->DrawRectangle(tr,x, y, ancho, largo);
		g->FillRectangle(Brushes::Yellow, x, y, ancho, largo);
	}