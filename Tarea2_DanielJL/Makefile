CC = g++
CFLAGS =-c
LDFLAGS =
OBJ = build/
SOURCES = src/Polinomio.cpp src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = a

all: $(SOURCES) build run clean

build: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(OBJ)$(EXECUTABLE)
	mv src/*.o $(OBJ)	
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run:	
	$(OBJ)$(EXECUTABLE)

clean:
	rm -f $(OBJ)*.o
	rm -f $(OBJ)$(EXECUTABLE)  
