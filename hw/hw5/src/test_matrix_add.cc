/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <test_matrix.h>


int main(int argc, char** argv) {
  MatrixTester tester;

  cout << "Testing Matrix::operator+" << endl;
  if (tester.Test_AddOp()) {
    cout << "  PASSED" << endl;
    return 0;
  }

  cout << "  FAILED" << endl;
  return 1;
}


bool MatrixTester::Test_AddOp() const {
  const int kRows = 3, kCols = 4;
  Matrix m1, m2;
  m1.m_ = new double *[kRows];
  for (unsigned int i = 0; i < kRows; ++i) {
    m1.m_[i] = new double[kCols];

    for (unsigned int j = 0; j < kCols; ++j)
      m1.m_[i][j] = (i + 1.0)*(j + 1.0);
  }
  m1.rows_ = kRows;
  m1.cols_ = kCols;

  // TEST ADDITION CORRECTNESS
  m2 = m1 + m1;
  if (m2.m_[0][0] != 2.0) {
    cout << "  Expected Matrix2[0][0]: 2.0, Actual: " << m2.m_[0][0] << endl;
    return false;
  }
  if (m2.m_[1][3] != 16.0) {
    cout << "  Expected Matrix2[1][3]: 16.0, Actual: " << m2.m_[1][3]
        << endl;
    return false;
  }
  if (m2.m_[2][2] != 18.0) {
    cout << "  Expected Matrix2[2][2]: 18.0, Actual: " << m2.m_[2][2]
        << endl;
    return false;
  }

  return true;
}
