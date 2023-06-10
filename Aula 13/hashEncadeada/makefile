all: hash

hash: hash.o main.o
	gcc -o hash hash.o main.o

hash.o: hash.c hash.h
	gcc -c hash.c -Wall -Werror -Wextra

main.o: main.c hash.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o hash