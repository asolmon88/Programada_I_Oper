#include <sys/types.h>
#include <filesystem>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "Buzon.hpp"
#include "Reader.hpp"
#include "Semaforo.hpp"

using namespace std;

#define NAME_FILE_SIZE 5

int main(int argc, char *argv[]) {
	Buzon buzon;
	Semaforo sem(1);
	vector<string> files;
	int files_count = 0;
	int total_errors = 0;

  char file_name[MAX_LENGTH];
	char current_error[5];
	
	memset(file_name,0, MAX_LENGTH);
	memset(current_error,0, 5);

	/* CREATES LIST OF FILES TO PROCESS */

	/* CASE: Input through terminal */
	cout << "Argument count: " << argc << endl;
	if (argc > 1) {
		for (int i = 0; i < argc - 1; i++) {
			++files_count;
			string temp_string = argv[i + 1];
			temp_string = temp_string.substr(0, temp_string.length() - 4);
			files.push_back(temp_string);
		}
	}
	/* CASE: Input through directory */
	else {
		std::string path = "./files/";
		// Generates a string based on name of file
		for (const auto & entry : filesystem::directory_iterator(path)) {
			++files_count;
			string file_string = filesystem::path(entry.path()).stem().string();
			// Converts string to char
			for (int iterator = 0; iterator < NAME_FILE_SIZE; iterator++) {
				file_name[iterator] = file_string[iterator];
	    }
			files.push_back(file_name);
		}
	}

	cout << "A total of '" << files_count <<  "' files have been detected..." << endl;

	/* CREATE CHILD PROCCESSES AND DISTRIBUTE WORK */
	for(int i=0; i < files_count; i++) {
		// Work
		if(fork() == 0) {
			string my_file_name = files[i];
			int errors = Reader::check_errors(my_file_name.c_str());
			cout << "For file: " << my_file_name << ", " << errors << " errors were found" << endl;
			string errors_char = to_string(errors);
			sem.wait();
			buzon.enviar((char*)errors_char.c_str());
			sem.signal();
			exit(0);
		}
  }

	/* PRINTS GENERAL RESULT */
	for (int i = 0; i < files_count; ++i) {
		buzon.recibir(&current_error[0]);
		total_errors += atoi(current_error);
		memset(current_error,0, 5);
	}
	cout << "TOTAL ERRORS: " << total_errors << endl;
  return 0;
}