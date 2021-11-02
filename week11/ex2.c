#include <dirent.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    DIR *folder = opendir("/");
    struct dirent *file;
    while ((file = readdir(folder)) != NULL) {
        printf("%s\n", file->d_name);
    }
    closedir(folder);
    return 0;
}