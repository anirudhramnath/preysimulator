# Add dependencies in the first line
DEPENDENCIES=SimulationController Creature CreatureFactory Animal Carnivore Deer Grass Herbivore Land Plant Rabiit Sheep SquareYard Wolf Zombie main

OBJECT_FILES=$(DEPENDENCIES) main.o
TARGET_FILE=sfml-app
LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system

build: $(OBJECT_FILES)
	g++ main.o -o $(TARGET_FILE) $(DEPENDENCIES) $(LIBRARIES)

%.o: %.cpp
	g++ -c $<

clean:
	rm *.o