TARGET = life

all: life

$(TARGET): main.o printer.o world.o
	g++ main.o printer.o world.o -o life -lopengl32 -lfreeglut -lglu32

main.o: src/main.cpp
	g++ $< -c

printer.o: src/printer.cpp
	g++ $< -c

world.o: src/world.cpp
	g++ $< -c

clean:
	del -rf *.o $(TARGET)