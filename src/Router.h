//Include davids stuff here
#include <queue>
#include "Packet.h"

#ifndef ROUTER_HEADER
#define ROUTER_HEADER
using namespace std;
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

		void setBandwidth ( int );
		void setDelay ( int );

		int getBandwidth ( );
		int getDelay ( );
	private:
		int bandwidth, delay;
		queue<Packet> incoming;
		queue<Packet> outgoing;
};


#endif