#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>
using namespace std;

template<typename E> class Chain;

template<typename E> 
class ListNode
{     
      friend class Chain<E>;
      
      public:
             ListNode(E &);
             E getData();
             void setData(E);
             void setNext(ListNode <E>);
        
      private:
              E data;
              ListNode<E> *nextNode;


};

#endif
  
       
