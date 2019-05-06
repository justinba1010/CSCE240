/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <test_matrix.h>


int main(int argc, char** argv) {
  MatrixTester tester;

  cout << "Testing Matrix::Get" << endl;
  if (tester.Test_Get()) {
    cout << "  PASSED" << endl;
    return 0;
  }

  cout << "  FAILED" << endl;
  return 1;
}

bool MatrixTester::Test_Get() const {
  const int kRows = 3, kCols = 3;
  const double kM[kRows][kCols] = {
    {1.5, 2.980, 3.087},
    {2.5, 4.980, 6.087},
    {3.5, 6.980, 9.087}
  };
  Matrix<double> m;
  m.m_ = new double *[kRows];
  for (unsigned int i = 0; i < kRows; ++i) {
    m.m_[i] = new double[kCols];
    for (unsigned int j = 0; j < kCols; ++j)
        m.m_[i][j] = kM[i][j];
  }
  m.rows_ = kRows;
  m.cols_ = kCols;

  // TEST GET METHOD
  for (unsigned int i = 0; i < kRows; ++i)
    for (unsigned int j = 0; j < kCols; ++j)
        if (kM[i][j] != m.Get(i, j)) {
          cout << "  Expected: " << kM[i][j] << ", Actual: " << m.Get(i, j)
              << endl;
          return false;
        }

  return true;
}
