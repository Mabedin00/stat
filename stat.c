#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <math.h>

void readable_perm(mode_t mode, char * buffer);
int main(){
    struct stat meta;
    stat("stat.c", &meta);
    printf("Size: %ld \n", meta.st_size);
    printf("Mode: %o \n", meta.st_mode);
    printf("Last Edit: %s \n", ctime(&meta.st_mtime));

    double fileSize = meta.st_size;
    double fileSizeGB = fileSize / 1000000000;
    double fileSizeMB = fileSize / 1000000;
    double fileSizeKB = fileSize / 1000;
    printf("HUMAN READABLE FORMAT %f GB, %f MB, %f KB, %f B \n", fileSizeGB, fileSizeMB, fileSizeKB, fileSize);
    char permission[1];
    readable_perm(meta.st_mode, permission);
    printf("Permissions: %s\n", permission);
    return 0;
}

void readable_perm(mode_t mode, char * buffer){
  char perm[9] = "rwxrwxrwx";
  int i;
    for (i = 0; i < 9; i++){
      if(!(mode & (1 << (8-i)))){
        perm[i] = '-';
      }
    }
  strcat(buffer, perm);
}
