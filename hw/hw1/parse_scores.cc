/*  Copyright 2019 Justin Baum
 *  CSCE240 at University of South Carolina; Spring 2019
 *  Dr. Jeremy Lewis
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  /* The following input
  *
  *   2 1234 3 98.7 87.92 77.32 2345 3 93.1 90.23 81.21
  *
  * would result in the following output.
  */

  // Get the number of students
  int num_students;
  cin >> num_students;

  // Start JSON Output
  cout << "{" << endl << "  \"students\" : [" << endl;

  int max_id;
  double max_score =  -10000;

  // We don't really need this information
  for (; num_students > 0; --num_students) {
    // Get the student id
    int id;
    cin >> id;

    //  Get number of grades
    int num_grades;
    cin >> num_grades;
    // Just in case we hit a stack overflow in Ubuntu
    // I don't know how the test cases are going to look,
    // so prepare for the worst.
    /* double *grades = reinterpret_cast<double*>(malloc(num_grades*sizeof(double)));
    //  We don't need this after thinking about it */

    // JSON Output
    cout << "    { \"id\" : " << id << ", \"grades\" : [ ";

    // i = student index
    for (int i = 0; i < num_grades; ++i) {
      double grade;
      cin >> grade;
      // JSON Output
      cout << grade << (i == num_grades - 1 ? " " : ", ");
      if (max_score < grade) {
        max_id = id;
        max_score = grade;
      }
    }  // for i
    // JSON Output
    cout << "] }" << (num_students == 1 ? "" : ",") << endl;
  }  // for num_students
  // JSON Output
  cout << "  ]," << endl;
  cout << "  \"max_id\" : " << max_id << "," << endl;
  cout << "  \"max_score\" : " << max_score << endl;
  cout << "}";

  /* Given code
  cout << "{" << endl;
  cout << "  \"students\" : [" << endl;
  cout << "    { \"id\" : 1234, \"grades\" : [ 98.7, 87.92, 77.32 ] }," << endl;
  cout << "    { \"id\" : 2345, \"grades\" : [ 93.1, 90.23, 81.21 ] }" << endl;
  cout << "  ]," << endl;
  cout << "  \"max_id\" : 1234," << endl;
  cout << "  \"max_score\" : 98.7" << endl;
  cout << "}";
  */
}
