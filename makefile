test: main.o bwindow.o Border.o Agent.o Prey.o
	g++ -o test main.o bwindow.o Border.o Agent.o Prey.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp Obstacle.h Agent.h Prey.h bwindow.h Border.h 
	g++ -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp

Border.o: Border.cpp Border.h
	g++ -c Border.cpp

Agent.o: Agent.cpp Agent.h
	g++ -c Agent.cpp

Prey.o: Prey.cpp Prey.h Agent.h
	g++ -c Prey.cpp

clean :
	rm *.o test