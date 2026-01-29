#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of files in the directory
#define MAX_FILES 100

// Maximum file name length
#define MAX_NAME_LENGTH 256

// File structure
typedef struct File {
    char name[MAX_NAME_LENGTH];
    int size;
    char content[1024];   // Fixed content size for simplicity
} File;

// Directory structure
typedef struct Directory {
    File files[MAX_FILES];
    int num_files;
} Directory;

// Function to create a new file
File createFile(const char* name, int size, const char* content) {
    File newFile;

    strncpy(newFile.name, name, MAX_NAME_LENGTH);
    newFile.size = size;
    strncpy(newFile.content, content, sizeof(newFile.content));

    return newFile;
}

// Function to add file to directory
void addFileToDirectory(Directory* directory, File file) {
    if (directory->num_files < MAX_FILES) {
        directory->files[directory->num_files] = file;
        directory->num_files++;
    } else {
        printf("Directory is full. Cannot add more files.\n");
    }
}

// Function to display directory contents
void displayDirectoryContents(const Directory* directory) {
    printf("Directory Contents:\n");

    for (int i = 0; i < directory->num_files; i++) {
        printf("File: %s, Size: %d\n",
               directory->files[i].name,
               directory->files[i].size);
    }
}
int main() {
    Directory directory;
    directory.num_files = 0;

    // Create and add files
    File file1 = createFile("File1.txt", 100, "This is the content of File1.");
    addFileToDirectory(&directory, file1);

    File file2 = createFile("File2.txt", 200, "Content of File2 goes here.");
    addFileToDirectory(&directory, file2);

    // Display directory
    displayDirectoryContents(&directory);

    return 0;

}

