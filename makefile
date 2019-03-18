CC=g++
CFLAGS=-W -Wall
LDFLAGS=
EXEC=mastermind
SRC= $(wildcard *.cpp) $(wildcard lib/*.cpp)
HFILE= $(wildcard lib/*.h)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

mastermind: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

mastermind.o: $(HFILE)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
mrproper: clean
	rm -rf $(EXEC)