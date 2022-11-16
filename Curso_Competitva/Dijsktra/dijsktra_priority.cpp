#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
# define INF 0x3f3f3f3f


// iPair ==> Integer Pair
typedef pair < int , int > iPair ;


class Graph
{
	int V ; // No. of vertices
	//lista de adjacencia
	list < pair < int , int > > * adj ;


public :
	Graph ( int V )
  {
  	this -> V = V ;
  	adj = new list < iPair > [ V ] ; //lista de adjacencia
  }

	void insert ( int u , int v , int w ) ;
	void Dijsktra ( int s ) ;
};




void Graph :: insert ( int u , int v , int w )
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}


// The shortest routes from src to all other vertices are printed. 
void Graph :: Dijsktra ( int src )
{

	priority_queue < iPair , vector < iPair > , greater < iPair > > pq ;
	vector < int > dist ( V , INF ) ;


	pq.push(make_pair(0 ,src )) ;
	dist [src] = 0 ;

	while ( !pq.empty() )
	{
		int u = pq.top ( ).second ;
		pq.pop( ) ;

		list < pair < int , int > > :: iterator i ;
		for ( i = adj[u].begin() ; i != adj[u].end() ; ++i )
		{
			int v = (*i).first; //a donde va
			int weight = (*i).second;  //peso

			if ( dist [ v ] > dist [ u ] + weight )
			{
				dist [ v ] = dist [ u ] + weight ;
				pq.push ( make_pair ( dist [ v ] , v ) ) ;
			}
		}
	}

	for ( int i = 0 ; i < V ; ++i )
		printf ( "%d\t%d \t \t %d \n" ,src, i , dist [ i ] ) ;
}


int main ( )
{
	int V;
	
  cin>>V;
  Graph g ( V ) ;
  int ed;
  cin>>ed;
  while(ed--){
    int i,j,v;
    cin>>i>>j>>v;
    g.insert(i,j,v);
  }

  
	g.Dijsktra ( 0) ;


	return 0 ;
}
