/*  Justin Baum
    list.cc
    20 January 2019
    List in CPP
*/

#include <iostream>

// Garbage
namespace List {
    template<typename t>
    struct Node {
        t *data;
        Node *next;
    };
    template<typename t>
    class List {
        public:
            Node<t> *head;
            List();
            void insert(t data);
            *t pop();
    };
    template<typename t>
    List<t>::List() {
        head = NULL;
    };
    template<typename t>
    void List<t>::insert(t *data) {
        Node<t> *newNode = new Node<t>;
            newNode->data = *data;
            if(head == NULL) {
                //Insert as list
                head = newNode;
                return;
            }
            Node<t> *curr = head;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
    };
    template<typename t>
    *t List<t>::pop() {
        if(head == NULL) {
            return NULL;
        }
        t data = head->data;
        head = head->next;
        return data;
    }
};
