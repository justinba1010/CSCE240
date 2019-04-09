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


bool Test_operatorPlusGradeBook();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::operator+(const GradeBook&)" << std::endl;
  if (Test_operatorPlusGradeBook())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }
  

  return passed;
}


bool Test_operatorPlusGradeBook() {
  bool passed = true;

  double expected[kBooks*kSize];
  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      expected[i*kBooks + j] = kGrades[i][j];

  GradeBook actual;
  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook tmp;
    for (size_t j = 0; j < kSize; ++j)
      tmp.Add(kGrades[i][j]);

    // using new operator+(GradeBook)
    actual = actual + tmp;
  }

  for (size_t i = 0; i < kBooks*kSize; ++i) {
    if (actual.Get(i) != expected[i]) {
      std::cout << "  Expected Grade at " << i << ": " << expected[i]
          << ", Actual: " << actual.Get(i) << std::endl;
      passed = false;
    }
  }

  return passed;
}
