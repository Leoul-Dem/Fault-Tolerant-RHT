CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pthread -DASIO_STANDALONE -I. -Ilibs/net/asio/include
LDFLAGS  := -pthread

SRCS := main.cpp Node.cpp log.cpp request_vote.cpp libs/net/networking.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := rht-node

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
