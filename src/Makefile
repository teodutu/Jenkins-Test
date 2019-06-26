CC=gcc
CFLAGS=-Wall -Wextra -O3
ELF=main

build: main.o helper.o
	$(CC) $^ -o $(ELF)

helper.o: helper.c
	$(CC) $(CFLAGS) $^ -c

main.o: main.c
	$(CC) $(CFLAGS) $^ -c

run: $(ELF)
	./$(ELF) $(str1) $(str2) $(type)

clean:
	rm -f *.o $(ELF)