#include<stdio.h>
#include<stdlib.h>

#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>

char * FILE_PATH = "testfile";

int main() {
    struct stat meta;
    if (stat(FILE_PATH, &meta) < 0) {
        printf("Error #%d when checking metadata of %s: %s\n", errno, FILE_PATH, strerror(errno));
    }

    printf("Time of last access: %s\n", ctime(&(meta.st_atime)));
    printf("Time of last edit: %s\n", ctime(&(meta.st_mtime)));
    printf("File size: %d bytes\n", meta.st_size);
}