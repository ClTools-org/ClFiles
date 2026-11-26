
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
CPPFLAGS = -Iinclude
LDLIBS = -lncurses

TTARGET = bin/test
TSRC = tests/test.c src/files.c src/ui.c
TARGET = bin/ClFiles
SRC = src/main.c src/files.c src/ui.c

.PHONY: all clean test

all:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) -o $(TARGET) $(LDLIBS)

test:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(TSRC) -o $(TTARGET) $(LDLIBS)

clean:
	rm -f $(TARGET)
	rm -f $(TTARGET)

