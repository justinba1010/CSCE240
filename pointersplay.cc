/*  Justin Baum
    19 January 2019
    CSCE240 Play with pointers why not.
*/

#include <iostream>

int main(int args, char* argv[]) {
    int r = 3;
    std::cout << &(r) << std::endl;
    std::cout << *(&(r)) << std::endl;
    int *p = (int *)0x0A;//Get the 4 bytes from memory at 0x10000000
    std::cout << p << std::endl;
    std::cout << &(p) << std::endl;
    //std::cout << *p << std::endl;

    std::cout << std::endl;

    int *x = &r;
    // I'm assuming that x is now the address of r;
    // &r is accessing the address of r;
    // &(x) is accessing the address of the pointer x
    std::cout << x << std::endl;
    std::cout << &(x) << std::endl;
    std::cout << *x << std::endl;
    // If this is correct then, I can make a new pointer to the pointer;
    int **y = &x;
    std::cout << std::endl;
    std::cout << y << std::endl;
    std::cout << &(y) << std::endl;
    std::cout << **y << std::endl;
    std::cout << *y << std::endl;
    return 0;
};
