#ifndef _Helpers_
#define _Helpers_

namespace Helpers 
{
	namespace Estados 
	{
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
	
	char ArandB() 
	{
		int aux = rand() % 102 + 1;
		if (aux >= 1 && aux <= 50)
			return 'A';
		return 'B';
	}

	namespace Nave 
	{
		int X_Recalculation(int x, int ancho) 
		{
			return x - (ancho / 2);
		}

		int Y_Recalculation(int y, int altura)
		{
			return y - (altura / 2);
		}

		const int GetvidaMax(Estados::TipoNave tipo) 
		{
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

		std::string GetSprite(Estados::TipoNave tipo, Estados::Bando bando) 
		{
			std::stringstream aux;
			switch (tipo)
			{
			case Estados::TipoNave::Escudo:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\DefensaAliada_" << ArandB() << ".png";
				else
					aux << "Naves\\DefensaEnemiga_" << ArandB() << ".png";
				break;
			case Estados::TipoNave::Cazador:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\CazaAliada_" << ArandB() << ".png";
				else
					aux << "Naves\\CazaEnemiga_" << ArandB() << ".png";
				break;
			case Estados::TipoNave::Nodriza:
				aux.clear();
				if (bando == Estados::Bando::Aliado)
					aux << "Naves\\NodrizaAliada.png";
				else
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
