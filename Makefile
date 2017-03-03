project: main.o
	g++ main.o -lwiringPi -lpthread -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi -lpthread
