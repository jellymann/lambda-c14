all: main

run: main
	./main

main: main.cpp
	g++ -g -O0 -std=c++1y -fextended-identifiers -fdollars-in-identifiers main.cpp -o main