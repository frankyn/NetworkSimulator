#include "GraphRouter.h"

GraphRouter::GraphRouter ( int maxQueue ) {
	routers = NULL;
	maxQueueSize = maxQueue;
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
	list<Packet> wireReadyPackets;
	for ( int i = 0 ; i < size ( ); i++ ) {

		//Try and get packets that have finished off their delay waiting within the wireQueue within the Router class.
		wireReadyPackets = routers [i].dequeueWire ( );
		//If there are any wireReadyPackets send them all to their next destinations.
		while ( wireReadyPackets.size ( ) > 0 ) {
			tmp = wireReadyPackets.front ( );
			wireReadyPackets.pop_front ( );
			nextRouter = nextPath ( i, tmp.getDestination ( ) );
			routers [ nextRouter ].enqueueIncoming ( tmp );			
		}

		//Outgoing Packets are waiting to be send out
		outgoingSize = routers [ i ].sizeOut ( );

		if ( outgoingSize > 0 ) {
			tmp = routers [i].dequeueOutgoing ( );
			nextRouter = nextPath ( i, tmp.getDestination ( ) );
			/*
			//Next router #id
			cout << "Switching Packet to Router #" << nextRouter << endl;
			//Packet information
			cout << tmp.toString ( );
			*/
			routers [ nextRouter ].enqueueIncoming ( tmp );
		}

		//Incoming Packets are waiting to be parsed 
		incomingSize = routers [ i ].sizeIn ( );
		if ( incomingSize > 0 ) {
			//pop off next one in line.
			tmp = routers [i].dequeueIncoming ( );
			if ( i == tmp.getDestination ( ) ) {
				//Packet made it to destination
				
				cout << "Packet made it to its destination" << endl;
			} else {
				//Packet still in transit push into outgoing queue

				//Need to add delayed packets into outgoing queue
				//Add check to make sure there is enough bandwidth for this packet to be sent to outgoing in one shot.

				//Push packet into next router.
				routers [ i ].enqueueOutgoing ( tmp );
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
		for ( int i = 0; i < size ( ) ; i++ ) {
			routers[i].setQueueSize ( maxQueueSize ) ;
		}
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
