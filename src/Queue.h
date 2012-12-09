#include <iostream>
#include <string>
#include "Chain.h"

#ifndef QUEUE_H
#define QUEUE_H


/*to make a queue on the main program, you just need construct the queue by typing Queue<"type"> "name of Queue" and call 
the functions as you need them.*/ 
template<typename E>
class Queue : private Chain<E>
{
      public:
            Queue ( );
            ~Queue ( );

            void pushNode(E &data);
            bool popNode(E &data);
            bool emptyQueue();
            void printQueue();
       
};//end class

#endif
              
                  
