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
void GraphRouter::send ( int source , int destination , void * data ) {
	createRouters ( );
	nextPath ( source, destination );
}

/*
	Run this on each peice of data we received to a destination vertex
*/
void GraphRouter::onReceive ( int source , int destination , void * data ) {

}

/*
	Iterate through each queue and check against boundaries to see how fast, ...etc... the data was received on.
	Call each queue within each NetworkNode
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
