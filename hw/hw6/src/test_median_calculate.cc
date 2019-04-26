
#include <iostream>
using std::cout;
using std::endl;

#include <median.h>
using csce240::Median;
#include <statistic.h>
using csce240::Statistic;

bool TestMedianCalculate(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Median();
  cout << "Testing Median::Calculate()" << endl;
  if (!TestMedianCalculate(stat)) {
    cout << "  FAILED" << endl;
    return 1;
  }
  
  cout << "  PASSED" << endl;
  delete stat;
  return 0;
}

bool TestMedianCalculate(Statistic* stat) {
  const double kData[] = {34, 54, 99, 102, 43};
  const unsigned int kSize = sizeof(kData) / sizeof(double);

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);

  double expected = 54;
  double actual = stat->Calculate();
  if (expected != actual) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  stat->Collect(22);  // now testing {34, 54, 99, 102, 43, 22}

  expected = (43 + 54) / 2.0; // [(n/2)th + (n/2 + 1)th] / 2
  actual = stat->Calculate();
  if (expected != actual) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
