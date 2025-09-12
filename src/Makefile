CC = g++
CPPFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -L Components -lComponents -g -fsanitize=address -fsanitize=undefined -Wall -Wextra

objects = Entity.o EntityManager.o Game.o main.o


all: $(objects)
	$(MAKE) -C Components
	$(CC) $^ $(CPPFLAGS) -o game_2D

$(objects): %.o: %.cc
	$(CC) -c $^ $(CPPFLAGS) -o $@

clean:
	rm -f *.o
	rm -f Components/*.o
	rm -f Components/*.a
