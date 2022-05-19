#include <iostream>
#include <time.h>

using namespace std;

int divide(int array[], int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right=right-1;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left=left+1;
        }

        //Intercambio
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // Se da el cruce, hacemos el cambio
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    //Nueva posición del pivot
    return right;
}


void quicksort(int array[], int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        // Ordenacion de los menores
        quicksort(array, start, pivot - 1);

        // Ordenacion de los mayores
        quicksort(array, pivot + 1, end);
    }
}


void imprimir(int a[],int longitud){
  cout<<longitud<<endl;
  for(int i=0; i<longitud; i++){
    cout<<a[i]<< " ";
  }
  cout<<endl;
}
int main() {
  unsigned t0, t1;
  
  int num;
  int l=10000;
  int a[l];
  srand(time(NULL));
  
    for(int c = 1; c <= l; c++)
    {
        num = 1 + rand() % (10001 - 1);
        a[c-1]=num;
    }

  
  int lon = (sizeof(a)/sizeof(a[0]));
  imprimir(a, lon);

  ///////
  t0=clock();
  quicksort(a, 0,lon-1);
  t1=clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;

  ////////
  imprimir(a,lon);
  cout << "Execution Time: " << time << endl;
  
}
