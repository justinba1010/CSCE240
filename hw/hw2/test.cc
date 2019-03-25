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


int main(int argc, char* argv[]) {
  // test get_num_grades
  assert(get_num_grades(1234, kValues, kSize) == 3);
  assert(get_num_grades(2345, kValues, kSize) == 4);
  // test get_grades
  double grades[5];
  assert(get_grades(1234, kValues, kSize, grades) == 3);
  assert(grades[0] == 98.7 && grades[2] == 77.32);
  assert(get_grades(2345, kValues, kSize, grades) == 4);
  assert(grades[0] == 93.1 && grades[3] == 89.33);
  
  //test get_grade
  assert(get_grade(1234, 0, kValues, kSize) == 98.7);
  assert(get_grade(1234, 2, kValues, kSize) == 77.32);
  assert(get_grade(2345, 0, kValues, kSize) == 93.1);
  assert(get_grade(2345, 3, kValues, kSize) == 89.33);

  // test get_max_ values
  assert(get_max_grade_id(kValues, kSize) == 1234);
  assert(get_max_grade(kValues, kSize) == 98.7);

  // test get_student_ids
  int ids[5];
  assert(get_student_ids(kValues, kSize, ids) == 2);
  assert(ids[0] == 1234);
  assert(ids[1] == 2345);
  return 0;
}
