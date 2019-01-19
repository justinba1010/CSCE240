/*  Justin Baum
    18 January 2019
    CSCE240 Multifiles Practice
*/

#include <iostream>
#include "astack.cc"
#include "stack.cc"

int main(int args, char* argv[]) {
    Astack::Astack s;
    s.push(100);
    s.push(200);
    s.push(300);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    Stack::Stack ss;
    ss.push(100);
    ss.push(200);
    ss.push(300);
    std::cout << ss.pop() << std::endl;
    std::cout << ss.pop() << std::endl;
    std::cout << ss.pop() << std::endl;
    return 0;
}
