CC=g++
CFLAGS=-c -Wall 
EFLAGS=
LDFLAGS= 
SOURCES= main.cpp Graph.h Graph.cpp GraphIO.h GraphIO.cpp GraphRouter.h GraphRouter.cpp Router.h Router.cpp Packet.h Packet.cpp PacketQueue.h PacketQueue.cpp Poisson.h
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE= ../build/NetworkSimulator

all: $(SOURCES) $(EXECUTABLE)

clean: 
	rm *.o
	rm ../build/*

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(EFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

