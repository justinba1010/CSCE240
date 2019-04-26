/* Copyright 2019
** Justin Baum
** 17 April 2019
** Dr. Lewis  CSCE240   HW6
** mean.cc
*/

#include <median.h>
#include <statistic.h>
#include <vector>
#include <algorithm>
#include <iostream>

using std::sort;
using std::vector;

namespace csce240 {
  double Median::Median::Calculate() const {
    // I had trouble with: sort(this->begin(), this->end())
    // I don't really know why the above happened, but I worked around below
    vector<double> newvec;
    for (auto it = this->begin(); it != this->end(); ++it)
      newvec.push_back(*it);
    // Sort for the median
    sort(newvec.begin(), newvec.end());
    int i = newvec.size();
    if (i == 0) return 0.0;
    double r = newvec[i/2];
    // case
    if (i % 2 == 0)
      r = (newvec[i/2] + newvec[(i-1)/2])/2;
    return r;
  }
  void Median::Median::Collect(double x) {
    this->push_back(x);
  }
}  // namespace csce240
