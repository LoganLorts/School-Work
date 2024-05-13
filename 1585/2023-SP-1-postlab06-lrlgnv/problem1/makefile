program: main.o TrianglePrinter.o funcs.o
	g++ main.o funcs.o TrianglePrinter.o -o program

main.o: main.cpp funcs.h TrianglePrinter.h funcs.cpp TrianglePrinter.cpp
	g++ -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

TrianglePrinter.o: TrianglePrinter.cpp TrianglePrinter.h
	g++ -c TrianglePrinter.cpp

.PHONY: clean
clean:
	-@ rm -f program *.o

