#include <sstream>

#ifndef PACKET_HEADER
#define PACKET_HEADER
using namespace std;
class Packet {
	public:
		Packet ( );
		~Packet ( );

		void setPath ( int, int );
		void setSize ( int );

		int getSource ( );
		int getDestination ( );
		int getSize ( );

		string toString ( );

	private:
		int source, destination, size;
};

#endif