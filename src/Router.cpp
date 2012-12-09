#include "Router.h"

Router::Router ( ) {

}

Router::~Router ( ) {

}

/*
	Add Packet to incoming packets
*/
void Router::enqueuePacket ( Packet p ) {

}

/*
	Remove packet from Output Queue and return it.
*/
Packet Router::dequeuePacket ( ) {
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