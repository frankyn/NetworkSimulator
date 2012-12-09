#include <iostream>
#include <string>
#include "ListNode.h"

#ifndef CHAIN_H
#define CHAIN_H
using namespace std;

template<typename E> 
class Chain
{
      public:
             Chain();
             ~Chain();
             void insertAtFront(E &);
             void insertAtBack(E &);
             void setHead(ListNode <E>);
             void setTail(ListNode <E>);
             void setCurrent(ListNode<E>);
             bool removeFirst(E &);
             bool removeLast(E &);
             bool isEmpty();
             void print();
             
      private:
              ListNode<E> *Head;
              ListNode<E> *Tail;
              ListNode<E> *Current;
              ListNode<E> *newNode(E &);
};

#endif
