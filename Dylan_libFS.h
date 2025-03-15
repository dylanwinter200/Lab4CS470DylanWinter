#ifndef DYLAN_LIBFS_H
#define DYLAN_LIBFS_H

#include <stdio.h>

// File system function prototypes
int fileCreate(const char *filename);
int fileOpen(const char *filename, FILE **fp, const char *mode);
int fileWrite(FILE *fp, const char *data);
int fileRead(FILE *fp, char *buffer, int size);
int fileClose(FILE *fp);
int fileDelete(const char *filename);

#endif // DYLAN_LIBFS_H

