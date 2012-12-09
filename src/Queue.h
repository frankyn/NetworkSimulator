#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "Chain.h"

/*to make a queue on the main program, you just need construct the queue by typing Queue<"type"> "name of Queue" and call 
the functions as you need them.*/ 
template<typename E>
class Queue: private Chain<E>
{
      public:
             void pushNode(E &data)
             {
                  insertAtBack(data);
             }
             
             bool popNode(E &data)
             {
                  return removeFirst(data);
             }
             
             bool emptyQueue()
             {
                  return this->isEmpty();
             }
             
             void printQueue()
             {
                  this->print();
             }
             
};//end class

#endif
              
                  
