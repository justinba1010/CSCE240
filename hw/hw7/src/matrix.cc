/* Copyright 2019
** Justin Baum
*/

#ifndef _matrix_cc  // NOLINT
#define _matrix_cc  // NOLINT
#include <matrix.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
      this->initialize();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& that) {
  this->rows_ = that.rows_;
  this->cols_ = that.cols_;
  this->initialize();
  this->mcopy(that);
}

template<typename T>
Matrix<T>::~Matrix() {
  this->destruct();
}

/* Accessor: 1 Point
  *   Precondition(s):
  *   - Parameter row is less than rows in matrix
  *   - Parameter col is less than cols in matrix
  *   Does what you would expect.
  */
template<typename T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
  assert(row >= 0 && row < rows_ && col >= 0 && col < cols_);
  return m_[row][col];
}

/* Assignment Op: 2 Points
  *   Precondition(s):
  *   - lhs rows must equal rhs rows
  *   - lhs cols must equal rhs cols
  *   Performs deep copy.
  */
template<typename T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  this->destruct();
  this->rows_ = rhs.rows_;
  this->cols_ = rhs.cols_;
  this->initialize();
  this->mcopy(rhs);
  return *this;
}

/* Times Equals Op: 2 Points
  *   Returns calling object with matrix scaled by rhs.
  */
template<typename T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
  for (unsigned int i = 0; i < this->rows_; ++i)
    for (unsigned int j = 0; j < this->cols_; ++j)
      m_[i][j] *= rhs;
  return *this;
}

/* Add Op: 2 points
  *   Returns the sum of calling object's matrix and rhs's matrix as a new
  *   object.
  * Precondition(s):
  *   - lhs rows must equal rhs rows
  *   - lhs cols must equal rhs cols
  */
template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
  assert(this->rows_ == rhs.rows_  &&
          this->cols_ == rhs.cols_ &&
          this->rows_ > 0 &&
          this->cols_ > 0);
  Matrix newMatrix(this->rows_, this->cols_);
  for (unsigned int i = 0; i < this->rows_; ++i)
    for (unsigned int j = 0; j < this->cols_; ++j)
      newMatrix.m_[i][j] = this->m_[i][j] + rhs.m_[i][j];
  return newMatrix;
}

#endif  // _matrix_cc //NOLINT