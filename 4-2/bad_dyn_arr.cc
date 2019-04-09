/* Copyright 2019
*/

#include<iostream>
using std::cout;
using std::endl;

int main() {
  int *aa;
  int *bb;
  aa = (int*)malloc(4);
  bb = (int*)malloc(4);
  *aa = 5;
  *bb = 6;
  aa = bb;
  cout << *aa << endl;
  cout << *bb << endl;
  return 0;
}