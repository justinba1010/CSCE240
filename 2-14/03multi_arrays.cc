/*  Copyright 2019 Justin Baum
 *  
 */

#include <cstdlib>

#include <ctime>

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  const int kSeed = 123;
  srand(kSeed);

  // create two const ints for kRows and kColumns of matrix
  const int kRows = 5;
  const int kColumns = 4;

  // create int matrix and assign each element
  // create a row
  int row[kColumns][kRows];
  cout << "row[0][0]: " << row[0][0] << endl;
  cout << "&row[0]: " << &row[0][0] << endl;
  cout << "row[1][1]: " << row[1][1] << endl;

  cout << "row[0]: " << row[0] << endl;
  cout << "*row[0]: " << *row[0] << endl;
  cout << "&row[0]: " << &row[0] << endl;
  // manage memory ourselves
  return 0;
}
