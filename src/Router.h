//Include davids stuff here
#include <queue>
#include <list>
#include <iostream>
#include "Packet.h"

#ifndef ROUTER_HEADER
#define ROUTER_HEADER
using namespace std;
//Keep track of packets within queue.
class Router {
	public:
		Router ( );
		~Router ( );

		void setQueueSize ( int );
		int getQueueSize ( );

		void enqueueIncoming ( Packet );
		void enqueueOutgoing ( Packet );
		void enqueueWire ( Packet );

		Packet dequeueIncoming ( );
		Packet dequeueOutgoing ( );
		list<Packet> dequeueWire ( );

		int sizeOut ( );
		int sizeIn ( );

		void setBandwidth ( int );
		void setDelay ( int );

		int getBandwidth ( );
		int getDelay ( );

		float getAvgLost ( );
		int getPacketsLost ( );


	private:
		int bandwidth, delay;
		int totalTransmitted, totalLost;
		int maxQueueSize;

		queue<Packet> incoming;
		queue<Packet> outgoing;
		queue<Packet> wire;
};


#endif