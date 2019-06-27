CC=gcc
CFLAGS=-Wall -Wextra -O3
ELF=test
UNITY_DIR=unity
SRC_DIR=src
TEST_DIR=tests

$(ELF): Test_helper_runner.c
	make build

build: Test_helper_runner.c $(UNITY_DIR)/unity.c $(TEST_DIR)/Test_helper.c $(SRC_DIR)/helper.c
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -I$(SRC_DIR) -I$(TEST_DIR) $^ -o $(ELF)

$(UNITY_DIR)/unity.o: $(UNITY_DIR)/unity.c
	make -C $(UNITY_DIR)

$(TEST_DIR)/Test_helper.o:
	make -C $(TEST_DIR)

$(SRC_DIR)/helper.o:
	make -C $(SRC_DIR)

Test_helper_runner.o: Test_helper_runner.c
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -I$(SRC_DIR) $^ -c

run: $(ELF)
	./$(ELF) $(arg)

clean:
	rm -f *.o $(ELF)
	make -C $(UNITY_DIR) clean
	make -C $(TEST_DIR) clean
	make -C $(SRC_DIR) clean