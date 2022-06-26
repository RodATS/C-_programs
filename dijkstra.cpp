class GrafChar : public Graf<char, int> {
public:
	typedef Cam<G> Recorrido;
	Recorrido camino(vector<Recorrido> lerute, Nodo* actual) {
		for (int i = 0; i < lerute.size(); i++) {
			if (lerute[i].nodos_recorrido[lerute[i].nodos_recorrido.size() - 1]->n_v == actual->n_v) return lerute[i];
		}
		return Recorrido(actual);
	}
	bool bus_rec(Recorrido r, Nodo* n) {
		for (int i = 0; i < r.nodos_recorrido.size(); i++) {
			if (r.nodos_recorrido[i]->n_v == n->n_v) {
				return 1;
			}
		}
		return 0;
	}
	void nivelar(vector<Recorrido>& res) {
		bool rpta = true;
		while (rpta) {
			rpta = false;
			for (int i = 0; i < res.size(); i++) {
				for (int j = i + 1; j < res.size(); j++) {
					if (res[i].nodos_recorrido[0] == res[j].nodos_recorrido[0] && res[i].nodos_recorrido[res[i].nodos_recorrido.size() - 1] == res[j].nodos_recorrido[res[j].nodos_recorrido.size() - 1]) {
						if (res[i].peso_actual < res[j].peso_actual) {
							res.erase(res.begin() + j);
						}
						else {
							res.erase(res.begin() + i);
						}
						rpta = true;
					}
				}
			}
		}
	}
	void busqueda(vector<Recorrido>& res, Nodo* n, Arista* arista) {
		Recorrido act = camino(res, arista->m_nodos[0]);
		act.nodos_recorrido.push_back(arista->m_nodos[1]);
		act.peso_actual += arista->m_v;
		res.push_back(act);
		for (int i = 0; i < n->aristas.size(); i++) {
			if (!(pos_node(n->aristas[i], n))) {
				if (!bus_rec(act, n->aristas[i]->m_nodos[1])) {
					nivelar(res);
					busqueda(res, n->aristas[i]->m_nodos[1], n->aristas[i]);
				}
			}
		}
	}
	vector<Recorrido> Dikjstra(N nombre) {
		vector<Recorrido> resultado;
		int pos;
		if (buscar_nodo(nombre, pos)) {
			Recorrido actual(g_node[pos]);
			resultado.push_back(actual);
			for (int i = 0; i < g_node[pos]->aristas.size(); i++) {
				if (!(pos_node(g_node[pos]->aristas[i], g_node[pos]))) {
					busqueda(resultado, g_node[pos]->aristas[i]->m_nodos[1], g_node[pos]->aristas[i]);
				}
			}
		}
		nivelar(resultado);
		imp_vec(resultado);
		return resultado;
	}
	void imp_vec(vector<Recorrido> res) {
		for (int i = 0; i < res.size(); i++) {
			res[i].imprimir();
		}
		cout << endl;
	}
	void cam_mas_corto(N nodo1, N nodo2) {
		vector<Recorrido> rpta = Dikjstra(g_node[0]->n_v);

	}
};

typedef Graf<int, int> G;
vector<vector<int>> AdjacencyFromGraph(G g){
  int n = g.cant_nodos();
  vector<int> f(n,0);
  vector<vector<int>> mat(n,f);
  for (auto v: g.g_node){
    for (auto a: v->aristas){
      mat[(v->id)][(a->m_nodos[1]->n_v)-1]=a->m_v;
    }
  }
  return mat;
}
