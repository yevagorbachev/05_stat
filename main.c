#include<stdio.h>
#include<stdlib.h>

#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>

char * FILE_PATH = ".bashrc";

void print_metric(long num) {
    char * prefs[5] = {"B","KB","MB","GB","TB"};
    int i;
    for (i = 0; i < 5, num >= 1000; i++, num /= 1000) {}
    printf("%ld %s\n", num, prefs[i]);
}

int main() {
    struct stat meta;
    if (stat(FILE_PATH, &meta) < 0) {
        printf("Error #%d when checking metadata of %s: %s\n", errno, FILE_PATH, strerror(errno));
    }

    printf("Information about file %s:\n", FILE_PATH);

    printf("File size: ");
    print_metric(meta.st_size);
    printf("File permissions: %o\n", meta.st_mode);
    printf("Time of last access: %s\n", ctime(&(meta.st_atime)));

    
}