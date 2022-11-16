#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int origen, destino, peso;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void printArr(int dist[], int n,int src, string Ver)
{
  cout<<"Desde el vertice "<<Ver[src]<<" hasta:\n";
	for (int i = 0; i < n; ++i)
    cout<<Ver[i]<<"\t\t"<<dist[i]<<endl;

}

void BellmanFord(struct Graph* graph, int src, string S)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

  //Llegar a si mismo
	dist[src] = 0;


  
	for (int i = 0; i <= V - 1; i++) {
    if(i!= src){
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].origen;
			int v = graph->edge[j].destino;
			int peso = graph->edge[j].peso;
			if (dist[u] != INT_MAX  && dist[u] + peso < dist[v])
				dist[v] = dist[u] + peso;
      }
		}
	}



  //saber si hay cilo negativo
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].origen;
		int v = graph->edge[i].destino;
		int peso = graph->edge[i].peso;
		if (dist[u] != INT_MAX	&&  dist[u] + peso < dist[v]) {
			cout<<"Ciclo negativo\n";
			return; 
		}
	}
	printArr(dist, V,src,S);

	return;
}


int main()
{
  
	int V,E;
  cin>>V;
  cin>>E;
	struct Graph* g = createGraph(V, E);
  
  string S = "ABCDE";
  for(int aux=0;aux<E;aux++){
    int i,j,v;
    cin>>i>>j>>v;
    g->edge[aux].origen=i;
    g->edge[aux].destino= j;
	  g->edge[aux].peso= v;
  }
	
	
	BellmanFord(g, 0,S);

	return 0;
}
