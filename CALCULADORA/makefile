all:
	g++ -c ./SYSTEM/Display/displayVitor.cpp -o displayVitor.o
	g++ -c ./SYSTEM/Console/consoleVitor.cpp -o consoleVitor.o
	g++ -c ./SYSTEM/Cpu/cpuVitor.cpp -o cpuVitor.o
	g++ main.cpp consoleVitor.o displayVitor.o cpuVitor.o -o main
	./main