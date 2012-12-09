#include "Router.h"

Router::Router ( ) {
	bandwidth = 0;
	delay = 0;
	maxQueueSize = 0;
}

Router::~Router ( ) {

}

/*
	Set max queue size for the routers incoming and outgoing queues.
*/
void Router::setQueueSize ( int size ) {
	maxQueueSize = size;
}

/*
	Get max queue size for the routers incoming and outgoing queues.
*/
int Router::getQueueSize ( ) {
	return maxQueueSize;
}

/*
	Add Packet to incoming packets
*/
void Router::enqueueIncoming ( Packet p ) {
	if ( sizeIn ( ) < maxQueueSize ) {
		incoming.push ( p );
	}
}

/*
	Add Packet to outgoing packets
*/
void Router::enqueueOutgoing ( Packet p ) {
	if ( sizeOut ( ) < maxQueueSize ) {
		outgoing.push ( p );
	}
}

/*
	Remove packet from incoming packets
*/
Packet Router::dequeueIncoming ( ) {
	Packet p;
	p = incoming.front ( );
	incoming.pop ( );
	return p;
}

/*
	Remove packet from Output Queue and return it.
*/
Packet Router::dequeueOutgoing ( ) {
	Packet p;
	p = outgoing.front ( );
	outgoing.pop ( );
	return p;
}

/*
	Return size of outbound packets.
*/
int Router::sizeOut ( ) {
	return outgoing.size ( );
}

/*
	Return size of inbound packets.
*/

int Router::sizeIn ( ) {
	return incoming.size ( );
}

void Router::setBandwidth ( int b ) {
	bandwidth = b;
}

void Router::setDelay ( int d ) {
	delay = d;
}

int Router::getBandwidth ( ) {
	return bandwidth;
}

int Router::getDelay ( ) {
	return delay;
}