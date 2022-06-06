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


//---------------------------------------------------------------------
int encontrar_ec(vector<string> ecuaciones, string ec) {
    for (int i = 0; i < ecuaciones.size(); i++) {
        int contador = 0;
        for (int j = 0; j < ecuaciones[i].size(); j++) {
            if (contador == ec.size() - 1) {
                return i;
            }
            if (ecuaciones[i][j] == ec[j]) {
                contador++;
            }
        }
    }
    return -1;
}

void sumatoria_dinamica(vector<int> lista, vector<vector<int>>* ecuaciones, int valor) {
    int suma;
    vector<int> ec;
    for (int j = lista.size() - 1; j >= 0; j--) {
        suma = lista[j];
        ec.push_back(lista[j]);
        int contador = 0;
        for (int i = lista.size() - 1; i >= 0;) {
            if (suma + lista[i] <= valor) {
                suma += lista[i];
                ec.push_back(lista[i]);
                int i = lista.size() - 1;
            }
            else {
                if (suma == valor) {
                    ecuaciones->push_back(ec);
                    suma = lista[j];
                    ec.clear();
                    contador++;
                    i = lista.size() - 1-contador;
                }
                else {
                    i--;
                }
                //i--;
            }
        }
    }
}



int main()
{
    vector<vector<int>> ecuaciones;
    vector<int> lista = { 1,2,3 };
    
    vector<vector<int>> sumatorias;
    for (int i = 0; i < lista.size() - 1;) {
        sumatoria_dinamica(lista, &sumatorias, lista[i]);
    }
    sumatoria_dinamica(lista, &ecuaciones, 5);
    /*
    for (int j = lista.size()-1; j >= 0; j--) {
        for (int i = j; i >= 0; i--) {
            sumatoria(lista,&ecuaciones, lista[j], to_string(lista[j]), i, 5);
           // sumatoria(lista, &ecuaciones, lista[i], to_string(lista[i]), i, 5);
        }
    }
    */
    for (int i = 0; i < ecuaciones.size(); i++) {
        for(int j=0;j<ecuaciones[i].size();j++)
            cout << ecuaciones[i][j] << "\t+\t";
        cout << endl;
    }
}
