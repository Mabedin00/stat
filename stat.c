#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<time.h>
#include <string.h>

int main(){
    struct stat meta;
    stat("stat.c", &meta);
    printf("%ld \n", meta.st_size);
    printf("%o \n", meta.st_mode);
    printf("%s \n", ctime(&meta.st_mtime));
}
