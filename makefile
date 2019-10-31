all: trabalho

trabalho: main.o init.o match.o show.o func.h
	g++ -o trabalho main.o init.o match.o show.o

main.o: main.cpp
	g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic -fopenmp

init.o: init.cpp
	g++ -o init.o init.cpp -c -W -Wall -ansi -pedantic -fopenmp

match.o: match.cpp
	g++ -o match.o match.cpp -c -W -Wall -ansi -pedantic -fopenmp

show.o: show.cpp
	g++ -o show.o show.cpp -c -W -Wall -ansi -pedantic -fopenmp

clean:
	rm -rf *.o *~ trabalho

