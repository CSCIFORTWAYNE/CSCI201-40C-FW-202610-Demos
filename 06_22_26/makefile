all: clock main.cpp
	g++ -pedantic-errors -g main.cpp clock -o main
clock: clock.h clock.cpp
	g++ -c -pedantic-errors -fdiagnostics-color=always -g clock.cpp -o clock
clean:
	rm main