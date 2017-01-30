default: Rengine.run

Rengine.run: main.o player.o bullet.o enemy.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -c $^

player.o: player.cpp
	g++ -c $^

bullet.o: bullet.cpp
	g++ -c $^

enemy.o: enemy.cpp
	g++ -c $^

clean:
	rm -f *.o *.gch Rengine.run
