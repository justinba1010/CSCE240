#include <iostream>
int * returnpointer() {
    static int r[100];
    for(int i = 0; i < 100; i++) {
        r[i] = i;
        std::cout << i << std::endl;
    }
    return r;
};

char * returnchars() {
    static char r[100];
    for(char c = 0; c < 100; c++) {
        r[c] = c;
        std::cout << c << std::endl;
    }
    return r;
}

int main(int args, char *argv[]) {
    int *p;
    p = returnpointer();
    for(int i = 0; i < 100; i++) {
        std::cout << "*(p + " << i << ") = " << *(p+i) << std::endl;
    };
    char *c;
    c = returnchars();
    for(int i = 0; i < 100; i++) {
        std::cout << "*(c + " << i << ") = " << *(c+i) << std::endl;
    };
    return 0;
};