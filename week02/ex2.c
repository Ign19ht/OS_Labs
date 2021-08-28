#include <stdio.h>
#include <string.h>

int main() {
    char *string;
    printf("Write your string:\n");
    scanf("%[^\n]s", string);
    printf("Your string in reverse:\n");
    for (int i = strlen(string); i > 0; i--) {
        printf("%c", *(string + i - 1));
    }
    return 0;
}
