/*  Copyright 2019 Justin Baum
**  Dr. Lewis
**  7 February 2019
*/
#include<iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  const long size = 0x000000000F000000;
  int *grades = reinterpret_cast<int*>(malloc(size*sizeof(int)));
  for(int i = 0; i < 0x000000000F000000; i++) {
    grades[i] = i;
    cout << grades << &(grades[-i]) << "\t" << grades[i] << endl;
  }
  cout << "Done" << endl;
  return 0;
}
