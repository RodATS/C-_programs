#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include <fstream>

#define MAX 1005 //numero max de vertices
using std::stoi;
using namespace std;

//UNion-find
int padre[MAX]; //contiene al padre del iesimo nodo

//Método de inicialización
void MakeSet(int n){
  for(int i=0; i<=n;i++){
    padre[i]=i;
  }
}

//Método para encontrar la raiz del vertice actual X
int Find(int x){
  return (x==padre[x])?x:padre[x]=Find(padre[x]);
}

//étood para unir 2 componentes conexas
void Union(int x, int y){
  padre[Find(x)]=Find(y);
}

//Método que me determina si 2 vértices estan en la misma componente conexa
bool sameComponent(int x, int y){
  if(Find(x)==Find(y)) return true;
  return false;
}

//Fin Uion-Find

int V, E;//numero vertices y aristas

//Estructura Arista Edge
struct Edge {
  int origen;
  int destino;
  int peso;
  Edge(){}
  //Comparador por peso, me servira al momento de ordenar lo realizara en orden ascendente
//Cambiar signo a > para obtener el arbol de expansion maxima
  bool operator<( const Edge &e)const{
    return peso<e.peso;
  }
}arista[MAX];//Arreglo de aristas para el kruskal

Edge MST[MAX];//arreglo de aristas del MTS encontrado

void Kruskal(){
  int origen , destino , peso;
  int total = 0; //Peso total del MST    
  int numAristas = 0;     //Numero de Aristas del MST

  MakeSet(V);//Inicializamos cada componente
  sort(arista,arista+E);//Ordenamos las aristas por su comparador

  for(int i=0;i<E;i++){//Recorremos las aristas ya ordenadas por peso
    origen=arista[i].origen; //Vertice origen de la arista actual
    destino=arista[i].destino; //vertice destino de la arista actual
    peso=arista[i].peso;//peso de la arista actual

    //Verificamos si estan o no en la misma componente conexa
    if(!sameComponent(origen,destino)){//Evitar ciclos
      total+=peso;//Incremento el peso total del MST
      MST[numAristas++]=arista[i];//Agrego al MST la arista actual
      Union(origen, destino); //Union de ambas componentes en una sola
    }
    
  }

   //Si el MST encontrado no posee todos los vértices mostramos mensaje de error    
  //Para saber si contiene o no todos los vértices basta con que el numero    
  //de aristas sea igual al numero de vertices - 1
  if(V-1 != numAristas){
    puts("No existe MST valido para e grafo ingresado, el grafo debe esr conexo"); return;
  }

  puts("----El MTS encontrado contiene las siguientes aristas-----");
  for(int i=0;i<numAristas;i++){
    printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso ); //( vertice u , vertice v ) : peso
  }

  printf("El costo minimo de todas las aristas del MTS es :%d\n",total);
  }



int main(){

  
  
  int mst;
  scanf("%d %d", &V, &E);
  
  
   //Realizamos el ingreso del grafo, almacenando las aristas en un arreglo con los datos respectivos    
  for( int i = 0 ; i < E ; i++ )        
      scanf("%d %d %d" , &arista[ i ].origen , &arista[ i ].destino , &arista[ i ].peso );
  
    Kruskal();
    return 0;
  }
