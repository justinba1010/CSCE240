/* Copyright 2019 */

#include <iostream>
#include <sstream>
#include <string>
#include <"main.h">

int ids[10];
double gpas[10];

struct Dollar {
  // Per Google style guide, can only have the following members:
  // constructor, destructor, Initialize(), Reset(), Validate()
  // These are all the same
  /*
  Dollar();

  Dollar() {
    dollars = 0;
    cents = 0.0;
  }
  */
  // The above and below are equal
  Dollar() : dollars(0), cents(0.0) {/* Intentionally empty */}
  Dollar(int _dollars, double _cents) : dollars(_dollars), cents(_cents) {/**/}
  Dollar(int _dollars) : dollars(_dollars), cents(_cents) {/**/}
  Dollar(double _cents) : dollars(0), cents(_cents) {/**/}
  /*
  Default
  Dollar(int _dollars = 0, double _cents = 0.0) : dollars(_dollars), cents(_cents)
  */
  ~Dollar() {
  }
  int dollars;
  double cents;
};  // Instead of 2 arrays, or 3 arrays


Dollar d1(5, 0.75), d2(5, .24);
const Dollar Add(const Dollar& lhs, const Dollar& rhs) {
  return Dollar(lhs.dollars + rhs.dollars, lhs.cents + rhs.cents);
}

Dollar sum = Add(d1, d2).dollars(5); // Cannot do this with const

Dollar sum2 = Add(d1, d2);
sum2.dollars = 5; // Can do this, this is the better way.

// Last way to use const

const Dollar Add(const Dollar& lhs, const Dollar& rhs) const {
  return Dollar(lhs.dollars + rhs.dollars, lhs.cents + rhs.cents);
}
