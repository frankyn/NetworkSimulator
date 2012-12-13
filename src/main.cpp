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

     //GraphRouter ( maxQueueSize for routers , )
     GraphRouter graphRouter ( 30 ); //We just want to reuse the graph so we will create a router based off its information once it's loaded in.
     GraphIO * graphIO = (GraphIO*)&graphRouter; //Use graphRouter Graph by typecasting it into GraphIO so we can use it to load in the file.
     
     
     /*
     if ( !graphRouter.create ( 150 ) ) {
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

     */

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

     /*
          Randomly Select 20 source / destination pairs in the network and transmit create packets to transmit.
          Run for : 1000 seconds // 0 -> 1000 while i = 0 and i < 1000
          Total number of packets generated // need a counter for this.
          Total number of packets that reached destination
          Average packet transmission time for each transmission
          Max, min, and avg time for completion for the transmissions
          Max, min, and avg number of packets dropped at a router.
     */

     for ( int i = 0 ; i < 1000 ; i++ ) {
          if ( ( rand() % 2 ) == 0 ) {
              graphRouter.send ( 20 , 15 );
              graphRouter.send ( 1 , 149 );
              graphRouter.send ( 24 , 32 );
              graphRouter.send ( 35 , 89 );
              graphRouter.send ( 9 , 15 );
              graphRouter.send ( 15 , 7 );
              graphRouter.send ( 11 , 25 );
              graphRouter.send ( 17 , 52 );
              graphRouter.send ( 97 , 12 );
              graphRouter.send ( 105 , 50 );
              graphRouter.send ( 7 , 2 );
              graphRouter.send ( 33 , 82 );
              graphRouter.send ( 5 , 76 );
              graphRouter.send ( 3 , 18 );
              graphRouter.send ( 50 , 56 );
              graphRouter.send ( 20 , 29 );
              graphRouter.send ( 90 , 15 );
              graphRouter.send ( 19 , 74 );
              graphRouter.send ( 23 , 120 );
              graphRouter.send ( 115 , 145 );
          }
          graphRouter.run ( );
     }

     //Print out all gathered statistics
     cout << "Routing Statistics: " << endl;
     cout << "Total number of packets generated: " << graphRouter.getTotalGeneratedPackets ( ) << endl;
     cout << "Total number of packets that reached destination: " << graphRouter.getTotalSuccessfulPackets ( ) << endl;
     
     /*
          We need to add in packet transmission time for each transmission but does that mean per packet?
          I'm just going to print out average packet transmission time for all packets.
     */
     //cout << "Average packet transmission time for each transmission: " << graphRouter.getAveragePacketTransmission ( ) << endl;
      
     //Print out completion time and dropped packet statistics.
     cout << "Time for completion for the transmissions: " << endl
          << "Max: " << graphRouter.getMaxTransmissionTime ( ) << " seconds" << endl
          << "Min: " << graphRouter.getMinTransmissionTime ( ) << " seconds" << endl
          << "Avg: " << graphRouter.getAvgTransmissionTime ( ) << " seconds" << endl;

     cout << "Number for packets dropped at a router: " << endl
          << "Max: " << graphRouter.getMaxLostPackets ( ) << endl
          << "Min: " << graphRouter.getMinLostPackets ( ) << endl
          << "Avg: " << graphRouter.getAvgLostPackets ( ) << endl;
     

     graphIO = NULL;

     exit ( 0 );
     return 0;
}
