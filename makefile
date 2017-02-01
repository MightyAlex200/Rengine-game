cc = g++

default: Rengine.run

Rengine.run: main.o player.o bullet.o enemy.o
	$(cc) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	$(cc) -c $^

player.o: player.cpp
	$(cc) -c $^

bullet.o: bullet.cpp
	$(cc) -c $^

enemy.o: enemy.cpp
	$(cc) -c $^

clean:
	rm -f *.o *.gch Rengine.run
