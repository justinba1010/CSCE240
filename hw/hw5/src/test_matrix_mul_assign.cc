/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <test_matrix.h>


int main(int argc, char** argv) {
  MatrixTester tester;

  cout << "Testing Matrix::operator*=" << endl;
  if (tester.Test_MulAssignOp()) {
    cout << "  PASSED" << endl;
    return 0;
  }

  cout << "  FAILED" << endl;
  return 1;
}



bool MatrixTester::Test_MulAssignOp() const {
  const int kRows = 3, kCols = 4;
  Matrix test_m;
  test_m.m_ = new double *[kRows];
  for (unsigned int i = 0; i < kRows; ++i) {
    test_m.m_[i] = new double[kCols];

    for (unsigned int j = 0; j < kCols; ++j)
      test_m.m_[i][j] = (i + 1.0)*(j + 1.0);
  }
  test_m.rows_ = kRows;
  test_m.cols_ = kCols;

  // TEST MUL ASSIGMENT OP CORRECT RETURN
  const Matrix *m_ptr = &(test_m *= 2.0);
  if (m_ptr != &test_m) {
    cout << "  Expected return address of assigment: " << &test_m
        << ", Actual: " << m_ptr << endl;
    return false;
  }
  // TEST MUL ASSIGMENT OP CALCULATION
  if (test_m.m_[0][0] != 2.0) {
    cout << "  Expected Matrix[0][0]: 2.0, Actual: " << test_m.m_[0][0] << endl;
    return false;
  }
  if (test_m.m_[1][3] != 16.0) {
    cout << "  Expected Matrix[1][3]: 24.0, Actual: " << test_m.m_[1][3]
        << endl;
    return false;
  }
  if (test_m.m_[2][2] != 18.0) {
    cout << "  Expected Matrix[2][2]: 18.0, Actual: " << test_m.m_[2][2]
        << endl;
    return false;
  }
  return true;
}
