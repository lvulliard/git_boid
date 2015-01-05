test: main.o bwindow.o Border.o Agent.o Prey.o Hunter.o Scene.o
	g++ -o test main.o bwindow.o Border.o Agent.o Prey.o Hunter.o Scene.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp Scene.h Obstacle.h Agent.h Prey.h Hunter.h bwindow.h Border.h DefVal.h
	g++ -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h DefVal.h
	g++ -c bwindow.cpp

Border.o: Border.cpp Border.h DefVal.h
	g++ -c Border.cpp

Agent.o: Agent.cpp Agent.h DefVal.h
	g++ -c Agent.cpp

Prey.o: Prey.cpp Prey.h Agent.h DefVal.h
	g++ -c Prey.cpp

Hunter.o: Hunter.cpp Hunter.h Agent.h DefVal.h
	g++ -c Hunter.cpp

Scene.o: Scene.cpp Scene.h Agent.h Obstacle.h Border.h DefVal.h
	g++ -c Scene.cpp

clean :
	rm *.o test