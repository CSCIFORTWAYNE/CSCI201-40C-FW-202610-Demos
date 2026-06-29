all: person employee main 
main: main.cpp person employee 
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee  -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
clean:
	rm employee
	rm person
	rm main