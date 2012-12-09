#include "Queue.h"

template<typename E>
Queue<E>::Queue ( ) {

}
template<typename E>
Queue<E>::~Queue ( ) {

}

template<typename E>
void Queue<E>::pushNode(E &data) {
	insertAtBack(data);
}

template<typename E>            
bool Queue<E>::popNode(E &data) {
	return removeFirst(data);
}

template<typename E>
bool Queue<E>::emptyQueue() {
	return this->isEmpty();
}
             
template<typename E>
void Queue<E>::printQueue() {
	this->print();
}