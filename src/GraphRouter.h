#include <iostream>
#include "Graph.h"
#include "Router.h"
#include "Packet.h"
#ifndef GRAPH_ROUTER_HEADER
#define GRAPH_ROUTER_HEADER
using namespace std;
class GraphRouter : public Graph {
	public:
		GraphRouter ( );
		~GraphRouter ( );
		
		void send ( int , int );
		void onReceive ( int , int );

		void run ( ); //Run each queue waiting in each NetworkNode
	private:
		Router * routers; //Holds all nodes and their queue's that transmit data.
		
		void createRouters ( );
		void clearRouters ( );
};


#endif