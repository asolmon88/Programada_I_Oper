#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// Constante que almacena el de carné.
#define KEY_S 0xC06640

// Clase encargada de informar a un proceso cuándo continuar su operación.
class Semaforo {
  public:
    Semaforo(int valorInicial = 0);
    ~Semaforo();
    void signal();
    void wait();

  protected:
    int id;

  // Estructura requerida por el semáforo.
  union semun {
    int val; 
    struct semid_ds* buf;
    unsigned short* array;
    struct seminfo* __buf;
  };
};
#endif // SEMAFORO_H
