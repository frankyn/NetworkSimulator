
#include <iostream>
#include <string>
#include "Packet.h"

#ifndef QUEUE_H
#define QUEUE_H


class PacketItem {
	public:
		PacketItem ( ) {
		}

		Packet item;
		PacketItem * next;
		PacketItem * prev;
};
class PacketQueue { 
	public:
		PacketQueue ( ) {
			HEAD = NULL;
			TAIL = NULL;
			currentSize = 0;
		}

		~PacketQueue ( ) {

		}

		void push ( Packet p ) {
			PacketItem * ptr = new PacketItem ( );
			ptr->item = p;
			if ( currentSize == 0 ) {
				HEAD=TAIL=ptr;
			}else {
				TAIL->next = ptr;
				TAIL = ptr;
			}
			ptr = NULL;
			incrementSize ( );

		}

		void pop ( Packet &p ) {
			if ( currentSize == 0 ) return;
			if ( HEAD == TAIL ) {
				HEAD=TAIL=0;
				return;
			} else {
				PacketItem * ptr = HEAD;
				p = HEAD->item;
				HEAD = HEAD->next;
				delete ptr;
				decrementSize ( );
			}
		}

		void incrementSize ( ) {
			currentSize ++;
		}
		void decrementSize ( ) {
			currentSize --;
		}

	 	int size  ( ) {
			return currentSize;
		}

	private:
		PacketItem * HEAD;
		PacketItem * TAIL;
		int currentSize;
};
#endif
              
                  
