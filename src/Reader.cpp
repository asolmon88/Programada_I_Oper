#include <fstream>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

#include "Reader.hpp"

using namespace std;

int Reader::check_errors(const char* filename) {
  // stack for keeping track of ( and {
  std::stack<char> check;

  string new_filename = filename;

  new_filename += "_Result.txt";
  new_filename = "./Results/" + new_filename;

  string filename_string = "./files/";
  filename_string += filename;
  filename_string += ".txt";

  // filestream variables
  std::fstream file;
  std::ofstream new_file(new_filename.c_str());

  char byte = 0;
  char byte_before = 0;

  int errors = 0;

  // opening file
  file.open(filename_string.c_str());


  while (file.get(byte)) {
    // check if we are at \n and if the char before is different
    // from () {} and wasn't ; then add it to the result 
    if (byte == '\n' && byte_before != '{' && byte_before != '}' &&
    byte_before != '(' && byte_before != ')' && byte_before != ';'
    && byte_before != '\n') {
      new_file << ';';
      ++errors;
    }

    // if we are waiting to close a ) and didn't, then write on result
    if (!check.empty() && check.top() == '(' ) {
      if (byte == '{') {
        new_file << ')';
        ++errors;
      } else if (byte == ')') {
        check.pop();
      }
    }

    // push to stack
    if (byte == '{' || byte == '(') {
      check.push(byte);
    }

    new_file << byte;
    byte_before = byte;
  }

  // if we have { that are not closed, then close them
  while (!check.empty()) {
    if (check.top() == '{') {
      new_file << "}\n";
      ++errors;
    }
    check.pop();
  }
  new_file.close();
  file.close();

  return errors;
}
