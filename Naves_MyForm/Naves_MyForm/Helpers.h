#ifndef _Helpers_
#define _Helpers_

enum EstadoNave
{
	Vivo, Muerto, FueraCombate
};

enum TipoNave
{
	Escudo, Cazador, Nodriza
};

enum EstadoJugador
{
	Victoria, Derrota, Jugando
};

enum Bando
{
	Aliado, Enemigo
};

namespace Extras {
	char getAB() {
		int aux = rand() % 102 + 1;
		if (aux >= 1 && aux <= 50)
			return 'A';
		return 'B';
	}
};

#endif // !_Helpers_
