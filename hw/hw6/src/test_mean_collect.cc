
#include <iostream>
using std::cout;
using std::endl;

#include <mean.h>
using csce240::Mean;
#include <statistic.h>
using csce240::Statistic;

void TestMeanCollect(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Mean();
  TestMeanCollect(stat);
  cout << "Testing Mean::Collect(double)" << endl;
  cout << "  PASSED" << endl;
  delete stat;
  return 0;
}

void TestMeanCollect(Statistic* stat) {
  const double kData[] = {34, 54, 99, 102, 43};
  const unsigned int kSize = sizeof(kData) / sizeof(double);

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);
}
