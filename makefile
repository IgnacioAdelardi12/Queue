CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

SRC = src/queue.c
TEST = tests/queueTests.c
BIN = queue_test

all: $(BIN)

$(BIN): $(SRC) $(TEST)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC) $(TEST)

test: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
