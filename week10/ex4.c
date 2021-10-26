#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void get_path(char *folder_path, char *file_name, char *output) {
    strcpy(output, folder_path);
    strcat(output, "/");
    strcat(output, file_name);
}

int main(void) {
    char* folder_path = malloc(sizeof(char));
    printf("Enter path to folder:");
    scanf("%s", folder_path);
    DIR *folder = opendir(folder_path);
    struct dirent *file;
    struct stat *file_stat;
    char* path = malloc(sizeof(char));
    while ((file = readdir(folder)) != NULL) {
        get_path(folder_path, file->d_name, path);
        stat(path, file_stat);

        printf("FILE - HARD LINK");

        char* names[100];
        int count = 0;
        DIR *folder_temp = opendir(folder_path);
        struct dirent *file_temp;
        struct stat *file_stat_temp;
        while ((file_temp = readdir(folder_temp)) != NULL) {
            get_path(folder_path, file_temp->d_name, path);
            stat(path, file_stat_temp);
            if (file_stat->st_ino == file_stat_temp->st_ino) {
                names[count] = file_temp->d_name;
                count++;
            }
        }
        if (count > 1) {
            printf("%s - ", file->d_name);
            for (int i = 0; i < count; ++i) {
                printf("%s, ", names[i]);
            }
            printf("\n");
        }
        closedir(folder_temp);
    }
    closedir(folder);
}