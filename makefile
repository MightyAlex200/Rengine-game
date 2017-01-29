default:Rengine

Rengine: main.o player.o bullet.o enemy.o
	g++ main.o player.o bullet.o enemy.o -o Rengine.run -lsfml-graphics	-lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp

player.o:
	g++ -c player.cpp

bullet.o:
	g++ -c bullet.cpp

enemy.o:
	g++ -c enemy.cpp

clean:
	rm -f *.o *.gch Rengine.run
