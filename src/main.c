#include <stdio.h>
#include <ncurses.h>
#include "files.h"

int main() {
    createFile("test.txt");
	listFiles();
}
