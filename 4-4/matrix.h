/* Copyright 2019
** Justin Baum
** 4 April 2019
** matrix.h
*/

#ifndef _matrix_h
#define _matrix_h
#include <assert.h>

class Matrix {
 public:
  Matrix(unsigned int rows, unsigned int cols);
  Matrix(const Matrix& that);
  ~Matrix();

  double Get(unsigned int row, unsigned int col) const;

  Matrix& operator=(const Matrix& rhs);

  Matrix& operator*=(double rhs);

  Matrix operator+(const Matrix& rhs) const;
 private:
  double **m_;
  unsigned int rows_;
  unsigned int cols_;
};

#endif //_matrix_h
