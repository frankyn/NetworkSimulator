#include "Graph.h"

Graph::Graph ( ) {
     graphTable = NULL;
     minPathTable = NULL;
     graphNodes = 0;
     graphEdges = 0;
}

Graph::~Graph ( ) {
     clear ( );
}

/*
     Create a graph based on the amount of verteces given.
*/
int Graph::create ( int nodes ) {
     try {
          /*
               We need to clear out any previous created graphTables
          */
          
          clear ( );
          
          /*
               Set graphNodes to nodes and reset graphEdges.
               Allocate memory for new graph table.
          */
          graphNodes = nodes;
          
          graphTable = new int*[graphNodes];
          minPathTable = new int*[graphNodes];
          for ( int i = 0; i < graphNodes; i++ ) {
               graphTable[i] = new int[graphNodes];
               minPathTable[i] = new int[graphNodes];    
               for ( int b = 0; b < graphNodes; b++ ) {
                    graphTable[i][b] = 0;
                    minPathTable[i][b] = 0;
               }
          }
          
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

/*
     Will set an edge in the graphTable;
*/
void Graph::setEdge ( int from , int to ) {
     graphEdges++;
     graphTable[from][to] = 1;
     graphTable[to][from] = 1;
}
/*
     Remove an edge between from and to
*/
void Graph::removeEdge ( int from , int to ) {
     graphEdges--;
     graphTable[from][to] = 0;
     graphTable[to][from] = 0;
}
/*
     Check if there is an edge between FROM->TO
*/
int Graph::getEdge ( int from , int to ) {
     return graphTable[from][to]==1;
}

/*
     Generate graph of nodes*nodes
     This will create a multi-dimensioanl array of [nodes][nodes] size.   
*/
int Graph::generateEdges ( ) {
     try {
          for ( int i = 0; i < graphNodes; i++ ) {
               for ( int b = i; b < graphNodes; b++ ) {
                    /*
                         Run random to figure out if we set an edge at this location and then flip indexes to set it for both nodes 
                    */
                    if ( i != b && getEdge ( i , b ) ) {
                         if ( rand () % 2 ) {
                              setEdge ( i , b );
                         } else {
                              removeEdge ( i , b );
                         }
                    }
               }
          }
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

/*
     Clear out graph_table
*/
int Graph::clear ( ) {
     try {
          if ( !graphTable ) {
               return 1;
          }

          for ( int i = 0; i < graphNodes; i++ ) {
               if ( graphTable[i] ) {
                    delete [] graphTable[i];
                    delete [] minPathTable[i];
                    graphTable[i] = NULL;
                    minPathTable[i] = NULL;
               }
          }
          if ( graphTable ) {
               delete graphTable;
               delete minPathTable;
               graphTable = NULL;
               minPathTable = NULL;
          }
          graphNodes = 0;
          graphEdges = 0;
          
          return 1;
     } catch ( ... ) {
          return 0;
     }
}
/*
     Get Graph Edge count
*/
int Graph::edges ( ) {
     return edges ( );
}
/*
     Get Graph Size
*/
int Graph::size ( ) {
     return graphNodes;
}

/*
     Runs a check on every possible vertex to make sure it can reach everyother vertex.
*/
int Graph::checkConnectivity ( ) {
     int * graphCheck = new int[graphNodes];
     for ( int i = 0; i < graphNodes; i ++ ) {
          graphCheck[i] = -1;
     }
     for ( int i = 0; i < graphNodes; i ++ ) {
          checkLocation ( i , graphCheck );
          if ( graphCheck[i] == 0 ) {
               return 0;
          }
     }
     delete [] graphCheck;

     return 1;
}

/*
     DFS check to make sure we can attain every vertex in the possible graph.
*/
void Graph::checkLocation ( int from , int *&graphCheck ) {
     int edge = 0;
     graphCheck[from] = 0;

     for ( int v =  0; v < graphNodes; v++ ) {
          if ( v == from ) continue;
          if ( getEdge ( from , v ) == 1 && graphCheck[v] == -1 ) {
               edge = 1;
               if ( minPathTable[from][v] == 0 ) {
                    minPathTable[from][v] = 1;
               }
               checkLocation ( v , graphCheck );
          } else
          if ( graphCheck[v] ==  1 ) {
               edge = 1;
          }
     }
     graphCheck[from] = edge;
}

/*
     Print out of all of the edges in the graph.
     Looks like the graph print out that GraphIO can provide.
*/
string Graph::toString ( ) {
     stringstream outputParser;
     for ( int i = 0; i < graphNodes; i++ ) {
          for ( int b = i; b < graphNodes; b++ ) {
               if ( b != i && getEdge ( i , b ) >= 1 ) {
                    outputParser << i << " " << b << " -> " << getEdge ( i , b ) << endl;
               }
          }
     }
     return outputParser.str();
}
