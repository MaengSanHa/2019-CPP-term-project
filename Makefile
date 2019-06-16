HEADERS = Map.h
SOURCES = Map.cpp main.cpp
CC = g++
CFLAGS = -std=c++11
EXECUTABLE = pushbox
RM = rm

all : $(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) -lncursesw	# g++ -std=c++11 -o pushbox main.cpp -lncursesw

clean : $(RM) *.o $(EXECUTABLE)