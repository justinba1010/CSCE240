/*  Copyright 2019 Justin Baum
 *  CSCE240 at University of South Carolina; Spring 2019
 *  Dr. Jeremy Lewis
 *  hw2
 */

#include "parse_scores.h"  //NOLINT
#include <iostream>
const int kBUFFER = 512;

using std::cout;
using std::endl;

int get_num_grades(int id, const std::string values[], int size) {
  int num_of_students = stoi(values[0]);
  int num_grades = -1;
  // Keep count of where we are, parsing 1 by 1
  int count = 0;

  for (int student = 0; student < num_of_students; student++) {
    ++count;
    int student_id = stoi(values[count]);
    ++count;
    int student_grades = stoi(values[count]);
    if (student_id == id) {
      num_grades = student_grades;
    }
    count += student_grades;
  }
  if (count != size - 1) {
    return -10;
  }
  return num_grades;
}  // get_num_grades

int get_grades(int id, const std::string values[], int size, double grades[]) {
  int num_of_students = stoi(values[0]);
  int num_grades = -1;
  // Keep count of where we are, parsing 1 by 1
  int count = 0;

  for (int student = 0; student < num_of_students; student++) {
    ++count;
    int student_id = stoi(values[count]);
    ++count;
    int student_grades = stoi(values[count]);
    if (student_id == id) {
      num_grades = student_grades;
      for (int i = 0; i < num_grades; ++i) {
        ++count;
        grades[i] = stod(values[count]);
      }
    } else {
      count += student_grades;
    }
  }
  if (count != size - 1) {
    return -10;
  }
  return num_grades;
}  // get_grades

double get_grade(int id,
                  int grade_index, const std::string values[], int size) {
  double grades[kBUFFER];
  int num_grades = get_grades(id, values, size, grades);
  if (num_grades < 0) return num_grades;
  // Return error if the grade doesn't exist
  if (grade_index >= num_grades) return -2;
  return grades[grade_index];
}

int get_max_grade_id(const std::string values[], int size) {
  int ids[kBUFFER];
  int num_students = get_student_ids(values, size, ids);
  // forward errors
  if (num_students < 0) return num_students;
  // no students
  if (num_students == 0) return -1;
  double maxgrade = -100;
  int maxid = 0x80000000;  // 32 bit minimum
  for (int student = 0; student < num_students; student++) {
    double grades[kBUFFER];
    int numgrades = get_grades(ids[student], values, size, grades);
    if (numgrades < 0) return numgrades;
    // no grades
    if (numgrades == 0) return -2;
    for (int grade = 0; grade < numgrades; grade++) {
      if (grades[grade] > maxgrade) {
        maxid = ids[student];
        maxgrade = grades[grade];
      }
    }
  }  // for
  return maxid;
}  // get_max_grade_id

double get_max_grade(const std::string values[], int size) {
  int ids[kBUFFER];
  int num_students = get_student_ids(values, size, ids);
  // forward errors
  if (num_students < 0) return num_students;
  // no students
  if (num_students == 0) return -1;
  double maxgrade = -100;
  int maxid = 0x80000000;  // 32 bit minimum
  for (int student = 0; student < num_students; student++) {
    double grades[kBUFFER];
    int numgrades = get_grades(ids[student], values, size, grades);
    if (numgrades < 0) return numgrades;
    // no grades
    if (numgrades == 0) return -2;
    for (int grade = 0; grade < numgrades; grade++) {
      if (grades[grade] > maxgrade) {
        maxid = ids[student];
        maxgrade = grades[grade];
      }
    }
  }  // for
  return maxgrade;
}  // get)max_grade

int get_student_ids(const std::string values[], int size, int ids[]) {
  int num_of_students = stoi(values[0]);
  // Use count to move along array
  int count = 0;
  for (int student = 0; student < num_of_students; student++) {
    // Move along array
    ++count;
    int gid = stoi(values[count]);
    // Add user id to array
    ids[student] = gid;
    // Move along array
    ++count;
    // Get number of grades
    int num_grades = stoi(values[count]);
    // Move past the grades
    count += num_grades;
  }  // for
  if (size != count+1) {
    // Invalid format
    return -10;
  }  // fi
  // User does not exist
  return num_of_students;
}  // get_num_grades

// Helper function

int stoi(std::string value) {
  return std::stoi(value);
}

double stod(std::string value) {
  return std::stod(value, nullptr);
}
