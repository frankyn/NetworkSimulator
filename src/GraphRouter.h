#include "Graph.h"
#include "Router.h"
#ifndef GRAPH_ROUTER_HEADER
#define GRAPH_ROUTER_HEADER

class GraphRouter : public Graph {
	public:
		GraphRouter ( );
		~GraphRouter ( );
		
		void send ( int , int , void * );
		void onReceive ( int , int , void * );

		void run ( ); //Run each queue waiting in each NetworkNode
	private:
		Router * routers; //Holds all nodes and their queue's that transmit data.
		void createRouters ( );
		void clearRouters ( );
};


#endif