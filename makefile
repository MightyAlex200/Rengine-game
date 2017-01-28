default:Rengine

Rengine: main.o
	g++ main.o -o Rengine.run -lsfml-graphics	-lsfml-window -lsfml-system

clean:
	rm -f *.o *.gch Rengine.run
