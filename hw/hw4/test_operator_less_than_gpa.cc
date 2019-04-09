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


bool Test_operatorLessThanGPA();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout
      << "Testing GradeBook::operator<(double) and operator(double, GradeBook)"
      << std::endl;
  if (Test_operatorLessThanGPA())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool Test_operatorLessThanGPA() {
  bool passed = true;

  GradeBook books[3];
  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      books[i].Add(kGrades[i][j]);

  for (size_t i = 0; i < kBooks; ++i)
    if (!(books[i] < kGPAs[i] + 1.0)) {
      std::cout << "  Expected ";
      for (size_t k = 0; k < kSize; ++k)
        std::cout << books[1].Get(k) << " ";
      std::cout << "< " << kGPAs[i];

      std::cout << ": True, Actual: False" << std::endl;

      passed = false;
    }

  for (size_t i = 0; i < kBooks; ++i)
    if (!(kGPAs[i] - 1.0 < books[i])) {
      std::cout << "  Expected ";
      std::cout << kGPAs[i] << " < ";
      for (size_t k = 0; k < kSize; ++k)
        std::cout << books[1].Get(k) << " ";

      std::cout << ": True, Actual: False" << std::endl;

      passed = false;
    }

  return passed;
}
