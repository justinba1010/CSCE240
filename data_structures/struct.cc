/*  Copyright 2019
**  Justin Baum
**  struct.cc
**  Playing with references and structs
**/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace Space {
  struct Point {
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {/**/};
    int x;
    int y;
  };
  const Point add(Point* p0, Point* p1) {
    p0->x += 1;
    return Point(p0->x + p1->x, p0->y + p1->y);
  };
};

int main(int argv, char* argc[]) {
  Space::Point a(5,5);
  Space::Point b(10,5);
  Space::Point c;
  c = add(&a, &b);
  cout << c.x << endl;
  cout << c.y << endl;
};


