project: main.o relay.o sentry.o servo_sensor.o
	g++ main.o relay.o sentry.o servo_sensor.o -lwiringPi -lpthread -o project.o

main.o: main.cpp
	g++ -c -std=c++98 main.cpp -lwiringPi

relay.o: ./class_files/relay.cpp ./header_files/relay.h
		g++ -c ./class_files/relay.cpp -lwiringPi

servo_sensor.o: ./class_files/servo_sensor.cpp ./header_files/servo_sensor.h
		g++ -c ./class_files/servo_sensor.cpp -lwiringPi -lpthread

sentry.o: ./class_files/sentry.cpp ./header_files/sentry.h
		g++ -c ./class_files/sentry.cpp -lwiringPi -lpthread

clean:
		rm *.o project
