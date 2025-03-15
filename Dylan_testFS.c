#include "Dylan_libFS.h"
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Dylan_Introduction.txt"

void showMenu();

int main() {
    FILE *fp;
    char buffer[512];
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("\nCreating file: %s...\n", FILENAME);
                if (fileCreate(FILENAME) == 0)
                    printf("File created successfully.\n");
                break;

            case 2:
                printf("\nOpening file for writing: %s...\n", FILENAME);
                if (fileOpen(FILENAME, &fp, "w") == 0) {
                    printf("Enter your introduction:\n");
                    const char *intro = "Hello! My name is Dylan.\n"
                                        "I am a computer science student with a passion for coding.\n"
                                        "I enjoy problem-solving and working on new projects.\n\n"
                                        "In my free time, I like learning about history and gaming.\n"
                                        "I am currently improving my skills in system programming.";
                    if (fileWrite(fp, intro) == 0)
                        printf("Data written successfully.\n");
                    fileClose(fp);
                }
                break;

            case 3:
                printf("\nOpening file for reading: %s...\n", FILENAME);
                if (fileOpen(FILENAME, &fp, "r") == 0) {
                    if (fileRead(fp, buffer, sizeof(buffer)) == 0) {
                        printf("File contents:\n%s\n", buffer);
                    }
                    fileClose(fp);
                }
                break;

            case 4:
                printf("\nDeleting file: %s...\n", FILENAME);
                if (fileDelete(FILENAME) == 0)
                    printf("File deleted successfully.\n");
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

// Function to display the menu
void showMenu() {
    printf("\n=== File System Menu ===\n");
    printf("1. Create File\n");
    printf("2. Write to File\n");
    printf("3. Read from File\n");
    printf("4. Delete File\n");
    printf("5. Exit\n");
}

