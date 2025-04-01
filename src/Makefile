CC = g++
CPPFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

objects = Game.o main.o

all: $(objects)
	$(CC) $^ $(CPPFLAGS) -o game_2D

$(objects): %.o: %.cc
	$(CC) -c $^ $(CPPFLAGS) -o $@

clean:
	rm -f *.o
