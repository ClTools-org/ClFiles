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

}

int createFile(const char *name) {

	FILE *file = fopen(name, "wx");

	if (file == NULL) {
		perror("fopen");
		return 1;
	}

	printf("File created succesfully!\n");

	fclose(file);

	return 0;
}

int deleteFile(const char *name) {
	int result = remove(name);

	if (result != 0) {
		perror("remove");
		return 1;
	}

	printf("File deleted successfully!\n");
	
	return 0;
}
