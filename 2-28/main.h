/* Copyright 2019 */

#ifndef _01_MAIN_H
#define _01_MAIN_H

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



#endif
