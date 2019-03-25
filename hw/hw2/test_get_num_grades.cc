#include "parse_scores.h"

#include <cassert>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string kValues[] = {
  "2",
  "1234", "3", "98.7", "87.92", "77.32", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
int kSize = 12;

bool TestGetNumGrades();
bool TestGetNumGradesNoMatch();
bool TestGetNumGradesCorrupt();

int main(int argc, char* argv[]) {
  int passed = 0;
  // test get_num_grades
  cout << "Testing get_num_grades" << endl;
  if (TestGetNumGrades()) {
    cout << "  PASSED" << endl;
  } else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_num_grades with no match" << endl;
  if (TestGetNumGradesNoMatch()) {
    cout << "  PASSED" << endl;
  } else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_num_grades with corrupt format" << endl;
  if (TestGetNumGradesCorrupt()) {
    cout << "  PASSED" << endl;
    return 0;
  } else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}

bool TestGetNumGrades() {
  bool passed = true;
  int expected, actual;

  expected = 3;
  actual = get_num_grades(1234, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  expected = 4;
  actual = get_num_grades(2345, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}


bool TestGetNumGradesNoMatch() {
  bool passed = true;
  int expected, actual;

  expected = -1;
  actual = get_num_grades(3456, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}


bool TestGetNumGradesCorrupt() {
  bool passed = true;
  int expected, actual;

  expected = -10;
  actual = get_num_grades(2345, kValues, kSize - 1);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}
