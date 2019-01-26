/* Copyright 2019 Justin Baum
*/

template<typename T>

class Stack {
    private:
        struct Node {
            T value;
            Node *next;
        };
        Node *head;
    public:
        bool isEmpty();
        void push(T value);
        T pop();
        
}