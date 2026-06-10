all: main
main: main.cpp clock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp clock -o main
clock: clock.h clock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g clock.cpp -o clock
clean:
	rm clock
	rm main