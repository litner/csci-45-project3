project: main.o
	g++ main.o -lwiringPi -llirc_client -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi -llirc_client
