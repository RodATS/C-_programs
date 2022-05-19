#include<iostream>
#include <time.h>
using namespace std;

void merge(int *izq,int nIzq,int *der,int nDer,int *A)
{
   int i=0,j=0,k=0;
   while( ( i < nIzq ) && ( j < nDer ) )
   {
    if( izq[i] <= der[j])
    {
     A[k] = izq[i];
     i++;
    }
    else
    {
     A[k] = der[j];
     j++;
    }
    k++;
   }
   while(i < nIzq)
   {
    A[k] = izq[i];
    i++;k++;
   }
   while(j < nDer)
   {
    A[k] = der[j];
    j++;k++;
   }
}


void merge_sort(int *A,int n)
{
   if(n==1){return;}
  
   int mitad = n / 2;
   int *izq = new int[mitad];
   int *der = new int[n-mitad];
  
   for(int i=0;i<mitad;i++){
    izq[i] = A[i];}
  
   for(int i=mitad;i<n;i++){
    der[i-mitad] = A[i];}
  
   merge_sort(izq, mitad);
   merge_sort(der, n-mitad);
   merge(izq, mitad, der, n-mitad, A);
}





void imprimir(int a[],int longitud){
  for(int i=0; i<longitud; i++){
    cout<<a[i]<< " ";
  }
  cout<<endl;
}


int main(){

  unsigned t0, t1;

  
  int num;
  int a[50];
  srand(time(NULL));
  
    for(int c = 1; c <= 100; c++)
    {
        num = 1 + rand() % (101 - 1);
        a[c-1]=num;
    }
  int lon = (sizeof(a)/sizeof(a[0]));
  imprimir(a,lon);
  t0=clock();
  merge_sort(a,lon);
  t1=clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
  imprimir(a,lon);
  cout << "Execution Time: " << time << endl;
}
