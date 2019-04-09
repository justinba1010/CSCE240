

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <vector>
using std::vector;


const vector<double>& PlusEquals(double offset, vector<double>* elements) {
  for (auto it = elements->begin(); it != elements->end(); ++it) {
    // it++ is going to be a huge memory sink if we do not use prefix
      *(it) += offset;
  }
  return *elements;
};

ostream& operator<<(ostream& lhs, const vector<double>& rhs) {
  for (auto it = rhs.begin(); it != rhs.end(); ++it) {
    lhs << *it << ' ';
  }
  return lhs;
}

const vector<double>& operator+=(vector<double>& elements, double offset) {
  return PlusEquals(offset, &elements);
};


int main(int argv, char* arc[]) {
  vector<double> vec;
  for(int i = 0; i < 5; ++i) {
    vec.push_back(static_cast<double>(i));
  }
  cout << vec << endl;
  vec += 13;
  auto vec2 =  PlusEquals(13, &vec);
  cout << vec2 << endl;
  cout << vec << endl;
  return 0;
}

/*
int operator++(int) {
  //Postfix
  type copy = *this;
}

int operator++() {
  //Prefix
  *this += 1;
  return *this;
}
*/
