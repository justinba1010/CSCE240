/* Copyright 2019
** Dr. Jeremy Lewis
*/ 

#ifndef _GRADEBOOK_H_  // NOLINT The reason is because it keeps
                      // telling me that I should be naming it something weird.
#define _GRADEBOOK_H_
// C HEADERS
#include <stddef.h>
// C++ HEADERS
#include <vector>
#include <cmath>
#include <limits>

class GradeBook {
 private:
  std::vector<double> gradebook_;

 public:
  /* Adds a new grade to the gradebook instance, increasing size by 1.
   */
  void Add(double grade);


  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of NAN (from cmath) is returned.
   */
  double Get(size_t index) const;


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook Add(const GradeBook& that) const;


  /* Returns the average of all grades stored in GradeBook instance, or NAN(from
   * cmath) if the the GradeBook instance is empty.
   */
  double GetGPA() const;


  /* Returns the max grade in the GradeBook or NAN if the calling instance is
   * empty.
   */
  double GetMax() const;


  /* Returns the number of grades currently stored by the GradeBook.
   */
  const size_t GetSize() const;


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades are within 0.00001 of each other.
   */
  bool Equals(const GradeBook& that) const;


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool LessThan(const GradeBook& that) const;
};

#endif  // NOLINT (Same reason) _GRADEBOOK_H_
