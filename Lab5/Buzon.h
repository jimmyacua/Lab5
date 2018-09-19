//
// Created by jimmy on 11/09/18.
//

#ifndef SEM_BUZONES_BUZON_H
#define SEM_BUZONES_BUZON_H


#define KEY 0xB50060	// Valor de la llave del recurso
#define MSGSIZE 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

class Buzon {
public:
    Buzon();
    ~Buzon();
    int Enviar(char * nmsj, int v);
    int Recibir( char *mensaje, int len );   // len es el tamaño máximo que soporte la variable mensaje
private:
    int id;		// Identificador del buzon
};

#endif //SEM_BUZONES_BUZON_H
