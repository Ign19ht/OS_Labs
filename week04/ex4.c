#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *input = malloc(sizeof(char));
    scanf("%[^\n]s", input);
    printf("%s", input);
    char *command = malloc(sizeof(char));
    int i = 0;
    while (*input && *input != ' ') {
        *(command + i) = *input;
        i++;
        input++;
    }
    char *args[8];
    args[0] = command;
    int arg_counter = 0;
    i = 0;
    while (*input) {
        if (*input == ' ') {
            arg_counter++;
            args[arg_counter] = malloc(sizeof(char));
            i = 0;
        } else {
            *(args[arg_counter] + i) = *input;
            i++;
        }
        input++;
    }
    if (arg_counter == 0) system(command);
    else {
        args[arg_counter + 1] = NULL;
        char *environ[] = {NULL};
        execve(command, args, environ);
    }
}
