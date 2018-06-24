#ifndef _Rastreador_
#define _Rastreador_
#include "Misil.h"
#define INF 9999999

class Rastreador: public Misil
	{
		private:
			vector<int> Objetivos;
			int **distancia;
			int **reccorrido;
		public:
			vector<int> FloydWarshall(int **Grafo, int origen, int destino, int V);
	};
vector<int> Rastreador::FloydWarshall(int **Grafo, int origen, int destino, int V)
	{	
		
		distancia = new int*[V];
		reccorrido = new int*[V];
		for(int i = 0; i < V;i++)
			{
				distancia[i] = new int[V];
				reccorrido[i] = new int[V];
			}
		for(int i = 0; i < V;i++)
			for(int j = 0; j < V;j++)
				{
					distancia[i][j] = Grafo[i][j];
					reccorrido[i][j] = i != j && Grafo[i][j] != INF ? i : -1;
				}
		for(int k = 0;k < V;k++)
			for(int i= 0; i < V; i++)
				for(int j= 0; j < V; j++)
					if(i!=k && distancia[i][k]+distancia[k][j]<distancia[i][j])
						{
							distancia[i][j] = distancia[i][k] + distancia[k][j];
							reccorrido[i][j] = reccorrido[k][j];
						}
		vector<int> objetivos;
		int vertice_auxiliar;
		while(origen!=destino)
			{
				vertice_auxiliar = reccorrido[origen][destino];
				objetivos.push_back(vertice_auxiliar);
				destino = vertice_auxiliar;
			}
		return objetivos;
	}

#endif // !_Rastreador_





/*
#ifndef _RASTREADOR_
#define _RASTREADOR_

#include "Misil.h"

#define INFINITY INT_MAX
class Rastreador : public Misil
{
public:
	Rastreador(int danio);
	~Rastreador();
	void Algoritmo(int src, int dest);
private:
	 struct Edge{
		int u, v, w;
		Edge(int u, int v, int w) :u(u), v(v), w(w) {}
		Edge() {}
	} ;
	int EDGES;
	Edge *edges;
	int *d;
	vector<int>navRas;

};

Rastreador::Rastreador(int danio) : Misil::Misil()
{
	Random a;	
	EDGES = a.Next(14,20);
	this->danio = danio;
	edges = new Edge[EDGES];
	d = new int[n];	
	for (int i = 0;i<EDGES;i++) {
		int u = a.Next(0,15);
		int v = a.Next(0,15);
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = a.Next(-200,200);
	}

}

Rastreador::~Rastreador() {}

void Rastreador::Algoritmo(int src, int dest)
{
	nav.clear();
    for (int i = 0; i < n; i++) {
		d[i] = INFINITY;
	}
	d[src] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < EDGES; j++) {
			if (d[edges[j].u] + edges[j].w < d[edges[j].v]) {
				if (edges[j].v == dest)
					navRas.push_back(edges[j].u);
				d[edges[j].v] = d[edges[j].u] + edges[j].w;
				
			}

		}
	}
	Set_nav(navRas);
}


#endif // !_RASTREADOR_
*/