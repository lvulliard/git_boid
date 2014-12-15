test.out: main.o bwindow.o
	g++ -o test.out main.o bwindow.o -lX11 -L/usr/X11R6/lib
main.o: main.cpp
	g++ -c main.cpp 
bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp
clean :
	rm *.o *.out