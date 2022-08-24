#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &A, int tam){
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      cout<<A[i][j]<<"\t";
    }
    cout<<"\n";
  }
}


void elim_gauss(vector<vector<int>> &A, int tam){
  for(int i=1;i<tam;i++){
    int aux=A[i][0]/A[0][0];
    aux=aux*-1;
    for(int j=0;j<tam;j++){
      A[i][j]=A[0][j]*aux+A[i][j];
    }
  }

  for(int i=1;i<tam;i++){
    int aux=A[i][1];
    for(int j=0;j<tam;j++){
      A[i][j]=A[i][j]/aux;
    }
  }

  for(int i=2;i<tam;i++){
    int aux=A[i][1]/A[1][1];
    aux=aux*-1;
    for(int j=0;j<tam;j++){
      A[i][j]=A[1][j]*aux+A[i][j];
    }
  }
}

int main() {
  vector<vector<int>> A={{1,-1,1},{2,3,1},{10,5,-1}};
  cout<<"Antes:\n";
  print(A,3);
  elim_gauss(A,3);
  cout<<"Despues:\n";
  print(A,3);
  
}
