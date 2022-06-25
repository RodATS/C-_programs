#include <vector>
#include <iostream>
#include<list>
#include<deque>
using namespace std;

struct Nodo;

struct Arista {
	int valor;
	Nodo* nodos[2];

};

struct Nodo {
	int valor;
	vector<Arista*> aristas;
	bool visitado = false;
};




class Grafo {
public:
	deque<Nodo*> nodos;
	//--------------------------------------------
	Nodo* Inser_Nodo(int n) {
		Nodo* tmp = new Nodo;
		tmp->valor = n;
		nodos.push_back(tmp);
		return tmp;
	}

	//--------------------------------------------
	void Inser_Arista(Nodo* a, Nodo* b, int n=0) {
		Arista* tmp = new Arista;
		tmp->nodos[0] = a;
		tmp->nodos[1] = b;
		tmp->valor = n;
	}


	//--------------------------------------------
	bool Buscar(deque<Nodo*>lista, Nodo* n) {
		for (int i = 0; i < lista.size(); i++) {
			if (n->valor = lista[i]->valor) {
				return true;
			}
		}
		return false;
	}
	/*
	//---------------------------------------------
	void Print_DFS(deque<Nodo*>visi) {
		for (int i = 0; i < visi.size(); i++) {
			cout << visi[i]->valor << " - ";
		}
	}
	//--------------------------------------------
	void DFS(Nodo* nodito) {
		deque<Nodo*>visitados;
		deque<Nodo*>stack;
		Nodo* n;
		for (int i = 0; i < nodos.size(); i++) {
			if (nodito->valor == nodos[i]->valor) {
				n = nodos[i];
			}
		}
		visitados.push_back(n);
		
		for (int i = 0; i < n->aristas.size(); i++) {
			if (!Buscar(visitados, n->aristas[i]->nodos[1])) {
				stack.push_back(n->aristas[i]->nodos[1]);
			}
		}
		
		while (!stack.empty()) {
			n = stack[0];
			visitados.push_back(n);
			stack.pop_front();
			for (int i = 0; i < n->aristas.size(); i++) {
				if (!Buscar(visitados, n->aristas[i]->nodos[1])) {
					stack.push_back(n->aristas[i]->nodos[1]);
				}
			}
		}

		Print_DFS(visitados);

	}*/
};


int main()
{
	Nodo* nodes[5];
	Grafo g;
	for (int i = 0; i < 5; i++) {
		nodes[i] = g.Inser_Nodo(i);
	}
	//nodo 0
	g.Inser_Arista(nodes[0], nodes[1]);
	g.Inser_Arista(nodes[0], nodes[2]);
	g.Inser_Arista(nodes[0], nodes[3]);

	//Nodo 1
	g.Inser_Arista(nodes[1], nodes[0]);
	g.Inser_Arista(nodes[1], nodes[2]);

	//Nodo 2
	g.Inser_Arista(nodes[2], nodes[0]);
	g.Inser_Arista(nodes[2], nodes[1]);
	g.Inser_Arista(nodes[2], nodes[4]);


	//Nodo 3
	g.Inser_Arista(nodes[3], nodes[0]);

	//g.DFS(nodes[0]);
	return 0;
}
