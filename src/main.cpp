#include <iostream>
#include "Graph.h"

using namespace std;

int main ( int argc, char ** argv ) {
     if ( argc != 3 ) {
          cout << "To run this you need arguments: <seed> <graph_filename>" << endl;
          exit ( 0 );
     } 
     string seedNumber = argv[1];
     string fileName = argv[2];
     srand ( atoi( seedNumber.c_str() ) );
     
     Graph graph;
     
     
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
     
     cout << "Graph was saved to graph.txt" << endl;
     
     if ( !graph.read ( fileName ) ) {
          cout << "Unable to read graph from " << fileName << endl;
     }
     
     cout << "Graph was read from graph.txt" <<endl;
     
     
     cout << graph.toString() << endl;
     return 0;
}
