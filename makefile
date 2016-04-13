# Add dependencies in the first line
DEPENDENCIES=Land.o SquareYard.o

OBJECT_FILES=main.o $(DEPENDENCIES)
TARGET_FILE=sfml-app
LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system

build: $(OBJECT_FILES) 
	g++ main.o -o $(TARGET_FILE) $(DEPENDENCIES) $(LIBRARIES)

%.o: %.cpp
	g++ -c $<

clean:
	rm *o