/* Copyright 2019
** Justin Baum
** 17 April 2019
** Dr. Lewis  CSCE240   HW6
** median.h
*/

#ifndef _median_h  // NOLINT
#define _median_h  // NOLINT

#include <statistic.h>
namespace csce240 {
class Median : public virtual Statistic {
 public:
  /* Stores data (datum) such than the median may be determined.
  */

  void Collect(double datum);

  /* Calculates the median of the data (datum) from the Collect method.
  */
  double Calculate() const;
};
}  // namespace csce240
#endif  // NOLINT
