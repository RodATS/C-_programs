#include <iostream>
using namespace std;


struct Vector{
  int *m_pVector,
  m_nCount=0,
  m_nMax=0,
  m_nDelta;
};


  //pThis->m_pVector = realloc(gpVect, sizeof(int) *(pThis->m_nMax + pThis->m_nDelta));

void Resize(Vector *pThis){
  pThis->m_nDelta=5;
  int *aux=new int[pThis->m_nMax+pThis->m_nDelta];
  for(int i=0;i<pThis->m_nCount;i++){
    aux[i]=pThis->m_pVector[i];
  }
  pThis->m_pVector=aux;
  pThis->m_nMax+=pThis->m_nDelta;
}




void Insertar(Vector *pThis, int elem){
  if(pThis->m_nCount==pThis->m_nMax){
    Resize(pThis);
    }
  pThis->m_pVector[pThis->m_nCount]=elem;
  pThis->m_nCount+=1;
}


void Print(Vector *pThis){
  for(int i=0;i<pThis->m_nCount;i++){
    cout<<pThis->m_pVector[i]<<"\t";
  }
  cout<<endl;
}

int main() {
  Vector vect;
  Insertar(&vect,5);
  Insertar(&vect,15);
  Insertar(&vect,65);
  Insertar(&vect,45);
  Insertar(&vect,5);
  Insertar(&vect,15);
  Print(&vect);
}
