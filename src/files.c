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
