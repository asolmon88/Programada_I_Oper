#include "Buzon.hpp"

// Constructor de la clase.
Buzon::Buzon() {
  this->id = msgget((key_t) KEY, 0666|IPC_CREAT);
}

// Método encargado de eliminar el buzón.
void Buzon::destructor() {
    // struct msqid_ds str;
    // Eliminar el buzón con msgctl
    msgctl(this->id, IPC_RMID, 0);
}

// Método encargado de enviar un mensaje al buzón.
void Buzon::enviar(char* etiqueta) {
    // Inicializar el contenido del mensaje con msgbuf
    msgbuf message;
    message.msg_type = 1;
    strcpy(message.text, etiqueta);

    // Enviar el mensaje con msgsnd
    msgsnd(this->id, (void*)&message, MAX_LENGTH, 0);

}

// Método encargado de recibir un mensaje.
void Buzon::recibir(char* mensaje) {
    // Inicializar el contenido del mensaje con msgbuf
    msgbuf message;

    // Recibir el mensaje con msgrcv
    msgrcv(this->id, (void *)&message, MAX_LENGTH, 0, 0);

    // Sacar el mensaje del buzón. Sugerencia: strcpy
    strcpy(mensaje, message.text);
}
