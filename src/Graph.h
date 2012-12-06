#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef GRAPH_HEADER
#define GRAPH_HEADER
using namespace std;

class Graph {
     public:
          Graph ( );
          ~Graph ( );
          
          int create ( int );
          int generateEdges ( ); //nodes
          int clear ( );
          
          int read ( string );
          int write ( string );
          
          string toString ( );
     private:
          int ** graphTable;
          int graphNodes, graphEdges;
          
          long getNumber ( ifstream& );
};

#endif
