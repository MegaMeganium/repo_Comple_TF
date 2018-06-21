#ifndef _MISIL_
#define _MISIL_

class Misil {
protected:
	int x, y;

public:
	Misil();
	~Misil();
	virtual void Algoritmo() abstract;
};

Misil::Misil() 
{
}
Misil::~Misil() 
{
}

#endif // !_MISIL_
