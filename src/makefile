CC=g++
CFLAGS=-c -Wall 
EFLAGS=
LDFLAGS= 
SOURCES= main.cpp Graph.h Graph.cpp GraphIO.h GraphIO.cpp GraphRouter.h GraphRouter.cpp Router.h Router.cpp Packet.h Packet.cpp Chain.h Chain.cpp ListNode.h ListNode.cpp Queue.h Poisson.cpp
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE= ../build/NetworkSimulator

all: $(SOURCES) $(EXECUTABLE)

clean: 
	rm build/*

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(EFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

