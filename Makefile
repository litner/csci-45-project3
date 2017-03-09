project: main.o ir_robot.o random_player.o relay.o sentry.o servo_sensor.o
	g++ main.o ir_robot.o random_player.o relay.o sentry.o servo_sensor.o -llirc_client -lpthread -lwiringPi -o project.o

main.o: main.cpp
	g++ -c -std=c++98 main.cpp -lwiringPi

relay.o: ./class_files/relay.cpp ./header_files/relay.h
	g++ -c ./class_files/relay.cpp -lwiringPi

servo_sensor.o: ./class_files/servo_sensor.cpp ./header_files/servo_sensor.h
	g++ -c ./class_files/servo_sensor.cpp -lpthread -lwiringPi

sentry.o: ./class_files/sentry.cpp ./header_files/sentry.h
	g++ -c ./class_files/sentry.cpp -lpthread -lwiringPi

ir_robot.o: ./class_files/ir_robot.cpp ./header_files/ir_robot.h
	g++ -c ./class_files/ir_robot.cpp -llirc_client -lwiringPi

random_player.o: ./class_files/random_player.cpp ./header_files/random_player.h
	g++ -c ./class_files/random_player.cpp

clean:
	rm *.o project
