CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lsqlite3

TARGET = server
SRCS = server.cpp database.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJS)