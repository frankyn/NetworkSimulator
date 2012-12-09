#include "Router.h"

Router::Router ( ) {
	bandwidth = 0;
	delay = 0;
}

Router::~Router ( ) {

}

/*
	Add Packet to incoming packets
*/
void Router::enqueueIncoming ( Packet p ) {
	incoming.push ( p );
}

/*
	Add Packet to outgoing packets
*/
void Router::enqueueOutgoing ( Packet p ) {
	outgoing.push ( p );
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