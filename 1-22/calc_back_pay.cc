/* Copyright 2019 Dr. Jeremy Lewis
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int args, char*  argv[]) {
    const int kNumberOfMonths = 6;
    const double kPayIncrease = 0.076;
    cout << "Enter your annual salary: ";
    double salary;
    cin >> salary;
    double back_pay = kPayIncrease * kNumberOfMonths * salary;
    cout << "Your back pay is " << (back_pay / 12.0) << endl;
    return 0;
}
