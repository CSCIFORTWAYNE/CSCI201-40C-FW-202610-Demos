all: person employee main movieTimes twelveHrClock clock
main: main.cpp person employee movieTimes twelveHrClock clock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee movieTimes twelveHrClock clock -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
clock: clock.h clock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g clock.cpp -o clock
twelveHrClock: twelveHrClock.h twelveHrClock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g twelveHrClock.cpp -o twelveHrClock
movieTimes: movieTimes.h movieTimes.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g movieTimes.cpp -o movieTimes
clean:
	rm employee
	rm person
	rm main