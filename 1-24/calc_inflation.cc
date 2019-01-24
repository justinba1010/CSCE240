/* calc_inflation.cc Copyright 2019
 * Inflation
 */

#include <iostream>

// Bored so made a 32 step O(1) float exponentiation
// (up to 2^32-1 exponents(basically unsigned))

double pow(double cost, double rate, int years, double curr) {
  if (years) {
    if (years & 0x80000000) {
      curr *= rate;
      years <<= 1;
      curr *= curr;
    } else {
      curr *= curr;
      years <<= 1;
    }
    return pow(cost, rate, years, curr);
  } else {
    return curr*cost;
  }
}

int main(int argc, char* argv[]) {
  double cost, rate;
  int years;

  // prompt user
  std::cout << "Enter cost of good: ";
  std::cin >> cost;
  std::cout << "Enter inflation rate: ";
  std::cin >> rate;
  std::cout << "Enter number of years: ";
  std::cin >> years;
  std::cout << pow(cost, rate, years, 1.0) std::endl;
  return 0;
}
