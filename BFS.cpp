#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
 
using namespace std;
 
 vector <vector <int >> tree; // Declara un vector bidimensional
 int flag [10]; // Se utiliza para buscar los primeros nodos del nodo i
 queue <int> M; // Declarar una cola
int ar_tree[8] = { 1,1,1,3,5,3,5,7 };
void BFS(int node) {
	int temp;
	cout << node << " ";
	 // Eliminar el primer nodo de la cola
	int m_first = M.front();
	M.pop();
	while(flag[node] < tree[node].size()) {
		temp = tree[node][flag[node]];
		flag[node]++;
		 // Añadir temp a la cola
		M.push(temp);
	}
	if (!M.empty()) {
		BFS(M.front());
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(flag, 0, sizeof(flag));
	int i,temp;
	 tree.resize (10); // Hay nueve nodos en la figura
	 // árbol de expansión
	for (i = 2; i <=9; i++) {
		temp = ar_tree[i - 2];
		 tree [temp] .push_back (i); // Indica que el nodo i-ésimo es hijo del nodo temp-ésimo
	}
	//BFS
	 cout << "Proceso BFS:" << endl;
	M.push(1);
	BFS(1);
	cout << endl;
	return 0;
  }
