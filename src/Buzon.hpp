#ifndef BUZON_H
#define BUZON_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Constante que almacena el de carné.
#define KEY 0xB97664
#define MAX_LENGTH 60
#define MAX_LENGTH_RESULT 5

// Clase encargada de compartir mensajes entre procesos.
class Buzon {
public:
  Buzon();
  void destructor();
  void enviar(char* mensaje);
  void recibir(char* mensaje);

protected:
  int id;

  // Estructura que almacena el contenido de los mensajes.   
  struct msgbuf{
    long int msg_type;
    char text[MAX_LENGTH];
  };
};

#endif // BUZON_H
