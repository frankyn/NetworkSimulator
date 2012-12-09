#include "GraphRouter.h"

GraphRouter::GraphRouter ( ) {
	routers = NULL;
}

GraphRouter::~GraphRouter ( ) {
	clearRouters ( );
}

/*
	Add data to vertex queue so it can be send out on next transmission.
*/
void GraphRouter::send ( int source , int destination ) {
	createRouters ( );
	cout << "Added Packet to SOURCE ( " << source << " ) -> DESTINATION ( " << destination << " )" << endl; 
	Packet p;
	p.setPath ( source, destination );
	p.setSize ( 10 );
	routers [ source ].enqueuePacket ( p );
}

/*
	Run this on each peice of data we received to a destination vertex
*/
void GraphRouter::onReceive ( int source , int destination ) {

}

/*
	Iterate through each queue and check against boundaries to see how fast, ...etc... the data was received on.
	Call each queue within each NetworkNode
	Use nextPath ( source, destination ) to figure which way to take it next.
	If router bandwidth is too small for packet place on wait queue till it is completed and then switch the packet.
*/
void GraphRouter::run ( ) {

}

/*
	Create a Router for ever node within the graph.
	Size of routers array is based on the size ( ) of graph.
*/
void GraphRouter::createRouters ( ) {
	//Clear out routers if it allocated space previously.
	clearRouters ( );
	
	if ( !routers ) {
		routers = new Router [ size ( ) ];
	}
}

/*
	Clear out routers array from memory.
*/
void GraphRouter::clearRouters ( ) {
	if ( routers ) {
		delete [] routers;
		routers = NULL;
	}
}
