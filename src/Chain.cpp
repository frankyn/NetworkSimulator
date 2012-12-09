#include "Chain.h"
using namespace std;

//constructs the linked list and sets the pointers to 0
template<typename E>
Chain<E>::Chain()
{
  setHead(0);
  setTail(0);
}//end Chain

//deconstructor for the linked list
template<typename E>
Chain<E>::~Chain()
{
  if(isEmpty () != true){
             Current=Head;
             ListNode<E> *temp;
             while(Current != 0){
                   temp=Current;
                   Current=Current->nextNode;
                   delete temp;
                   }//end while
             }//end if
     cout<<"The linked list has been destroyed.\n";        
}//end ~Chain

//Head should already be set to the front of the list, but in case you need to change it
template<typename E> 
void Chain<E>::setHead(ListNode<E> front)
{
     Head=front;
}//end setHead

//same applies to the Tail
template<typename E> 
void Chain<E>::setTail(ListNode<E> last)
{
     Tail=last;
}//end setTail

//when working with the list, we are going to need to set current to the node we want to alter or change
template<typename E> 
void Chain<E>::setCurrent(ListNode<E> location)
{
     Current=location;
}//end setTail

//put a node at the front
template<typename E>
void Chain<E>::insertAtFront(E &digit)
{
     ListNode<E> *newPtr=newNode(digit);
     
     if(isEmpty() == true){
        Head=Tail=newPtr;
        }//end if
     else{
          newPtr->nextNode=Head;
          Head=newPtr;
     }//end else
                
}//end insertAtFront

//put a node at the back
template<typename E>
void Chain<E>::insertAtBack(E &digit)
{
     ListNode<E> *newPtr=newNode(digit);
     
     if(isEmpty() == true){
          Head=Tail=newPtr;
          }//end if
      else{
           Tail->nextNode=newPtr;
           Tail=newPtr;
      }//end else              
}//end insertAtBack

//remove the node at the front and return true if it was successful
template<typename E>
bool Chain<E>::removeFirst(E &cell)
{
     if(isEmpty() == true){
       return false;
     }//end if
     
     else{
       ListNode<E> *temp=Head;
       if(Head==Tail){
         Head=Tail=0;
       }
       else{
         Head=Head->nexNode;
         }
         
         cell=temp->data;
         delete temp;
         return true;
         }//end else
         
}//end removeFirst

//remove the node at the back and return true if it was successful
template<typename E>
bool Chain<E>::removeLast(E &cell)
{
     ListNode<E> *temp=Tail;
     
     if(isEmpty()==true){
       return false;
     }//end if
     
     else{
       if(Head==Tail){
         Head=Tail=0;
       }
       else{
        setCurrent(Head);
        while(Current->nextNode != Tail){
          Current=Current->nextNode;
          }//end while
        
        Tail=Current;
        Current->nextNode=0;
        }//end else
        
        cell=temp->data;
        delete temp;
        return true;
        
     }//end first else
}//end removeLast

//check if the list has any nodes
template<typename E>
bool Chain<E>:: isEmpty()
{
     return Head==0;
}//end isEmpty

template<typename E>
ListNode<E> *Chain<E>::newNode(E &digit)
{
  return new ListNode<E>(digit);
}//end newNode

//print the list if we want to see it
template<typename E>
void Chain<E>::print()
{
     if(isEmpty()==true){
       cout<<"The list is empty.\n";
       return;
     }
     
     setCurrent(Head);
     
     cout<<"The list is : ";
     
     while(Current !=0){
       cout<<Current->data<<' ';
       Current=Current->nextNode;              
     }//end while
     
     cout<<"/n/n";
     
     
}//end print
