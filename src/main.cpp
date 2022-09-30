#include <iostream>
#include "Buzon.hpp"
#include "Reader.hpp"

using namespace std;

int main() {
  char message[MAX_LENGTH];
  char result[MAX_LENGTH];
  
  memset(message,0, MAX_LENGTH);
  memset(result,0, MAX_LENGTH);
  message[0] = 'H';
  message[1] = 'o';
  message[2] = 'l';
  message[3] = 'a';
  message[4] = '\0';
  Buzon buzon;
  buzon.enviar(&message[0]);
  buzon.recibir(&result[0]);
  cout << "RECIBIDO: ";
  for (auto x : result) {
    cout << x;
  }
  cout << endl;
  buzon.destructor();
  //Reader::check_errors("file.txt");

  return 0;
}