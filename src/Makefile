COMPILE  = g++
LINK     = g++
DONTLINK = -c
MAKEOBJ  = -o
OBJECTS  = main.o Creature.o Player.o

all: app clean

app: $(OBJECTS)
	$(LINK) $(OBJECTS) -o C-game

main.o: Clibrary.hpp main.cpp
	$(COMPILE) $(DONTLINK) main.cpp $(MAKEOBJ) main.o

Creature.o: Clibrary.hpp Creature.hpp Creature.cpp
	$(COMPILE) $(DONTLINK) Creature.cpp $(MAKEOBJ) Creature.o

Player.o: Clibrary.hpp Player.hpp Player.cpp
	$(COMPILE) $(DONTLINK) Player.cpp $(MAKEOBJ) Player.o

clean:
	rm *.o
