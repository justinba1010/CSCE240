/* Copyright 2019
** Justin Baum
*/

#ifndef _matrix_h  //NOLINT
#define _matrix_h

#include <cassert>
#include <iostream>
// using assert

class MatrixTester;

class Matrix {
 public:
  friend class MatrixTester;

  Matrix();  // for testing, useless in practice
  Matrix(unsigned int rows, unsigned int cols);

  /* Copy Constructor: 2 Points
   *   Performs deep copy.
   */
  Matrix(const Matrix& that);

  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  ~Matrix();

  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Does what you would expect.
   */
  double Get(unsigned int row, unsigned int col) const;

  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  const Matrix& operator=(const Matrix& rhs);

  /* Times Equals Op: 2 Points
   *   Returns calling object with matrix scaled by rhs.
   */
  const Matrix& operator*=(double rhs);

  /* Add Op: 2 points
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
  const Matrix operator+(const Matrix& rhs) const;

 private:
  double **m_;
  unsigned int rows_;
  unsigned int cols_;

  inline void initialize() {
    assert(rows_ > 0);  // assert preconditions are true
    assert(cols_ > 0);  // assert preconditions are true
    m_ = new double *[rows_];  // create array of double pointers
    for (unsigned int i = 0; i < rows_; ++i)
      m_[i] = new double[cols_];  // create array of doubles
    }  // initialize

  inline void destruct() {
    if (m_) {
      for (unsigned int i = 0; i < rows_; ++i) {
        delete [] m_[i];
      }
      delete [] m_;
      rows_ = 0;
      cols_ = 0;
      // We need to not only free the memory, but we need to say we don't have
      // that address anymore. This prevents us from trying to redelete it.
      m_ = nullptr;
    }  // if m
  }  // destruct()

  inline void mcopy(const Matrix& rhs) {
    for (unsigned int i = 0; i < rows_; ++i) {
      for (unsigned int j = 0; j < cols_; ++j) {
        this->m_[i][j] = rhs.m_[i][j];
      }  // for j
    }  // for i
  }  // copy()
};

#endif  //_matrix_h // NOLINT
