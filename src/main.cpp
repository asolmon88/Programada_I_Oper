#include <sys/types.h>
#include <filesystem>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Buzon.hpp"
#include "Reader.hpp"

using namespace std;

#define NAME_FILE_SIZE 5

int main() {
	// Obtiene y divide nombres de archivos
	Buzon buzon;
	int files_count;

  char file_name[MAX_LENGTH];
	char result[MAX_LENGTH_RESULT];
	
	memset(file_name,0, MAX_LENGTH);
	memset(result,0, MAX_LENGTH_RESULT);

	/* SEND LIST OF FILES TO BUZON */
	std::string path = "./files/";
	// Generates a string based on name of file
	for (const auto & entry : filesystem::directory_iterator(path)) {
		files_count++;
		string file_string = filesystem::path(entry.path()).stem().string();
		// Converts string to char
		for (int iterator = 0; iterator < NAME_FILE_SIZE; iterator++) {
			file_name[iterator] = file_string[iterator];
    }
		buzon.enviar(&file_name[0]);
	}
	cout << "A total of '" << files_count <<  "' files have been detected..." << endl;

	/* CREATE CHILD PROCCESSES AND DISTRIBUTE WORK */
	for(int i=0; i < files_count; i++) {
		// Work
		if(fork() == 0) {
			buzon.recibir(&result[0]); // recibe nombre de file
			string file_name_string = result;
			cout << "Nombre del file: " << file_name_string << endl;
			// Reader::check_errors(result); // procesa file
			cout << "A file has been processed..." << endl;; // sale
			exit(0);
		}
  }
	buzon.destructor();
  return 0;
}