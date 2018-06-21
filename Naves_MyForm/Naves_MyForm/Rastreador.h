#ifndef _RASTREADOR_
#define _RASTREADOR_

#include "Misil.h"

class Rastreador : public Misil
{
public:
	Rastreador(int danio);
	~Rastreador();

	void Algoritmo();
private:

};

Rastreador::Rastreador(int danio) : Misil::Misil()
{
	this->danio = danio;
}

Rastreador::~Rastreador() {}

void Rastreador::Algoritmo()
{

}

#endif // !_RASTREADOR_
