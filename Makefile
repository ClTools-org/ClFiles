CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude -std=c11

TARGET = bin/ClFiles
SRC = src/main.c src/files.c

.PHONY: all clean

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
