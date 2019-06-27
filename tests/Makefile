CC=gcc
CFLAGS=-Wall -Wextra -O3
UNITY_DIR=../unity
SRC_DIR=../src
TEST_FILE=Test_helper_Runner.c
EXTRA_FILES=$(UNITY_DIR)/unity.c $(SRC_DIR)/helper.c Test_helper.c
ELF=test

build: $(TEST_FILE) $(EXTRA_FILES)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(UNITY_DIR) $^ -o $(ELF)

run:
	./$(ELF)

clean:
	rm -f *.o $(ELF) $(TEST_FILE)
	make -C $(UNITY_DIR) clean
