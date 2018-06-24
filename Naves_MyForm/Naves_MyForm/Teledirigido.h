#ifndef _TELEDIRIGIDO_
#define _TELEDIRIGIDO_

#include "Misil.h"

class Teledirigido : public Misil
{
public:
	Teledirigido(int danio);
	~Teledirigido();
	void Algoritmo(int Vida[], int Material[]);
	int get_MaterialMax();

private:
	int MaterialMax;
	vector<int>navTel;

};

Teledirigido::Teledirigido(int danio) : Misil::Misil()
{
	this->danio = danio;
}

Teledirigido::~Teledirigido() {}

//Knapsack
void Teledirigido::Algoritmo(int Vida[], int Material[])
{
	nav.clear();
	int *a = new int[100];
	int *temp = new int[100];
	int aux;

	for (int i = 0; i <= 100; i++) {
		a[i] = 0;
		temp[i] = -1;
	}

	a[0] = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j < n; j++)
			if ((Vida[j] <= i) && (a[i] < a[i - Vida[j]] + Material[j])) {
				a[i] = a[i - Vida[j]] + Material[j];
				temp[i] = j;
			}

	aux = 100;

	while ((aux > 0) && (temp[aux] != -1)) {
		navTel.push_back(temp[aux]+1);
		aux -= Vida[temp[aux]];
	}
	Set_nav(navTel);
	MaterialMax = a[100];


	delete[] temp;
	delete[] a;
}

int Teledirigido::get_MaterialMax()
{
	return this->MaterialMax;
}

#endif // !_TELEDIRIGIDO_
