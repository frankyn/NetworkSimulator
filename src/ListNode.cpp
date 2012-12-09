#include <iostream>
#include <string>
#include "ListNode.h"

//constructor for the node 
template<typename E>
ListNode<E>::ListNode(E &info)
{
  setData(info);
  setNext(0);
}

//set the data within the node
template<typename E> 
void ListNode<E>::setData(E in)
{
     data=in;
}//end setData

//If, for any reason, you need to change what a Node is linked to, you can use this to link it somewhere else
template<typename E> 
void ListNode<E>::setNext(ListNode<E> place)
{
     nextNode=place;
}//end setNext

//retrieve the data a node has
template<typename E> 
E ListNode<E>:: getData()
{
  return data;
}//end getData
