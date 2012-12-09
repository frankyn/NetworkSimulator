#include "GraphRouter.h"

GraphRouter::GraphRouter ( int maxQueue ) {
	routers = NULL;
	maxQueueSize = maxQueue;
	totalGeneratedPackets = 0;
	totalSuccessfulPackets = 0;
}

GraphRouter::~GraphRouter ( ) {
	clearRouters ( );
}

/*
	Add data to vertex queue so it can be send out on next transmission.
*/
void GraphRouter::send ( int source , int destination ) {
	createRouters ( );
	
	totalGeneratedPackets++;
	//cout << "Added Packet to SOURCE ( " << source << " ) -> DESTINATION ( " << destination << " )" << endl; 
	Packet p;
	p.setPath ( source, destination );
	p.setSize ( rand() % 1001 );  // [ 0 , ( 1000 kilobits = 1mb ) ]
	//need to use Poisson distrubution here...
	routers [ source ].enqueueIncoming ( p );
}

/*
	Statistics on all the network transfers
*/

/* 
	return Total Generated Packets at the moment called.
*/
int GraphRouter::getTotalGeneratedPackets ( ) {
	return totalGeneratedPackets;
}

/*
	return Total amount of packets that arrived at its destination.
*/
int GraphRouter::getTotalSuccessfulPackets ( ) {
	return totalSuccessfulPackets;
}

/*
	Find the most lost packets out of all of the routers.
*/
int GraphRouter::getMaxLostPackets ( ) {
	int max = -1;
	for ( int i = 0 ; i < size ( ) ; i++ ) {
		if ( routers [i].getPacketsLost ( ) > max ) {
			max = routers[i].getPacketsLost ( );
		}
	}
	return max;
}

/* 
	Find the least lost packets out of all of the routers.
*/
int GraphRouter::getMinLostPackets ( ) {
	int min = INT_MAX;
	for ( int i = 0 ; i < size ( ) ; i++ ) {
		if ( routers [i].getPacketsLost ( ) < min ) {
			min = routers[i].getPacketsLost ( );
		}
	}
	return min;
}

/*
	Calculate total of lost packets and then return the average lost across all routers.
*/
int GraphRouter::getAvgLostPackets ( ) {
	int totalLost = 0;
	for ( int i = 0 ; i < size ( ) ; i++ ) {
		totalLost += routers[i].getPacketsLost ( );
	}
	return totalLost;
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
				totalSuccessfulPackets++;
				//cout << "Packet made it to its destination" << endl;
			} else {
				//Packet still in transit push into outgoing queue

				//!!!!!Need to add delayed packets into outgoing queue
				//!!!!!Add check to make sure there is enough bandwidth for this packet to be sent to outgoing in one shot.

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
	
	
	if ( !routers ) {
		routers = new Router [ size ( ) ];
		for ( int i = 0; i < size ( ) ; i++ ) {
			routers[i].setQueueSize ( maxQueueSize ) ;
			routers[i].setBandwidth ( rand ( ) % 1001 ); //Bandwidth is set in kilobits ( 1000kbps = 1mbps )
			routers[i].setDelay ( rand ( ) % 11 + 1 ); //Delay is in seconds
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
