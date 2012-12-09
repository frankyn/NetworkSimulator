CC=g++
CFLAGS=-c -Wall -g
EFLAGS=
LDFLAGS= 
SOURCES= main.cpp Graph.h Graph.cpp GraphIO.h GraphIO.cpp GraphRouter.h GraphRouter.cpp Router.h Router.cpp Packet.h Packet.cpp
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE= ../build/NetworkSimulator

all: $(SOURCES) $(EXECUTABLE)

clean: 
	rm build/*

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(EFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

