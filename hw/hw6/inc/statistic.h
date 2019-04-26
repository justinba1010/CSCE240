/* Copyright 2019
** Justin Baum
** 17 April 2019
** Dr. Lewis  CSCE240   HW6
** statistic.h
*/

#ifndef _statistic_h  // NOLINT
#define _statistic_h  // NOLINT

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

namespace csce240 {
class Statistic : public vector<double>{
 public:
  /* Not a pure virtual so that children may not override if unused
  */

  virtual ~Statistic() { /* Use the vector::vector destructor */ }

  /* Defined by children
  */
  virtual void Collect(double) = 0;

  /* Defined by children
  */
  virtual double Calculate() const = 0;
};
}  // namespace csce240
#endif  // _statistic_h   // NOLINT
