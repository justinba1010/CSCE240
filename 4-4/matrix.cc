/* Copyright 2019
** Justin Baum
** 4 April 2019
** matrix.h
*/

#ifndef _matrix_cc
#define _matrix_cc
#include <matrix.h>

Matrix::Matrix(unsigned int rows, unsigned int cols) : rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);
  double *d = new double[5];
  m_ = new double *[rows_];
  for (unsigned int i = 0; i < cols_; ++i) {
    m_[i] = new double[cols_];
  }
};
#endif //_matrix_cc
