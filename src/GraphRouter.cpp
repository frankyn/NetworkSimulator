#include "GraphRouter.h"

GraphRouter::GraphRouter ( ) {
	graphRoutes = NULL;
}

GraphRouter::~GraphRouter ( ) {
	clearTable ( );
	Graph::clear ( );
}

/*
	Add data to vertex queue so it can be send out on next transmission.
*/
void GraphRouter::send ( int source , int destination , void * data ) {

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
	Create a table for routes, create NetworkNodes with queues, and then call findShortestPath ( );
*/
int GraphRouter::buildRouteTable ( ) {
	try {
		//create NetworkNodes
		clearTable ( );
		graphRoutes = new int* [ size ( ) ];
		for ( int i = 0 ; i < size ( ) ; i++ ) {
			graphRoutes[i] = new int [ size ( ) ];
			for ( int b = 0 ; b < size ( ) ; b++ ) {
				graphRoutes[i][b] = 0;
			}
		}
		for ( int i = 0 ; i < size ( ); i++ ) {
			for ( int b = i ; b < size ( ) ; b++ ) {
				findShortestPath ( i, b );			
			}
		}
		
		return 1;
	} catch ( bad_alloc& e ) {
		cout << e.what ( ) << endl;
		return 0;
	}
}

/*
	Clear out routing table, and NetworkNodes from memory
*/
void GraphRouter::clearTable ( ) {
	try {
		
		if ( graphRoutes ) {
			
			for ( int i = 0 ; i < size ( ) ; i++ ) {
				delete [] graphRoutes[i];
				graphRoutes[i] = NULL;
			}
			delete graphRoutes;
			//delete NetworkNodes array
			graphRoutes = NULL;
		}
	} catch ( exception& e ) {
		cout << e.what ( ) << endl;
		return;
	}
}

/*
	Run shortest path algorithm from each vertex and find a path for each pair.
	If we need to go through another node give node index + 2
	EX: 0 = 2
		1 = 3
		2 = 4
		3 = 5
	That way we can avoid using memory locations
*/
void GraphRouter::findShortestPath ( int i , int b ) {

}