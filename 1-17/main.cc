/*  2019 CSCE240
    Dr. Jeremy Lewis
    Justin Baum
*/

// Delegate work to other methods and classes, main is supposed to be very empty.
// 1 M ton = 35,273.92 oz

#include <iostream>
//#include "path"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    double oz, boxes;
    const double kOzInTon = 35273.92;
    cout << "Enter oz in cereal box: ";
    cin >> oz;
    boxes = kOzInTon/oz;
    int total_boxes = 1 + static_cast<int>(boxes);
    //Display
    cout << "Ship: ";
    cout << total_boxes;
    cout << " boxes.\n";

    return 0;
}

// Compile
/*
g++ file.cc # outut = a.out
*/
