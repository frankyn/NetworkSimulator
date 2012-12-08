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
     
     GraphIO graphIO;
     GraphRouter * graphRouter = (GraphRouter*)&graphIO; //We just want to reuse the graph so we will create a router based off its information once it's loaded in.

     
     /*
     if ( !graph.create ( 10 ) ) {
          cout << "Unable to create graph" << endl;
     }
     
     cout << "Created graph" << endl;
     
     if ( !graph.generateEdges ( ) ) {
          cout << "Unable to generate edges" << endl;          
     }     
     
     cout << "Generated graph" << endl;
     
     if ( !graph.write ( fileName ) ) {
          cout << "Unable to save graph to " << fileName <<endl;
     }
     
     cout << "Graph was saved to " << fileName << endl;
     */

     if ( !graphIO.read ( fileName ) ) {
          cout << "Unable to read graph from " << fileName << endl;
          exit ( 0 );
     }
     
     cout << "Graph was read from " << fileName <<endl;
    

     if ( !graphIO.checkConnectivity ( ) ) {
          cout << "Graph wasn't completely connected " << fileName <<endl;
          exit ( 0 );
     }

     cout << "Graph is completely connected " << fileName <<endl;

     
     
     return 0;
}
