/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#ifndef _test_matrix_h  //NOLINT
#define _test_matrix_h

#include <matrix.h>
#include <cassert>
#include <iostream>
// using assert
using std::cout;
using std::endl;



class MatrixTester {
 public:
  bool Test_CopyConstructor() const;

  bool Test_Get() const;

  bool Test_AssignOp() const;

  bool Test_MulAssignOp() const;

  bool Test_AddOp() const;
};

#endif  //_test_matrix_h  //NOLINT

