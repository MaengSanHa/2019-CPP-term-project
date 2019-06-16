HEADERS = Map.h
SOURCES = Map.cpp
CC = g++
CFLAGS = -std=c++11
EXECUTABLE = main
RM = rm -rf

all : $(SOURCES) $(HEADERS) $(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean : $(RM) *.o $(EXECUTABLE)