#ifndef _Helpers_
#define _Helpers_
namespace Helpers {
	namespace Estados {
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
	};
	
	char getAB() {
		int aux = rand() % 102 + 1;
		if (aux >= 1 && aux <= 50)
			return 'A';
		return 'B';
	}

	namespace Nave {
		const int GetvidaMax(Estados::TipoNave tipo) {
			switch (tipo)
			{
			case Estados::TipoNave::Escudo:
				return 100;
			case Estados::TipoNave::Cazador:
				return 60;
			case Estados::TipoNave::Nodriza:
				return 120;
			default:
				return -3;
			}
		}

		std::string GetSprite(Estados::TipoNave tipo, Estados::Bando bando) {
			std::stringstream aux;
			switch (tipo)
			{
			case Estados::TipoNave::Escudo:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\DefensaAliada_" << getAB() << ".png";
				aux << "Naves\\DefensaEnemiga_" << getAB() << ".png";
				break;
			case Estados::TipoNave::Cazador:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\CazaAliada_" << getAB() << ".png";
				aux << "Naves\\CazaEnemiga_" << getAB() << ".png";
				break;
			case Estados::TipoNave::Nodriza:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\NodrizaAliada.png";
				aux << "Naves\\NodrizaEnemiga.png";
				break;
			default:
				aux.clear();
				aux << "Naves\\_ERROR_.png";
			}
			return aux.str();
		}
	};
};

#endif // !_Helpers_
