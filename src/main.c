#include <stdio.h>
#include <ncurses.h>
#include "files.h"

int main() {
    createFile("test.txt");
	listFiles();
	deleteFile("test.txt");
	listFiles();

	return 0;
}
