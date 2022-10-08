all:
	g++ -c ./SYSTEM/Display/displayVitor.cpp -o displayVitor.o
	g++ -c ./SYSTEM/Console/consoleVitor.cpp -o consoleVitor.o
	g++ -c ./SYSTEM/Keyboard/keyboardVitor.cpp -o keyboardVitor.o
	g++ -c ./SYSTEM/Key/keyVitor.cpp -o keyVitor.o
	g++ -c ./SYSTEM/Cpu/cpuVitor.cpp -o cpuVitor.o
	g++ main.cpp consoleVitor.o displayVitor.o cpuVitor.o keyboardVitor.o keyVitor.o -o main
	./main

del:
	rm *.o
	rm main.exe