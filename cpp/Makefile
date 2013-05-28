# CXX =		clang++

# CXXFLAGS =	-std=c++11 -stdlib=libc++ -O2 -g -Wall -fmessage-length=0 -DDEBUG=1 -I/usr/local/include -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk

# OBJS =		main.o

# LIBS =

# TARGET =	flovv

# $(TARGET):	$(OBJS)
# 	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

# all:	$(TARGET)

# clean:
# 	rm -f $(OBJS) $(TARGET)

TARGET	= flovv
CC		= clang++
CFLAGS	= -std=c++11 -stdlib=libc++ -O0 -Wall -pedantic 
LFLAGS	= 
SRC		= $(wildcard src/*.cpp)
OBJS	= $(SRC:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o bin/$(TARGET) $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f bin/$(TARGET) $(OBJS)
