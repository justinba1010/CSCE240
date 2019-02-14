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
  const int kRows = 3;
  const int kColumns = 2;

  // create int matrix and assign each element
  // create a row
  int matrix[kRows][kColumns];
  for (int row = 0; row < kRows; ++row) {
    for (int col = 0; col < kColumns; ++col) {
      matrix[row][col] = row*kColumns + col;
    }
  }
  for (int row = 0; row < kRows; ++row) {
    cout << "\trow[" << row << "]\t\t: " << matrix[row] << endl;
    cout << "*\trow[" << row << "]\t\t: " << *matrix[row] << endl;
    cout << "&\trow[" << row << "]\t\t: " << &matrix[row] << endl;
  }  // for

  for (int row = 0; row < kRows; ++row) {
    for (int col = 0; col < kColumns; ++col) {
      cout << "\trow[" << row <<"][" << col << "]\t: " << matrix[row][col] << endl;
      cout << "&\trow[" << row <<"][" << col << "]\t: " << &(matrix[row][col]) << endl;
    }
  }
  // manage memory ourselves
  return 0;
}
