/* Copyright 2019
** Justin Baum
** 17 April 2019
** Dr. Lewis  CSCE240   HW6
** mean.cc
*/

#include <mean.h>
#include <statistic.h>
#include <vector>
#include <cmath>
using std::vector;

namespace csce240 {
  double Mean::Mean::Calculate() const {
    // Basic average calculator
    double sum = 0.0;
    int counter = 0;
    for (auto it = this->begin(); it != this->end(); ++it) {
      ++counter;
      sum += *it;
    }
    if (counter == 0) {
      return NAN;
    }
    return sum/counter;
  }
  void Mean::Mean::Collect(double x) {
    this->push_back(x);
  }
}  // namespace csce240
