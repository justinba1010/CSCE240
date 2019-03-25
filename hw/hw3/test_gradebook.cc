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
const double kMaxes[kBooks] = { 100.0, 90.0, 105.0 };


bool TestAddAndGetGrade();
bool TestAddGradeBook();
bool TestGetGPA();
bool TestGetMax();
bool TestEquals();
bool TestLessThan();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::Add(double) and GradeBook::Get(size_t)"
      << std::endl;
  if (TestAddAndGetGrade())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }
  
  std::cout << "Testing GradeBook::AddGradeBook(const GradeBook&)" << std::endl;
  if (TestAddGradeBook())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  std::cout << "Testing GradeBook::GetGPA()" << std::endl;
  if (TestGetGPA())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  std::cout << "Testing GradeBook::GetMax()" << std::endl;
  if (TestGetMax())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  std::cout << "Testing GradeBook::Equals(const GradeBook&)" << std::endl;
  if (TestEquals())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }


  std::cout << "Testing GradeBook::LessThan(const GradeBook&)" << std::endl;
  if (TestLessThan())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestAddAndGetGrade() {
  bool passed = true;

  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook actual;
    for (size_t j = 0; j < kSize; ++j)
      actual.Add(kGrades[i][j]);

    for (size_t j = 0; j < kSize; ++j) {
      if (kGrades[i][j] != actual.Get(j)) {
        std::cout << "  Expected Grade at " << j << ": " << kGrades[i][j]
            << ", Actual: " << actual.Get(j) << std::endl;
        passed = false;
      }
    }
  }
  
  return passed;
}


bool TestAddGradeBook() {
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

    actual = actual.Add(tmp);
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


bool TestGetGPA() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  for (size_t i = 0; i < kBooks; ++i)
    if (kGPAs[i] != actuals[i].GetGPA()) {
      std::cout << "  Expected GPA at " << i << ": " << kGPAs[i]
          << ", Actual: " << actuals[i].GetGPA() << std::endl;
      passed = false;
    }
  GradeBook empty;
  passed &= std::isnan(empty.GetGPA());

  return passed;
}


bool TestGetMax() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  for (size_t i = 0; i < kBooks; ++i)
    if (kMaxes[i] != actuals[i].GetMax()) {
      std::cout << "  Expected GPA at " << i << ": " << kMaxes[i]
          << ", Actual: " << actuals[i].GetMax() << std::endl;
      passed = false;
    }

  return passed;
}


bool TestEquals() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  if (!actuals[0].Equals(actuals[2])) {
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

  if (actuals[0].Equals(actuals[1])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[0][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[1].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": False, Actual: True" << std::endl;

    passed = false;
  }
  // Here's our extra checks.
  GradeBook empty, empty2;
  passed &= empty.Equals(empty2);
  passed &= !(empty.Equals(actuals[0]));
  passed &= !(actuals[0].Equals(empty));
  return passed;
}


bool TestLessThan() {
  bool passed = true;

  GradeBook books[3];
  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      books[i].Add(kGrades[i][j]);

  if (!books[1].LessThan(books[0])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << books[1].Get(k) << " ";
    std::cout << "< ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << books[0].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;
    passed = false;
  }

  if (!books[0].LessThan(books[2])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << books[0].Get(k) << " ";
    std::cout << "< ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << books[2].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": False, Actual: True" << std::endl;

    passed = false;
  }

  // Heres some more checks
  GradeBook empty, empty2;
  passed &= !(empty.LessThan(empty2));
  
passed &= (empty.LessThan(books[0]));
  passed &= !(books[0].LessThan(empty));

  return passed;
}
