#include <dirent.h>
#include <stdio.h>
#include "files.h"

void listFiles() {
    printf("Listing files...\n");
    
	DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir))  != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
	
	return;
}

int createFile(const char *name) {

	FILE *file = fopen(name, "a");

	if (file == NULL) {
		perror("fopen");
		return 1;
	}

	printf("File created succesfully!\n");

	fclose(file);

	return 0;
}
