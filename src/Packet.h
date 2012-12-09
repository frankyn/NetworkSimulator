#ifndef PACKET_HEADER
#define PACKET_HEADER

class Packet {
	public:
		Packet ( );
		~Packet ( );

		void setPath ( int, int );
		void setSize ( int );

		int getSource ( );
		int getDestination ( );
		int getSize ( );

	private:
		int source, destination, size;
};

#endif