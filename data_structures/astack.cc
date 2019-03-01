/*  Justin Baum
    astack.cc
    19 January 2019
    Array Stack in CPP
*/
namespace Astack {
    class Astack {
        public:
            static const int max = 64;
            int a[max];
            int top;
            Astack() {
                top = -1;
            }
            bool push(int x);
            int pop();
            bool isEmpty();
    };

    bool Astack::push(int x) {
        if(top >= (max-1)){
            std::cout << "Stack overflow" << std::endl;
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }

    int Astack::pop() {
        if(top < 0) {
            std::cout << "Stack underflow" << std::endl;
            return 0;
        }
        return a[top--];
    }

    bool Astack::isEmpty() {
        return (top < 0);
    }
}
