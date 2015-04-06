CC=g++
CFLAGS=-c -Wall -Iinclude
LDFLAGS=-lpcap
SOURCES=src/captapp.cpp src/capturer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=netiqcapt

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	    $(CC) $(CFLAGS) $< -o $@

