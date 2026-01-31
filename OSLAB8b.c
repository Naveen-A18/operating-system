#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 100
#define MAX_FILES 100

// File structure
struct FileEntry {
    char name[50];
    char content[1000];
};

// Directory structure
struct Directory {
    char name[50];
    struct FileEntry files[MAX_FILES];
    int num_files;
};

// Global directory list
int num_dirs = 0;
struct Directory directories[MAX_DIRS];

// Create sub-directory under parent
void createDirectory(char parent_name[], char dir_name[]) {

    if (num_dirs >= MAX_DIRS) {
        printf("Error: Maximum directories reached.\n");
        return;
    }

    for (int i = 0; i < num_dirs; i++) {

        if (strcmp(directories[i].name, parent_name) == 0) {

            if (directories[i].num_files >= MAX_FILES) {
                printf("Error: Maximum files reached in %s.\n", parent_name);
                return;
            }

            strcpy(directories[num_dirs].name, dir_name);
            directories[num_dirs].num_files = 0;

            num_dirs++;

            printf("Directory %s created in %s.\n", dir_name, parent_name);
            return;
        }
    }

    printf("Error: Parent directory not found.\n");
}
// Create file inside a directory
void createFile(char dir_name[], char file_name[]) {

    for (int i = 0; i < num_dirs; i++) {

        if (strcmp(directories[i].name, dir_name) == 0) {

            if (directories[i].num_files >= MAX_FILES) {
                printf("Error: Maximum files reached in %s.\n", dir_name);
                return;
            }

            strcpy(directories[i].files[directories[i].num_files].name, file_name);
            directories[i].files[directories[i].num_files].content[0] = '\0';

            directories[i].num_files++;

            printf("File %s created in %s.\n", file_name, dir_name);
            return;
        }
    }

    printf("Error: Directory not found.\n");
}
// List files in directory
void listFiles(char dir_name[]) {

    for (int i = 0; i < num_dirs; i++) {

        if (strcmp(directories[i].name, dir_name) == 0) {

            printf("\nFiles in directory %s:\n", dir_name);

            for (int j = 0; j < directories[i].num_files; j++) {
                printf("%s\n", directories[i].files[j].name);
            }

            return;
        }
    }

    printf("Error: Directory not found.\n");
}
// Main function
int main() {

    // Create root directory
    strcpy(directories[0].name, "root");
    directories[0].num_files = 0;
    num_dirs++;

    // Create sub-directories
    createDirectory("root", "docs");
    createDirectory("root", "images");

    // Create files
    createFile("docs", "document1.txt");
    createFile("docs", "document2.txt");
    createFile("images", "image1.jpg");

    // List files
    listFiles("docs");
    listFiles("images");

    return 0;
}
