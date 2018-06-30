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
	void heapify(vector<pair<int, iPair>>&obj, int n, int i);
	void heapSort(vector<pair<int, iPair>>&obj, int n);
	bool verificar(int j, int temp[], int k);
	void Algoritmo(vector<pair<int, iPair>>&obj);
	int get_MaterialMax();
	vector<int>get_NavTel();


};


Teledirigido::Teledirigido() : Misil::Misil()
{

}
Teledirigido::~Teledirigido() {}

void Teledirigido::heapify(vector<pair<int, iPair>>&obj, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2;

	if (l < n && obj[l].second.first> obj[largest].second.first)
		largest = l;

	if (r < n && obj[r].second.first > obj[largest].second.first)
		largest = r;

	if (largest != i)
	{
		swap(obj[i], obj[largest]);

		heapify(obj, n, largest);
	}
}
void Teledirigido::heapSort(vector<pair<int, iPair>>&obj, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(obj, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(obj[0], obj[i]);

		heapify(obj, i, 0);
	}
}
bool Teledirigido::verificar(int j, int temp[], int k)
{
	int in = 0;
	for (int i = 0; i <= k; i++)
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
void Teledirigido::Algoritmo(vector<pair<int, iPair>>&obj)
{
	heapSort(obj, obj.size());
	navTel.clear();
	int *a = new int[VMax + 1]; 
	int *temp = new int[VMax + 1]; 
	int aux;

	for (int i = 0; i <= VMax; i++) {
		a[i] = 0;
		temp[i] = -1;
	}

	a[0] = 0;
	for (int i = 1; i <= VMax; i++)
		for (int j = 0; j < obj.size(); j++) {
			int sum = 0;
			if (verificar(j, temp, i) == false)
				a[i] += obj[j].second.second;
			if ((obj[j].second.first <= i) && (a[i] < a[i - obj[j].second.first] + obj[j].second.second) && (verificar(j, temp, i) == true)) {
				a[i] = a[i - obj[j].second.first] + obj[j].second.second;
				temp[i] = j;
			}
			for (int k = 1; k <= n; k++) {
				if (verificar(k, temp, i) == false)
				{
					sum += obj[k].second.second;
					a[i + 1] = sum;
				}
			}
		}

	aux = VMax;
	while ((aux <= VMax) && (aux>0)) {
		if (temp[aux] != -1) {
			navTel.push_back(obj[temp[aux]].first);
			aux -= obj[temp[aux]].second.first;
			//cout << "Se agrego " << indice[temp[aux]] << " ($" << Material[temp[aux]] << ", " << Vida[temp[aux]] << "Kg) Espacio disponible: " << tempM - Vida[temp[aux]] << endl;
			//tempM -= Vida[temp[aux]];
		}
		else
			aux -= 1;

	}
	//cout << "Valor total: $" << a[VMax] << endl;
	MaterialMax = a[VMax];

}

int Teledirigido::get_MaterialMax()
{
	return this->MaterialMax;
}
vector<int> Teledirigido::get_NavTel()
{
	return this->navTel;
}
#endif // !_TELEDIRIGIDO_
