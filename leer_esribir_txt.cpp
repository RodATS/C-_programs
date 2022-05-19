#include <iostream>
#include <fstream>//libreria para trabajar con txt
#include <stdlib.h> //sirve para salir de un programa: exit(1)
#include <string>

using namespace std;

void lectura(string nombreArch) {
    ifstream archivo_txt;
    string texto_txt;
    string linea;
    //archivo_txt.open("archivo_1.txt", ios::in);//abrir el archivo en modo lectura
    archivo_txt.open(nombreArch.c_str(), ios::in);

    //en caso no exista el txt
    if (archivo_txt.fail()) {
        cout << "No es pudo abrir el archivo";
        exit(1);
    }

    //leer el txt y almacenarlo en un string
    while (!archivo_txt.eof()) {//mientras no sea el final del archivo - eof recorre todo el archivo
        getline(archivo_txt, linea);//para usar getline usa libreria string
        texto_txt += linea + "\n";
    }
    archivo_txt.close();
    cout << texto_txt << endl;
    
    

}

int main()
{
    
    string nombreArchivo;
    cout << "Ingresar nombre del txt a crear: ";
    getline(cin, nombreArchivo);


    //estructura para generar un archivo
    ofstream archivo;//declarando la variable tipo archivo
    archivo.open(nombreArchivo.c_str(), ios::out);
    //archivo.open("archivo1.txt",ios::out);//esta en la ubicación del proyecto este txt, acá se crea y abre
    
    //en caso no se pudo abrir o crear el txt
    if (archivo.fail()) {
        cout << "No es pudo abrir el archivo";
        exit(1);
    }


    //para escribir en el txt
    archivo<<"Lo lograste\n";
    archivo << "Ayuda\n";


    archivo.close();//es necesario cerrarse el archivo
    
    cout << "lectura e imoresion:" << endl;
    lectura(nombreArchivo);

    return 0;
}
