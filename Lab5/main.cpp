#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "Fichero.h"

/*
 * Compilar usando "g++ Diccionario.cpp Fichero.cpp main.cpp" (sin las comillas)
 * y ejecutar el programa con "./a.out ejemploXML.xml" (sin las comillas).
 * Para ejecutar el punto opcional debe hacerlo con el comando:
 * "./a.out -t nombreDeArchivo.xml" (sin las comillas).
 */

using namespace std;

int main(int argc, char *argv[]) {
    Fichero fichero;
    string param = argv[1];
    if(param.compare("-t") == 0) {
        string nombre = argv[2];
        fichero.opcional(nombre);
    }
    else {
        string archivo = argv[1];
        fichero.leerArchivo(archivo);
    }

    //return 0;
}
