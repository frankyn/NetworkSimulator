#include "Router.h"

Router::Router ( ) {

}

Router::~Router ( ) {

}

/*
	Add Packet to incoming packets
*/
void Router::enqueueIncoming ( Packet p ) {

}

/*
	Add Packet to outgoing packets
*/
void Router::enqueueOutgoing ( Packet p ) {

}

/*
	Remove packet from incoming packets
*/
Packet Router::dequeueIncoming ( ) {
	Packet p;

	return p;
}

/*
	Remove packet from Output Queue and return it.
*/
Packet Router::dequeueOutgoing ( ) {
	Packet p;

	return p;
}

/*
	Return size of outbound packets.
*/
int Router::sizeOut ( ) {
	return 0;
}

/*
	Return size of inbound packets.
*/

int Router::sizeIn ( ) {
	return 0;
}