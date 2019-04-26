
#include <iostream>
using std::cout;
using std::endl;

#include <mean.h>
using csce240::Mean;
#include <statistic.h>
using csce240::Statistic;

bool TestMeanCalculate(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Mean();
  cout << "Testing Mean::Calculate()" << endl;
  if (!TestMeanCalculate(stat)) {
    cout << "  FAILED" << endl;
    return 1;
  }
  cout << "  PASSED" << endl;
  delete stat;
  return 0;
}

bool TestMeanCalculate(Statistic* stat) {
  const double kData[] = {34, 54, 99, 102, 43};
  const unsigned int kSize = sizeof(kData) / sizeof(double);
  const double kExpected = (34 + 54 + 99 + 102 + 43) / 5.0;

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);

  double actual = stat->Calculate();
  if (kExpected != actual) {
    cout << "  Expected: " << kExpected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
