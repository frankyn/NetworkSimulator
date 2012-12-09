#include "Graph.h"

#ifndef GRAPH_ROUTER_HEADER
#define GRAPH_ROUTER_HEADER

class GraphRouter : public Graph {
	public:
		GraphRouter ( );
		~GraphRouter ( );
		
		int buildRouteTable ( );
		void send ( int , int , void * );
		void onReceive ( int , int , void * );

		void run ( ); //Run each queue waiting in each NetworkNode
	private:
		int ** graphRoutes;
		//NetworkNode * nodes; //Holds all nodes and their queue's that transmit data.

		void clearTable ( );
		void findShortestPath ( int , int );

};


#endif