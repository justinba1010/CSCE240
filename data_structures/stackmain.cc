/*  Justin Baum
    18 January 2019
    CSCE240 Multifiles Practice
*/
#include "stack2.cc"
#include <iostream>

int main(int args, char* argv[]) {
  Stack::Stack<int> aStack = Stack::Stack<int>();
  for (int i = 0; i < 100; ++i) {
    aStack.push(i);
  }
  for (int i = 0; i < 100; ++i) {
    std::cout << aStack.pop() << std::endl;
  }
}
