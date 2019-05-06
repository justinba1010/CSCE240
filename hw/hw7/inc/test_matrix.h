/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <cassert>
// using assert
#include <iostream>
using std::cout;
using std::endl;

#include <matrix.h>
#include <matrix.h>


class MatrixTester {
 public:
  bool Test_CopyConstructor() const;

  bool Test_Get() const;

  bool Test_AssignOp() const;

  bool Test_MulAssignOp() const;

  bool Test_AddOp() const;
};
