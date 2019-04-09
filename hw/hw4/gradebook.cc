/*  Copyright 2019 Justin Baum
**  Dr. Lewis
**  gradebook.h
**  CSCE240
**  25 March 2019
*/

// I am using a no lint because the cpplint
// is in a higher directory, see makefile.

#include "./gradebook.h" // NOLINT

namespace {
  // Anonymous Namespace(so it doesn't get exported)
  inline bool compareAbs(double x, double y) {
    return abs(x - y) < 0.00001;
  }

  inline bool compare(double x, double y) {
    return x - y < 0.00001;
  }
}

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}

double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

double GradeBook::Average() const {
  double sum = 0.0;
  int i;
  for (i = 0; !isnan(this->Get(i)); ++i) {
    sum += this->Get(i);
  }
  return (i == 0) ? - INFINITY : sum/i;
  // Implicit conversion to Double
  // See https://en.cppreference.com/w/cpp/language/operator_precedence
}

const GradeBook GradeBook::operator+(double rhs) const {
  GradeBook newgradebook;
  for (int i = 0; !isnan(this->Get(i)); ++i) {
    newgradebook.Add(this->Get(i));
  }
  newgradebook.Add(rhs);
  return newgradebook;
}

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook newgradebook;
  for (int i = 0; !isnan(this->Get(i)); ++i) {
    newgradebook.Add(this->Get(i));
  }
  for (int i = 0; !isnan(rhs.Get(i)); ++i) {
    newgradebook.Add(rhs.Get(i));
  }
  return newgradebook;
}

bool GradeBook::operator==(const GradeBook& rhs) const {
  return compareAbs(this->Average(), rhs.Average());
}

bool GradeBook::operator==(double rhs) const {
  // NaN or -INF for rhs will give us a false
  // IF Average is -INF we will get a false
  return compareAbs(rhs, this->Average());
}

bool GradeBook::operator<(const GradeBook& rhs) const {
  return compare(this->Average(), rhs.Average());
}

bool GradeBook::operator<(double rhs) const {
  if (*this == rhs) {
    return false;
  }
  return compare(this->Average(), rhs);
}

const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook newgradebook;
  for (int i = 0; !isnan(rhs.Get(i)); ++i) {
    newgradebook.Add(rhs.Get(i));
  }
  newgradebook.Add(lhs);
  return newgradebook;
}

bool operator==(double lhs, const GradeBook& rhs) {
  return compareAbs(lhs, rhs.Average());
}

bool operator<(double lhs, const GradeBook& rhs) {
  return compare(lhs, rhs.Average());
}
