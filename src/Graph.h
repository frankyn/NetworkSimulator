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
          void setEdge ( int, int );
          void removeEdge ( int, int );
          int getEdge ( int, int );
          int clear ( );
          int size ( );
          int edges ( );
          
          int checkConnectivity ( );
          
          string toString ( );
     private:
          int ** graphTable;
          int graphNodes, graphEdges;

          void checkLocation ( int, int*& );
};

#endif