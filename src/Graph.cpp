#include "Graph.h"
using namespace std;

Graph::Graph ( ) {
     graphTable = NULL;
     graphNodes = 0;
     graphEdges = 0;
}

Graph::~Graph ( ) {
     clear ();
}

int Graph::read ( string filename ) {
     try {
          ifstream graphFile ( filename.c_str() );
          
          if(graphFile.is_open()){
               int i = 0, b = 0, edgesFound = 0;
               graphNodes = getNumber ( graphFile ); //Grab node amount
               graphEdges = getNumber ( graphFile ); //Grab edge amount
               
               create ( graphNodes ); //create graphTable based on node amount
               
               //run through and add edges to graphTable
               while( !graphFile.eof ( ) ){
                    if ( (i = getNumber(graphFile)) == -1 ) {
                         break;
                    }
                    if ( !(b = getNumber(graphFile)) == -1 ) {
                         break;
                    }
                    graphTable[i][b] = 1;
                    graphTable[b][i] = 1;
                    edgesFound ++;
               }
               
               graphFile.close();
               return 1;
          } else {
               cout<<"File could not be found.\n";
          }
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

/*
     Print out ascii version of graph
*/
int Graph::write ( string filename ) {
     try {
          ofstream graphFile ( filename.c_str() );
         
          graphFile << graphNodes << " " << graphEdges << endl; 
          
          /*
               Loop through graph and set each link possible
          */
          for ( int i = 0; i < graphNodes; i++ ) {
               for ( int b = 0; b < graphNodes; b++ ) {
                    if ( graphTable[i][b] == 1) {
                         graphTable[i][b] = 0;
                         graphTable[b][i] = 0;
                         graphFile << i << " " << b << endl;
                    }
               }
          }
          graphFile.close ();
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

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
          for ( int i = 0; i < graphNodes; i++ ) {
               graphTable[i] = new int[graphNodes];    
               for ( int b = 0; b < graphNodes; b++ ) {
                    graphTable[i][b] = -1;
               }
          }
          
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

/*
     Generate graph of nodes*nodes
     This will create a multi-dimensioanl array of [nodes][nodes] size.   
*/
int Graph::generateEdges ( ) {
     try {
          for ( int i = 0; i < graphNodes; i++ ) {
               for ( int b = 0; b < graphNodes; b++ ) {
                    /*
                         Run random to figure out if we set an edge at this location and then flip indexes to set it for both nodes 
                    */
                    if ( i != b && graphTable[i][b] == -1 ) {
                         graphTable[i][b] = (rand () % 2 ? 1 : 0 );
                         graphTable[b][i] = graphTable[i][b];
                         if ( graphTable[i][b] ) {
                              graphEdges++;
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
          for ( int i = 0; i < graphNodes; i++ ) {
               if ( graphTable[i] ) {
                    delete [] graphTable[i];
                    graphTable[i] = NULL;
               }
          }
          if ( graphTable ) {
               delete graphTable;
               graphTable = NULL;
          }
          graphNodes = 0;
          graphEdges = 0;
          
          return 1;
     } catch ( ... ) {
          return 0;
     }
}

long Graph::getNumber ( ifstream &file ) {
       string number = "";
       char c = file.get();
       if ( !file.good() ) {
          return -1;
       }
       while ( c != ' ' && c != '\n' && c!='\r' ) {
          number += c;
          c = file.get();
       }
       cout << "Num:" << number <<endl;
       return atoi ( number.c_str () );
}

string Graph::toString ( ) {
     stringstream outputParser;
     for ( int i = 0; i < graphNodes; i++ ) {
          for ( int b = 0; b < graphNodes; b++ ) {
               if ( b != i && graphTable[i][b] == 1 ) {
                    outputParser << i << " " << b << endl;
                    graphTable[b][i] = 0;
               }
          }
     }
     return outputParser.str();
}

