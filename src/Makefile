COMPILE  = g++
LINK     = g++
DONTLINK = -c
MAKEOBJ  = -o

all: app clean

app: main.o Creature.o
	$(LINK) main.o Creature.o -o C-game

main.o: main.cpp
	$(COMPILE) $(DONTLINK) main.cpp $(MAKEOBJ) main.o

Creature.o: Creature.hpp Creature.cpp
	$(COMPILE) $(DONTLINK) Creature.cpp $(MAKEOBJ) Creature.o

clean:
	rm *.o
