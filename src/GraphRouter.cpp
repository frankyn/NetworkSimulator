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
	p.setSize ( rand() % 1001 );  // [ 0 , ( 1000 kilobits = 1mb ) ]
	routers [ source ].enqueueIncoming ( p );
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
	int incomingSize = 0, outgoingSize = 0;
	int nextRouter = -1;
	Packet tmp;
	for ( int i = 0 ; i < size ( ); i++ ) {
		incomingSize = routers [ i ].sizeIn ( );

		if ( incomingSize > 0 ) {
			tmp = routers [i].dequeueIncoming ( );
			nextRouter = nextPath ( i , tmp.getDestination ( ) );
			cout << tmp.toString ( );
			cout << "Next Router: " << nextRouter << endl;

			if ( tmp.getDestination ( ) == nextRouter ) {
				//Packet made it to destination
				cout << "Packet made it to its destination" << endl;
			} else {
				//Packet still in transit push into next router.
				routers [ nextRouter ].enqueueIncoming ( tmp );
			}
		}
	}
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
