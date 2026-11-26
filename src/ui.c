#include <ncurses.h>
#include <stdio.h>
#include "ui.h"
#include "files.h"

int initUI(void) {
	WINDOW *screen = initscr();
	
	if (screen != 0) {
		perror("initscr");
		
		return 1;
	}

	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	
	return 0;

}

void cleanupUI(void) {
	endwin();
}

void drawUI(void) {
	int height, width;
	getmaxyx(stdscr, height, width);
	
	const char *title = "ClFiles -- V0.0.1";
	mvprintw(0, (width - strlen(title)) / 2, "%s", title);
	
	char *fileList = listFiles();


}

