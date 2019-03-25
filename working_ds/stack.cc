/*  Copyright 2019
**  Justin Baum
**  stack.cc
*/

#include <cstddef>
#include <iostream>
#ifndef _STACK_CC
using std::cout;
using std::endl;

namespace Stack {
  template<typename T>
  struct Node{
    Node(T _data, Node* _next) : data(_data), next(_next) {/**/};
    T data;
    struct Node<T> *next;
  };

  template<typename T>
  class Stack{
    public:
      Node<T> *head;
      Stack<T>() {
        head = NULL;
      }
      void push(T data) {
        Node<T> *newHead;
        newHead = (struct Node<T>*)malloc(sizeof(struct Node<T>*)); 
        newHead->data = data;
        newHead->next = head;
        head = newHead;
      }
      T pop() {
        if (head == NULL) {
          return NULL;
        }
        // Keep the old pointer to free
        struct Node<T> *oldhead;
        T data = head->data;
        oldhead = head;
        head = head->next;
        // Now that the head has moved, let's free the memory
        free(oldhead);
        return data;
      }
  };
};
#endif

