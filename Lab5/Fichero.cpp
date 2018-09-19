//
// Created by jimmy on 21/08/18.
//
#include "Fichero.h"

Fichero::Fichero() {

}

void Fichero::leerArchivo(string s) {
    diccionario.crear();
    nArchivo = s;
    ifstream fichero;
    fichero.open(nArchivo.c_str());
    if(!fichero.fail()){
        while(!fichero.eof()){
            string linea;
            getline(fichero, linea);
            string::iterator it = linea.begin();
            string::iterator aux;
            for(it; it != linea.end(); it++){
                if(*it == '<'){
                    aux = it+1;
                    string palabra;
                    while(*aux != ' ' && *aux != '>') {
                        palabra += *aux;
                        aux++;
                    }
                    it = aux;
                    diccionario.agregar(palabra);
                }
            }
        }
        fichero.close();
    }
    diccionario.ordenar();
    //diccionario.destruir();
}

void Fichero::opcional(string nombre) {
    ofstream nuevo(nombre);
    string archO;
    cout << "Escriba el nombre del archivo xml original. (Con el .xml)" << endl;
    cin >> archO;
    ifstream fichero;
    fichero.open(archO.c_str());
    //--------------------------------------------------------------------
    if(!fichero.fail()){
        while(!fichero.eof()){
            string linea = "";
            getline(fichero, linea);
            string::iterator it = linea.begin();
            string::iterator aux;
            for(it; it != linea.end(); it++){
                //cout << linea << endl;
                if(*it == '>'){
                    aux = it+1;
                    string palabra = "";
                    while(*aux != '<' && *aux != '\n' && *aux != 0) {
                        palabra += *aux;
                        aux++;
                    }

                    //it = aux;
                    nuevo << palabra << endl;
                }
            }
            //cout << palabra << endl;
            //nuevo << linea << endl;
        }
        fichero.close();
    }
    //-------------------------------------------------------------------------
    nuevo.close();
    cout << "Se ha generado el archivo " << nombre << endl;
}
