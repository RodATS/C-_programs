#include <iostream>
#include <string> //para agregar las ecuaciones
#include <vector> //para guardar las ecuaciones y la lista
using namespace std;


void sumatoria(vector<int> A,vector<string> *ecua, int suma, string ec, int indice, int valor) {

    if ((suma + A[indice]) < valor) {
        ec = ec + "+" + to_string(A[indice]);
        suma = suma + A[indice];
        if (suma + A[indice] <= valor) {
            sumatoria(A,ecua, suma, ec, indice, valor);
            for (int aumentar = 1; indice + aumentar < A.size(); aumentar++) {
                sumatoria(A, ecua, suma, ec, indice + aumentar, valor);
            }
        }
        else {
            if (suma + A[indice] > valor and indice - 1 >=0)//para que no baje en busca de un numero menor ej: n=5 ec=3+
                sumatoria(A,ecua, suma, ec, indice - 1, valor);
            else {
                return;
            }
        }
    }
    else {
        if ((suma + A[indice]) == valor) {
            ec = ec + "+" + to_string(A[indice]);
            suma = suma + A[indice];
           // cout << ec << endl;
            (ecua)->push_back(ec);
            return;
        }
    }
    
}
/*
void datos(int n) {
    int A[n];
    for (int i = n - 1; i >= 0; i--) {
        A[i] = i + 1;
    }
    cout << A[n - 1] << endl;

    for (int j = n - 2; j >= 0; j--) {
        for (int i = j; i >= 0; i--) {
            fun_2(A, A[j], to_string(A[j]), i, n);

        }
    }
}*/

int main()
{
    vector<string> ecuaciones;
    vector<int> lista = { 1,2,3,4 };
    for (int j = lista.size()-1; j >= 0; j--) {
        for (int i = j; i >= 0; i--) {
            sumatoria(lista,&ecuaciones, lista[j], to_string(lista[j]), i, 5);

        }
    }

    for (int i = 0; i < ecuaciones.size(); i++) {
        cout << ecuaciones[i] << endl;
    }
}
