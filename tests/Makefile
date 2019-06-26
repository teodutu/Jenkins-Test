CC=gcc
CFLAGS=-Wall -Wextra -O3
UNITY_DIR=../unity
SRC_DIR=../src
TEST_FILE=Test_helper.c

build: $(TEST_FILE)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(UNITY_DIR) $^ -c

clean:
	rm -f *.o $(ELF)
	make -C $(UNITY_DIR) clean
