default:Rengine

Rengine: main.o player.o bullet.o
	g++ main.o player.o bullet.o -o Rengine.run -lsfml-graphics	-lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp

player.o:
	g++ -c player.cpp

bullet.o:
	g++ -c bullet.cpp

clean:
	rm -f *.o *.gch Rengine.run
