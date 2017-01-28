default:Rengine

Rengine: main.o player.o
	g++ main.o player.o -o Rengine.run -lsfml-graphics	-lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp

player.o:
	g++ -c player.cpp

clean:
	rm -f *.o *.gch Rengine.run
