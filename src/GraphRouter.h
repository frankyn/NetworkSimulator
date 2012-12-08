#include "Graph.h"

#ifndef GRAPH_ROUTER_HEADER
#define GRAPH_ROUTER_HEADER

class GraphRouter : public Graph {
	public:
		GraphRouter ( );
		~GraphRouter ( );
	
		void send ( int , int , void * );
		void onReceive ( int , int , void * );

	private:
		int ** graphRoutes;

		void buildRouteTable ( );
};


#endif