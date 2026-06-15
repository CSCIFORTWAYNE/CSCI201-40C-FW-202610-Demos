all: main
main: main.cpp clock twelveHrClock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp clock twelveHrClock -o main
clock: clock.h clock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g clock.cpp -o clock
twelveHrClock: clock twelveHrClock.h twelveHrClock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g twelveHrClock.cpp -o twelveHrClock
clean:
	rm clock
	rm twelveHrClock
	rm main