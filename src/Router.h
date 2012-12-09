//Include davids stuff here
#include "Packet.h"

#ifndef ROUTER_HEADER
#define ROUTER_HEADER

//Keep track of packets within queue.
class Router {
	public:
		Router ( );
		~Router ( );

		void enqueueIncoming ( Packet );
		void enqueueOutgoing ( Packet );
		Packet dequeueIncoming ( );
		Packet dequeueOutgoing ( );
		
		int sizeOut ( );
		int sizeIn ( );
	private:

};


#endif