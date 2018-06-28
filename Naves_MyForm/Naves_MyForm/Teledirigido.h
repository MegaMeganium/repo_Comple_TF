#ifndef _TELEDIRIGIDO_
#define _TELEDIRIGIDO_

#include "Misil.h"

class Teledirigido : public Misil
{
private:
	int MaterialMax;
	vector<int>navTel;

public:
	Teledirigido();

	~Teledirigido();
	void ordenar(vector<pair<int, iPair>>&obj);
	bool verificar(int j, int temp[], int k);
	void Algoritmo(int n, int Vida[], int Material[], int indice[]);
	int get_MaterialMax();


};


Teledirigido::Teledirigido() : Misil::Misil()
{

}
Teledirigido::~Teledirigido() {}

void Teledirigido::ordenar(vector<pair<int, iPair>>&obj)
{
	pair<int, iPair>aux;
	for (int i = 0; i<obj.size(); i++)
		for (int j = i + 1; j<obj.size(); j++)

			if (obj[i].second.first>obj[j].second.first) {
				aux = obj[i];
				obj[i] = obj[j];
				obj[j] = aux;

			}
}

bool Teledirigido::verificar(int j, int temp[], int k)
{
	int in = 0;
	for (int i = 0; i < k; i++)
	{
		if (temp[i] == j)
			in = 1;
	}
	if (in == 1)
		return false;
	else
		return true;
}

//Knapsack
void Teledirigido::Algoritmo(int n, int Vida[], int Material[], int indice[])
{
	int *a = new int[VMax];
	int *temp = new int[VMax];
	int aux;

	for (int i = 0; i <= VMax; i++) {
		a[i] = 0;
		temp[i] = -1;
	}

	a[0] = 0;
	for (int i = 1; i <= VMax; i++)
		for (int j = 1; j <= n; j++) {
			if (verificar(j, temp, i) == false)
				a[i] += Material[j];
			if ((Vida[j] <= i) && (a[i] < a[i - Vida[j]] + Material[j]) && (verificar(j, temp, i) == true)) {
				a[i] = a[i - Vida[j]] + Material[j];
				temp[i] = j;
			}
		}

	aux = VMax;
	int tempM = VMax;
	while ((aux <= VMax) && (aux>0)) {
		if (temp[aux] != -1) {
			navTel.push_back(indice[temp[aux]]);
			//cout << "Se agrego " << indice[temp[aux]] << " ($" << Material[temp[aux]] << ", " << Vida[temp[aux]] << "Kg) Espacio disponible: " << tempM - Vida[temp[aux]] << endl;
			//tempM -= Vida[temp[aux]];
		}
		aux -= Vida[temp[aux]];
	}
	//cout << "Valor total: $" << a[VMax] << endl;
	MaterialMax = a[VMax];
	delete[] temp;
	delete[] a;
}

int Teledirigido::get_MaterialMax()
{
	return this->MaterialMax;
}

#endif // !_TELEDIRIGIDO_
