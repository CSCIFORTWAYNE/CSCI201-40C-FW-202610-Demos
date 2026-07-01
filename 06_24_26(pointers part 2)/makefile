all: clock twelveHrClock movieTimes main.cpp
	g++ -pedantic-errors -g main.cpp clock twelveHrClock movieTimes -o main
clock: clock.h clock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g clock.cpp -o clock
twelveHrClock: twelveHrClock.h twelveHrClock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g twelveHrClock.cpp -o twelveHrClock
movieTimes: movieTimes.h movieTimes.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g movieTimes.cpp -o movieTimes
clean:
	rm main