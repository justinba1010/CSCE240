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

bool TestGetMaxGradeId();
bool TestGetMaxGradeIdNoStudents();
bool TestGetMaxGradeIdNoGrades();
bool TestGetMaxGradeIdCorruptFormat();


int main(int argc, char* argv[]) {
  int passed = 0;

  // test get_grades
  cout << "Testing get_max_grade_id" << endl;
  if (TestGetMaxGradeId())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade_id with no students" << endl;
  if (TestGetMaxGradeIdNoStudents())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade_id with no grades" << endl;
  if (TestGetMaxGradeIdNoGrades())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade_id with corrupt format" << endl;
  if (TestGetMaxGradeIdCorruptFormat())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}


bool TestGetMaxGradeId() {
  int expected_id = 1234;
  int actual_id = get_max_grade_id(kValues, kSize);
  if (expected_id != actual_id) {
    cout << "\tExpected id: " << expected_id << ", Actual id: "
        << actual_id << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeIdNoStudents() {
  int expected_id = -1;
  std::string values[] = { "0" };
  int actual_id = get_max_grade_id(values, 1);
  if (expected_id != actual_id) {
    cout << "\tExpected id: " << expected_id << ", Actual id: "
        << actual_id << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeIdNoGrades() {
  int expected_id = -2;
  std::string values[] = { "2", "1234", "0", "2345", "0" };
  int actual_id = get_max_grade_id(values, 5);
  if (expected_id != actual_id) {
    cout << "\tExpected id: " << expected_id << ", Actual id: "
        << actual_id << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeIdCorruptFormat() {
  int expected_id = -10;
  int actual_id = get_max_grade_id(kValues, kSize-1);
  if (expected_id != actual_id) {
    cout << "\tExpected id: " << expected_id << ", Actual id: "
        << actual_id << endl;
    return false;
  }

  return true;
}
