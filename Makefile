CC=gcc
CFLAGS=-Wall -Wextra -O3
ELF=main

$(ELF):
	make build

build: main.o
	$(CC) $^ -o $(ELF)

main.o: main.c
	$(CC) $(CFLAGS) $^ -c

run: $(ELF)
	./$(ELF) $(str1) $(str2) $(type)

clean:
	rm -f *.o $(ELF)
