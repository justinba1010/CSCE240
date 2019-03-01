/*  Copyright 2019
**  Justin Baum
**  stack.cc
*/

#include <cstddef>
#ifndef _STACK_2_CC

namespace Stack {
  template<typename T>
  struct Node{
    Node(T _data, Node* _next) : data(_data), next(_next) {/**/};
    T data;
    Node* next;
  };

  template<typename T>
  class Stack{
    public:
      Node<T>* head;
      Stack<T>() {
        head = NULL;
      }
      T pop() {
        if(head == NULL) {
          return NULL;
        }
        T data = head->data;
        Node<T> newHead = head->next;
        return data;
      }
      void push(T _data) {
        Node<T> newNode(_data, head);
        if(head == NULL) {
          head = &(newNode);
          return;
        }
        newNode.next = head;
        head = &(newNode);
      }
  };
};
#endif
