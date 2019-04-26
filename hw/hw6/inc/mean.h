/* Copyright 2019
** Justin Baum
** 17 April 2019
** Dr. Lewis  CSCE240   HW6
** mean.cc
*/

#include <statistic.h>
#include <iostream>

#ifndef _mean_h  //NOLINT
#define _mean_h  //NOLINT

using std::cout;
using std::endl;
namespace csce240 {
class Mean : public virtual Statistic {
 public:
  /* Stores data (datum) such than an average may be calculated.
  * - NOTE: You do not necessarily need to store each datum.
  */

  void Collect(double datum);

  /* Returns the mean of the data (datum) from the Collect method.
  */
  double Calculate() const;
};
}  // namespace csce240
#endif  // _mean_h // NOLINT
