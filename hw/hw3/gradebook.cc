/*  Copyright 2019
**  Justin Baum
**  7 March 2019
*/

#ifndef _GRADEBOOK_CC
#define _GRADEBOOK_CC

#include "./gradebook.h" // NOLINT

// NAN is defined in CMATH
// INFINITY is defined in CMATH

void GradeBook::Add(double grade) {
  this->gradebook_.push_back(grade);
}

double GradeBook::Get(size_t index) const {
  // Check if our gradebook is the right size first
  if (this->gradebook_.size() > index) {
    return this->gradebook_.at(index);
  }
  return NAN;
}

const GradeBook GradeBook::Add(const GradeBook& that) const {
  GradeBook newGradeBook;
  for (unsigned int i = 0; i < this->GetSize(); ++i) {
    newGradeBook.Add(this->Get(i));
  }
  for (unsigned int i = 0; i < that.GetSize(); ++i) {
    newGradeBook.Add(that.Get(i));
  }
  return newGradeBook;
}

double GradeBook::GetGPA() const {
  double sum = 0.0;
  for (unsigned int i = 0; i < this->GetSize(); ++i) {
    sum += this->Get(i);
  }
  if (this->GetSize() == 0) {
    return NAN;
  }
  return sum / this->GetSize();
}

double GradeBook::GetMax() const {
  double max = - std::numeric_limits<double>::infinity();
  for (unsigned int i = 0; i < this->GetSize(); ++i) {
    max = max < this->Get(i) ? this->Get(i) : max;
  }
  return (this->GetSize() == 0 ? NAN : max);
}

const size_t GradeBook::GetSize() const {
  return gradebook_.size();
}

bool GradeBook::Equals(const GradeBook& that) const {
  double thisGPA = this->GetGPA();
  double thatGPA = that.GetGPA();
  if (std::isnan(thisGPA) && std::isnan(thatGPA)) {
    return true;
  }
  // We don't need to worry about NAN here, because NAN <= x is always false
  if (std::isnan(thisGPA) || std::isnan(thatGPA)) {
    return false;
  }
  return (abs(thisGPA - thatGPA) <= 0.00001);
}

bool GradeBook::LessThan(const GradeBook& that) const {
  bool equality =  this->Equals(that);
  // This lets us know that at least one of the gradebooks are nonzero as well
  // We'll also check to make sure that we check the equality issue
  if (equality) {
    double maxThis = this->GetMax();
    double maxThat = that.GetMax();
    return maxThis < maxThat;
  }
  double thisGPA = this->GetGPA();
  double thatGPA = that.GetGPA();
  thisGPA = std::isnan(thisGPA) ? - INFINITY : thisGPA;
  thatGPA = std::isnan(thatGPA) ? - INFINITY : thatGPA;
  // We know that one of these are not -INFINITY
  return thisGPA < thatGPA;
}

#endif
