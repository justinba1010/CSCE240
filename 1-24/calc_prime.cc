/* calc_prime.cc Copyright 2019
 * Inflation
 * Sieve of Erasthones(sp?)
 */

#include <iostream>


// Technically O(n^2)
int main(int argc, char* argv[]) {
  std::cout << "Enter a number to check until: " << std::endl;
  int max;
  std::cin >> max;
  bool *primes = reinterpret_cast<bool*>(malloc(max*sizeof(bool)));
  for (int i = 0; i < max; ++i) {  // O(n)
    primes[i] = true;
  }
  for (int i = 2; i < max; ++i) {  // O(n^2)
    if (primes[i]) {
      int x = i+i;  // i+i is cheaper than 2*i
      while (x < max) {  // O(n)
        primes[x] = false;
        x += i;
      }
    }
  }
  std::cout << "Primes are listed below" << std::endl;
  for (int i = 2; i < max; ++i) {  // O(n)
    if (primes[i]) {
      std::cout << i << std::endl;
    }
  }
  return 0;
}
