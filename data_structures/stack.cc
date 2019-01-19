/*  Justin Baum
    stack.cc
    19 January 2019
    Linked Stack in CPP
*/

namespace Stack {
    struct Node {
        int data;
        struct Node *next;
    };

    class Stack {
        public:
            Stack();
            bool push(int x);
            int pop();
            bool isEmpty();
        private:
            Node *head;
    };
    Stack::Stack() {
        // set to empty
        head = NULL;
    };
    bool Stack::push(int x) {
        Node *newNode = new Node; //Not sure how this works for a struct.
        newNode->data = x;
        newNode->next = head; // Move pointer to the old head;
        head = newNode; // New head
        return true;
    };
    int Stack::pop() {
        if(isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return 0;
        }
        int data = head->data;
        head = head->next;
        return data;
    };
    bool Stack::isEmpty() {
        return (head == NULL);
    }
};
