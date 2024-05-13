program: prob1.o prob2.o

prob1.o: Problem1/prob1.cpp
	g++ Problem1/prob1.cpp -Wall -g -fsanitize=address -fno-omit-frame-pointer -o prob1

prob2.o: Problem2/prob2.cpp
	g++ Problem2/prob2.cpp -Wall -g -fsanitize=address -fno-omit-frame-pointer -o prob2

.PHONY: clean
clean:
	-@ rm -f prob1 *.o
	-@ rm -f prob2 *.o
