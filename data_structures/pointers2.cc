// https://www.tutorialspoint.com/cplusplus/cpp_return_pointer_from_functions.htm
#include <iostream>
#include <ctime>
 
using namespace std;
 
// function to generate and retrun random numbers.
int * getRandom( ) {
    static int r[10];
 
   // set the seed
   
   for (int i = 0; i < 10; ++i) {
      r[i] = i;
      cout << r[i] << endl;
   }
 
   return r;
}
 
// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;
 
   p = getRandom();
   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }
 
   return 0;
}