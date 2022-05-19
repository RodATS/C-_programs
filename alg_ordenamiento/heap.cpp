#include <iostream>
using namespace std;

void heap(int arr[], int n, int i)
{
    int largest = i; // El más grande como raiz
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    //en busqueda del mayor para ser la raiz secundaria
    // El hijo izquierdo es mayor
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // El hijo derecho es mayor
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // hace el intercambio
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursivo hasta que el mayor sea la raiz secundaria
        heap(arr, n, largest);
    }
}
 

void heapSort(int arr[], int n)
{
    // construye mini arrays (una rama con hijos)
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);
 
    //Se extraen los elementos
    for (int i = n - 1; i > 0; i--) {
        // Mover la raiz al final
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heap(arr, i, 0);
    }
}

void imprimir(int a[],int longitud){
  for(int i=0; i<longitud; i++){
    cout<<a[i]<< " ";
  }
  cout<<endl;
}


int main() {
  unsigned t0, t1;

  
  int num;
  int a[1000];
  srand(time(NULL));
  
    for(int c = 1; c <= 100; c++)
    {
        num = 1 + rand() % (101 - 1);
        a[c-1]=num;
    }
  int lon = (sizeof(a)/sizeof(a[0]));
  imprimir(a,lon);
  t0=clock();
  heapSort(a,lon);
  t1=clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
  imprimir(a,lon);
  cout << "Execution Time: " << time << endl;
}
