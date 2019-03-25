#include <string>


/* Description:
 *   Parses the values array to determine how many grades are present for a
 *   student selected by the id parameter and returns that value.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The number of grades for student with parameter id when student id is
 *     found.
 * - Integer -1 when a match for parameter id is not found in student ids
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_num_grades(int id, const std::string values[], int size);

/* Description:
 *   Parses the values array to get all grades for a student matching parameter
 *   id
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter grades is large enough to hold all grades for requested student
 * Postconditions:
 * - Parameter grades has the floating point representation of the corresponding
 *     grades for student matching parameter id
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - grades: an input parameter into which the floating point representation of
 *     student's grades are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 * - Integer -1 if id not found
 */
int get_grades(int id, const std::string values[], int size, double grades[]);

/* Description:
 *   Extracts a single grade for a given student and given grade index.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - grade_index: index of the grade to be returned for matching student
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - Grade selected
 * - Integer -1 when student is not found
 * - Integer -2 when grade_index is not found
 * - Integer -10 when values format is corrupt
 */
double get_grade(int id,
                   int grade_index, const std::string values[], int size);

/* Description:
 *   Extracts the id of the student with the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The id of the student with the highest grade.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_max_grade_id(const std::string values[], int size);

/* Description:
 *   Extracts the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * - Grades are nonnegative. Adjust accordingly.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The highest grade found.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
double get_max_grade(const std::string values[], int size);

/* Description:
 *   Parses the values array to extract all student ids. Stores the values in
 *   the parameter ids
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter ids is large enough to hold all student id values
 * Postconditions:
 * - Parameter ids has the integer values of the corresponding student ids.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - ids: an input parameter into which student ids are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 */
int get_student_ids(const std::string values[], int size, int ids[]);
