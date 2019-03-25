/*  Justin Baum
    18 January 2019
    CSCE240 Multifiles Practice
*/
#include "stack.cc"
#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;

struct Point {
  int x;
  int y;
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {/**/};
};
const int kNumOfPoints = 100000000;
const int kConst = 7;

int main(int args, char* argv[]) {
  Stack::Stack<struct Point> stack = Stack::Stack<struct Point>();
  for (int i = 0; i < kNumOfPoints; ++i) {
    struct Point point(kConst*i,kConst*i);
    stack.push(point);
  }
  for (int i = 0; i < kNumOfPoints; i++) {
    stack.pop();
    //cout << p.x << endl << p.y << endl << endl;
  }
  cout << "done" << endl;
  return 0;
}
