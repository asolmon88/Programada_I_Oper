#include "Semaforo.hpp"

// Método constructor de la clase.
Semaforo::Semaforo(int valorInicial) {
   // Crear semáforo con semget
   if ((this->id = semget(KEY_S, 1, 0660 | IPC_CREAT)) == -1) {
      cerr << "Could not create semaphore" << endl;
   }
   semun arg;
   arg.val = valorInicial;
   semctl(this->id, 0, SETVAL, arg);
}

// Método encargado de eliminar el semáforo.
Semaforo::~Semaforo() {
   // Eliminar semáforo con semctl
   semctl(this->id, 0, IPC_RMID);
}

// Método encargado de poner el semáforo en verde.
void Semaforo::signal() {
   // Utilizar sembuf y semop
   sembuf sb;
   sb.sem_num = 0;
   sb.sem_op = 1;
   sb.sem_flg = 1;
   semop(this->id, &sb, 1);
}

// Método encargado de esperar que el semáforo esté en verde.
void Semaforo::wait() {
   // Utilizar sembuf y semop
   sembuf sb;
   sb.sem_num = 0;
   sb.sem_op = -1;
   sb.sem_flg = 0;
   semop(this->id, &sb, 1);
}
