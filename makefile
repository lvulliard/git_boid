test: main.o bwindow.o Border.o
	g++ -o test main.o bwindow.o Border.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp Obstacle.h
	g++ -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp

Border.o: Border.cpp Border.h
	g++ -c Border.cpp

clean :
	rm *.o test