#include <dirent.h>
#include <stdio.h>
#include "files.h"
#include <string.h>
#include <stdlib.h>


char ** listFiles() {
    printf("Listing files...\n");
	

	char **files = malloc(100 * sizeof(char *));
	int count = 0;

	DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        free(files)
		return NULL;
    }

    struct dirent *entry;

    while ((entry = readdir(dir))  != NULL) {
        files[count] = strdup(entry->d_name);
		count++;
    }

    closedir(dir);

	return files;

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
