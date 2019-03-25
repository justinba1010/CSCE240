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


bool TestGetGrade();
bool TestGetGradeNoMatch();  // true when returns -1 for no matching id
bool TestGetGradeNoIndex();  // true when returns -2 for missing index
bool TestGetGradeFormatCorrupt();  // true when returns -10 for corrupt format


int main(int argc, char* argv[]) {
  int passed = 0;
  // test get_num_grades
  cout << "Testing get_grade" << endl;
  if (TestGetGrade())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_grade with no matching student id" << endl;
  if (TestGetGradeNoMatch())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_grade with no matching grade index" << endl;
  if (TestGetGradeNoIndex())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_grade with format corrupt" << endl;
  if (TestGetGradeFormatCorrupt())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}


bool TestGetGrade() {  // true when correct grade selected for given id
  int ids[] = { 1234, 2345, 1234, 2345 };
  int grade_index[] = { 0, 1, 2, 2 };
  double expected_grades[] = { 98.7, 90.23, 77.32, 81.21 };
  bool passed = true;

  for (unsigned int i = 0; i < sizeof(ids)/sizeof(int); ++i) {
    double actual_grade = get_grade(ids[i], grade_index[i], kValues, kSize);

    if (expected_grades[i] != actual_grade) {
      cout << "\tExpected Grade at " << i << ": " << expected_grades[i]
          << "Actual Grade : " << actual_grade << endl;
      passed = false;
    }
  }
  return passed;
}


bool TestGetGradeNoMatch() {  // true when returns -1 for no matching id
  double expected = -1;
  double actual = get_grade(234, 2, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetGradeNoIndex() {
  double expected = -2;
  double actual = get_grade(1234, 3, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetGradeFormatCorrupt() {
  double expected = -10;
  double actual = get_grade(1234, 2, kValues, kSize-5);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
