all: main drink twelveHrClock twentyFourHrClock clock
main: drink twelveHrClock twentyFourHrClock clock main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp drink clock twelveHrClock twentyFourHrClock -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g drink.cpp -o drink
clock: clock.h clock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g clock.cpp -o clock
twelveHrClock: twelveHrClock.h twelveHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twelveHrClock.cpp -o twelveHrClock
twentyFourHrClock: twentyFourHrClock.h twentyFourHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twentyFourHrClock.cpp -o twentyFourHrClock
