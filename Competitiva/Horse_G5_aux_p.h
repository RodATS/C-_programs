#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <chrono>
#include <time.h>
#include <ctime>
using namespace std;
using std::chrono::milliseconds;
using std::chrono::steady_clock;


class Salto_Caballo {
private:
    int N = 8; //tamaño del tablero
    //movimientos posibles
    int h[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int v[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
    vector<vector<int>> tablero;
    bool logrado;
    double time;

public:
    Salto_Caballo(int N_n, int pos_x, int pos_y) {
        auto start = steady_clock::now();
        N = N_n;
        tablero.assign(N, vector<int>(N, 0));
        tablero[pos_x][pos_y] = 1;
        int p;
        Mover_Caballo(2, pos_x, pos_y);
        Print_Tablero();
        auto end = steady_clock::now();
        std::chrono::duration<double, std::milli> float_ms = end - start;
        time = float_ms.count();
    }
//----------------------------------------------------------------------------------------------------------------------
    void Print_Tablero() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j] << "\t";
            }
            cout << "\n";
        }
    }


 //----------------------------------------------------------------------------------------------------------------------
    //prediccion
    void saltos(int x, int y, vector < pair<int, int>>& movimientos) {
        for (int i = 0; i < 8; i++) {
            int n_x = x + h[i];
            int n_y = y + v[i];
            //si esa nueva posicion se encuentra dentro del tablero
            if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && tablero[n_x][n_y] == 0) {
                    //cantidad de saltos - movimiento inicial
                    movimientos.push_back(make_pair(0, i));
                    //ve hasta donde llegaria 
                    for (int j = 0; j < 8; ++j) {
                        int n_x_2 = n_x + h[j];
                        int n_y_2 = n_y + v[j];
                        if (n_x_2 >= 0 && n_x_2 < N && n_y_2 >= 0 && n_y_2 < N && tablero[n_x_2][n_y_2] == 0) {
                            //elemento insertado -> n saltos yendo por ese camino
                            movimientos.back().first += 1;
                            
                        }
                   }
            }
        }
        //ordena segun la cant mov
        sort(movimientos.begin(), movimientos.end());
    }

    //----------------------------------------------------------------------------------------------------------------------
    void Mover_Caballo(int salto, int p_x, int p_y) {

        //listar todos los movimientos (prediccion)
        vector< pair<int, int> > movimientos;
        saltos(p_x, p_y, movimientos);

        int xn, yn;
        logrado = false;
        //si logro recorrer todo - n_saltos
        for ( int m = 0; !logrado && m < movimientos.size();m++) {
            //accede a los movimientos
            xn = p_x + h[movimientos[m].second];
            yn = p_y + v[movimientos[m].second];
            if (xn < N && yn < N) {
                if (tablero[xn][yn] == 0) {
                    tablero[xn][yn] = salto;
                    if (salto < N*N) {
                        Mover_Caballo(salto + 1, xn, yn);
                        if (!logrado) {
                            tablero[xn][yn] = 0;
                        }
                    }
                    else logrado = true;
                }
            }
            salto++;
        }
    }

    //----------------------------------------------------------------------------------------------------------------------
    double Tiempo() {
        return time;
    }

};



//----------------------------------------------------------------------------------------------------------------------
double Horse_G5(int N, int p_x, int p_y) {
    Salto_Caballo caballito(N, p_x, p_y);
    return caballito.Tiempo();
}
