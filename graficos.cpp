#include <iostream>
using namespace std;


int main() {
	int x, mayor=0, menor=1000, veces, veces2, acum1=0, acum2[100], columna, columna2, columna3, columna4;
	x = 3; //cantidad de datos
	int datos[3] = { 520,620,420 };
	int z[3] = { datos[0] / 100, datos[1] / 100, datos[2] / 100 };
	for (int i = 0; i < x; i++) {
		if (mayor < z[i]) {
			mayor = z[i];
		}

		if (menor > z[i]) {
			menor = z[i];
		}

	}

	for (veces = 1; veces <= x; veces++) {
		for (veces2 = 1; veces2 <= x; veces2++) {
			if(z[veces]==z[veces2])
				acum1++;
		}
		acum2[veces] = acum1;
		acum1 = 0;
	}

	columna = mayor;
	columna2 = mayor;
	columna3 = mayor;
	columna4 = mayor;

	for (int i = 0; i < columna; i++) {
		cout << columna2 << " |";
		columna2--;

		for (int j = 0; j < x; j++) {
			if (z[j] >= columna3) {
				cout <<"\t" << "||||"<<"\t";
			}
			else {
				cout << "\t\t";
			}
		}
		columna3--;
		cout << "\n";
	}
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < x; i++) {
		cout << "\t" << "Horse " << i + 1<<"\t";
	}
}
