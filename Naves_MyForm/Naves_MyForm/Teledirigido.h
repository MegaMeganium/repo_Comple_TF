#ifndef _TELEDIRIGIDO_
#define _TELEDIRIGIDO_

#include "Misil.h"

class Teledirigido : public Misil
{
public:
	Teledirigido(int danio);
	~Teledirigido();

	void Algoritmo();

private:

};

Teledirigido::Teledirigido(int danio) : Misil::Misil()
{
	this->danio = danio;
}

Teledirigido::~Teledirigido() {}

void Teledirigido::Algoritmo()
{

}

#endif // !_TELEDIRIGIDO_