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
