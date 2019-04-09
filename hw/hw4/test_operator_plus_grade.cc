#include <cmath>
#include <iostream>


#include "gradebook.h"


const size_t kBooks = 3;
const size_t kSize = 3;
const double kGrades[kBooks][kSize] = {
  { 80.0, 90.0, 100.0 },
  { 70.0, 80.0, 90.0 },
  { 75.0, 90.0, 105.0 }
};
const double kGPAs[kBooks] = { 90.0, 80.0, 90.0 };


bool Test_operatorPlusGrade();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout
      << "Testing operator+(double) and operator+(double, GradeBook)"
      << std::endl;
  if (Test_operatorPlusGrade())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool Test_operatorPlusGrade() {
  bool passed = true;

  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook actual;
    for (size_t j = 0; j < kSize; ++j)
      // testing operator+(double)
      actual = actual + kGrades[i][j];

    for (size_t j = 0; j < kSize; ++j)
      if (kGrades[i][j] != actual.Get(j)) {
        std::cout << "  Expected Grade at " << j << ": " << kGrades[i][j]
            << ", Actual: " << actual.Get(j) << std::endl;
        passed = false;
      }
  }

  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook actual;
    for (size_t j = 0; j < kSize; ++j)
      // testing operator+(double, GradeBook)
      actual = kGrades[i][j] + actual;

    for (size_t j = 0; j < kSize; ++j)
      if (kGrades[i][j] != actual.Get(j)) {
        std::cout << "  Expected Grade at " << j << ": " << kGrades[i][j]
            << ", Actual: " << actual.Get(j) << std::endl;
        passed = false;
      }
  }
  
  return passed;
}
