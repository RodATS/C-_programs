#include <iostream>
#include <vector>
using namespace std;


int Remove_Prefix(vector<int> A, int n_elementos){
  int contador=0;
  for(int i=n_elementos-1;i>contador;i--){
    int ubicacion=0;
  for(int f=0;f<i;f++){
     if(A[i]==A[f])
     ubicacion=f+1;
   }
   
    if(contador<ubicacion){
      int aux=ubicacion-contador;
      contador=contador+aux;
    }
  }
  return contador;
}


int main() {
  vector<int> respuestas;
  int intentos,n_elementos,elemento;
  cin>>intentos;
  for(int i=0;i<intentos;i++){
    n_elementos=0;
    cin>>n_elementos; 
    vector<int> aux;
    for(int j=0;j<n_elementos;j++){
      cin>>elemento;
      aux.push_back(elemento);
    }

    respuestas.push_back(Remove_Prefix(aux,n_elementos));
  }
  for(int i=0;i<intentos;i++){
    cout<<respuestas[i]<<endl;
  }

}

//https://codeforces.com/contest/1714/problem/B
