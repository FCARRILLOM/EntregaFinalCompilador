all: maquina

maquina: main.o cpu.o memoria.o
	g++ -std=c++14 -o maquina main.o cpu.o memoria.o

main.o: main.cpp
	g++ -std=c++14 -c main.cpp 

cpu.o: CPU.cpp
	g++ -std=c++14 -c CPU.cpp

memoria.o: Memoria.cpp
	g++ -std=c++14 -c Memoria.cpp