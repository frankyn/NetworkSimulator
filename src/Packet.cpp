#include "Packet.h"

Packet::Packet ( ) {

}

Packet::~Packet ( ) {

}

/*
	Set source and destination indexes for packet.
	Kinda acts like a header.
*/
void Packet::setPath ( int s , int d ) {
	source = s;
	destination = d;
}

void Packet::setSize ( int s ) {
	size = s;
}

int Packet::getSource ( ) {
	return source;
}

int Packet::getDestination ( ) {
	return destination;
}

int Packet::getSize ( ) {
	return size;
}

