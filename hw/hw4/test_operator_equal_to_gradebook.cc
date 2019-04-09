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


bool Test_operatorEqualTo();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::operator==(const GradeBook&)" << std::endl;
  if (Test_operatorEqualTo())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool Test_operatorEqualTo() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  // testing operator==(GradeBook)
  if (!(actuals[0] == actuals[2])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[0][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[2].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  // testing operator==(GradeBook)
  if (actuals[0] == actuals[1]) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[0][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[1].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  return passed;
}
