# Add dependencies in the first line
DEPENDENCIES=Creature CreatureFactory SimulationController Animal Carnivore Deer Grass Herbivore Land Plant SquareYard Wolf main

OBJECT_FILES=$(DEPENDENCIES) main.o
TARGET_FILE=sfml-app
LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system

build: $(OBJECT_FILES)
	g++ main.o -o $(TARGET_FILE) $(DEPENDENCIES) $(LIBRARIES)

#%.o: %.cpp
#	g++ -c $<

Carnivore.o: Carnivore.cpp Animal.o
	g++ -c Carnivore.cpp

Creature.o: Creature.cpp SimulationController.o
	g++ -c Creature.cpp

Animal.o: Animal.cpp Creature.o
	g++ -c Animal.cpp

CreatureFactory.o: CreatureFactory.cpp Creature.o Grass.o Deer.o Wolf.o
	g++ -c CreatureFactory.cpp

Deer.o: Deer.cpp Herbivore.o SimulationController.o
	g++ -c CarDeernivore.cpp

Land.o: Land.cpp SquareYard.o SimulationController.o Creature.o
	g++ -c Land.cpp

Grass.o: Grass.cpp Plant.o SimulationController.o
	g++ -c Grass.cpp

Herbivore.o: Herbivore.cpp Animal.o SimulationController.o Grass.o
	g++ -c Herbivore.cpp

Plant.o: Plant.cpp Creature.o SimulationController.o
	g++ -c Plant.cpp

SimulationController.o: SimulationController.cpp Creature.o CreatureFactory.o
	g++ -c SimulationController.cpp

Wolf.o: Wolf.cpp SimulationController.o Carnivore.o
	g++ -c Wolf.cpp

SquareYard.o: SquareYard.cpp
	g++ -c SquareYard.cpp

clean:
	rm *.o