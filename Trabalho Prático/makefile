all: RBTree

RBTree: RBTree.o main.o
	gcc -o RBTree RBTree.o main.o

RBTree.o: RBTree.c RBTree.h
	gcc -c RBTree.c -Wall -Werror -Wextra

main.o: main.c RBTree.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o RBTree