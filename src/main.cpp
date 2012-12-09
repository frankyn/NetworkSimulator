#include <iostream>
#include "Graph.h"
#include "GraphIO.h"
#include "GraphRouter.h"

using namespace std;

int main ( int argc, char ** argv ) {
     if ( argc != 3 ) {
          cout << "To run this you need arguments: <seed> <graph_filename>" << endl;
          exit ( 0 );
     } 
     string seedNumber = argv[1];
     string fileName = argv[2];

     srand ( atoi( seedNumber.c_str() ) );

     GraphRouter graphRouter; //We just want to reuse the graph so we will create a router based off its information once it's loaded in.
     GraphIO * graphIO = (GraphIO*)&graphRouter; //Use graphRouter Graph by typecasting it into GraphIO so we can use it to load in the file.
     
     

     if ( !graphRouter.create ( 10 ) ) {
          cout << "Unable to create graph" << endl;
     }
     
     cout << "Created graph" << endl;
     
     if ( !graphRouter.generateEdges ( ) ) {
          cout << "Unable to generate edges" << endl;          
     }     
     
     cout << "Generated graph" << endl;
     if ( !graphIO->write ( fileName ) ) {
          cout << "Unable to save graph to " << fileName <<endl;
     }
     
     cout << "Graph was saved to " << fileName << endl;
     

     if ( !graphIO->read ( fileName ) ) {
          cout << "Unable to read graph from " << fileName << endl;
          exit ( 0 );
     }
     
     cout << "Graph was read from " << fileName <<endl;
    

     if ( !graphIO->checkConnectivity ( ) ) {
          cout << "Graph wasn't completely connected " << fileName << "." <<endl;
          exit ( 0 );
     }
     
     cout << "Graph is completely connected " << fileName << "." <<endl;



     if ( !graphIO->findShortestPaths ( ) ) {
          cout << "Unable to find shortest paths" << endl;
          exit ( 0 );
     }

     cout << "Shortest Paths found." << endl;

     graphRouter.send ( 1, 3 );
     
     for ( int i = 0; i < 5; i++ ) {
          graphRouter.run ( );
     }

     cout << "Completed" << endl;
     graphIO = NULL;

     exit ( 0 );
     return 0;
}
