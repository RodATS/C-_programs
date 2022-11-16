#include <iostream>
using namespace std;

# define INT_MAX 0x3f3f3f3f
#define V 9

int minDistance(int dist[], bool Visitados[])
{
	int min = INT_MAX, index;

	for (int v = 0; v < V; v++)
		if (Visitados[v] == false && dist[v] <= min)
			min = dist[v], index = v;

	return index;
}

void printSolution(int dist[], int s)
{
	cout << "Origen \t Destino \t Distancia" << endl;
	for (int i = 0; i < V; i++)
		cout <<s << " \t\t\t"<< i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool Visitados[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, Visitados[i] = false;

	//Ir a si mismo siemore es 0
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, Visitados);

		Visitados[u] = true;
		for (int v = 0; v < V; v++)
			if (!Visitados[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist, src);
}

int main()
{
	int graph[V][V];

  int edg;
  cin>>edg;
  while(edg--){
    int i,j,v;cin>>i>>j>>v;
    graph[i][j]=v;
  }
	dijkstra(graph, 0);

	return 0;
}
