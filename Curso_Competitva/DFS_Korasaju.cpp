#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX_N 20001

using namespace std;

vector<int> res;
string Vert = "abcdefgh";

class Grafo{
  private:
  int n_vertices;
  list<int> *adjList;
  list<int> *revList;
  bool *visitados;

  stack<int> S;
  list<int> *components;
  int numComponents;

  public:

  Grafo(int n){
    n_vertices=n;
    adjList= new list<int>[n];
    revList= new list<int>[n];
    visitados = new bool[n_vertices];
    components = new list<int>[n];
    numComponents=0;
  }

  //insertar
  void insEdge(int ini, int fin){
    adjList[ini].push_back(fin);
    revList[fin].push_back(ini);
  }


  void DFS2(int v) 
  { 
    visitados[v] = true; 
    cout << v << "\t";
    components[numComponents].push_back(v);
    list<int>::iterator i; 
    for(i = revList[v].begin(); i != revList[v].end(); ++i) 
      if(!visitados[*i]) 
        DFS2(*i); 
  } 


  void DFS(int v) 
  { 
    visitados[v] = true; 
       
    list<int>::iterator i; 
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
    if(!visitados[*i]) 
      DFS(*i); 
    S.push(v);
  } 

  void Kosaraju(){

    for(int i=0;i<n_vertices;i++){
      visitados[i]=false;
    }

    for(int i=0;i<n_vertices;i++){
      if(!visitados[i])
        DFS(i);
    }
  
    for(int i=0;i<n_vertices;i++){
      visitados[i]=false;
    }

    while(!S.empty()){
      int v = S.top(); 
      S.pop();
        if (!visitados[v])
        {
            cout<<"Grupo "<<numComponents<<": ";
            DFS2(v);
            numComponents++;
            cout<<"\n";
        }
    }
    cout<<endl;
    for(int i=0;i<numComponents;i++){
      cout<<"Grupo "<<i<<": ";
      list<int>::iterator j; 
      for(j = components[i].begin();j != components[i].end();++j){
        cout<<Vert[*j]<<"\t";
      }
      cout<<endl;
    }
    
  }
};





int main() {
  
  Grafo g1(8);
  g1.insEdge(0,1);//a->b

  g1.insEdge(1,2);//b->c
  g1.insEdge(1,4);//b->e
  g1.insEdge(1,5);//b->f
  
  g1.insEdge(2,3);//c->d
  g1.insEdge(2,6);//c->g
  
  g1.insEdge(3,2);//d->c
  g1.insEdge(3,7);//d->h
  
  g1.insEdge(4,0);//e->a
  g1.insEdge(4,5);//e->f
  
  g1.insEdge(5,6);//f->g
  
  g1.insEdge(6,5);//g->f
  
  g1.insEdge(7,3);//h->d
  g1.insEdge(7,6);//h->g

  g1.Kosaraju();
}
