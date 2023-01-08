CC = gcc
FLAG = -Wall -g

all: isort.o txtfind.o

isort.o: isort.c
	$(CC) $(FLAG) -o isort.o isort.c

runi:
	./isort.o < sort_input.txt

clean:
	rm -f ./isort.o ./txtfind.o

txtfind.o: txtfind.c
	$(CC) $(FLAG) -o txtfind.o txtfind.c

runt: runtinputa runtinputb

runtinputa:
	./txtfind.o < find_inputa.txt

runtinputb:
	./txtfind.o < find_inputb.txt

.PHONY: clean all

test:
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./txtfind.o < find_inputa.txt
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./txtfind.o < find_inputb.txt
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./isort.o < sort_input.txt
