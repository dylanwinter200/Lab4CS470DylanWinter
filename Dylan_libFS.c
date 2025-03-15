#include "Dylan_libFS.h"
#include <stdlib.h>
#include <string.h>

// Function to create a file
int fileCreate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error creating file");
        return -1;
    }
    fclose(fp);
    return 0;
}

// Function to open an existing file in the specified mode
int fileOpen(const char *filename, FILE **fp, const char *mode) {
    *fp = fopen(filename, mode);
    if (!(*fp)) {
        perror("Error opening file");
        return -1;
    }
    return 0;
}

// Function to write to a file
int fileWrite(FILE *fp, const char *data) {
    if (fp == NULL) {
        fprintf(stderr, "Error: File is not open for writing.\n");
        return -1;
    }
    if (fprintf(fp, "%s", data) < 0) {
        perror("Error writing to file");
        return -1;
    }
    fflush(fp);  // Ensure data is written immediately
    return 0;
}

// Function to read a file
int fileRead(FILE *fp, char *buffer, int size) {
    if (fp == NULL) {
        fprintf(stderr, "Error: File is not open for reading.\n");
        return -1;
    }
    rewind(fp);  // Move file pointer to beginning
    if (!fgets(buffer, size, fp)) {
        perror("Error reading file");
        return -1;
    }
    return 0;
}

// Function to close a file
int fileClose(FILE *fp) {
    if (fp == NULL) {
        fprintf(stderr, "Error: No file is open.\n");
        return -1;
    }
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

// Function to delete a file
int fileDelete(const char *filename) {
    if (remove(filename) != 0) {
        perror("Error deleting file");
        return -1;
    }
    return 0;
}

