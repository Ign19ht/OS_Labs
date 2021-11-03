
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>

static const char *const evval[3] = {
        "RELEASED",
        "PRESSED",
        "REPEATED"
};

typedef struct key {
    int value;
    struct key *next;
} key;

typedef struct shortcut {
    key *head;
    key *current;
    char *message;
} shortcut;

shortcut *create_shortcut(int n, int array[], char *message) {
    shortcut *sc = malloc(sizeof(shortcut));
    key *head = malloc(sizeof(key));
    head->value = array[0];
    sc->head = head;
    sc->current = head;
    sc->message = message;
    key *current_key = head;
    for (int i = 1; i < n; i++) {
        key *key = malloc(sizeof key);
        key->value = array[i];
        current_key->next = key;
        current_key = key;
    }
    return sc;
}

void check_shortcuts(shortcut *shortcuts[], int n, int value) {
    for (int i = 0; i < n; i++) {
        shortcut *sc = shortcuts[i];
        if (sc->current->value == value) sc->current = sc->current->next;
        else {
            sc->current = sc->head;
            if (sc->current->value == value) sc->current = sc->current->next;
        }
        if (sc->current == NULL) {
            sc->current = sc->head;
            printf("%s\n", sc->message);
        }
    }
}

int main(void) {
    shortcut *shortcuts[2];
    int passed[] = {25, 18};
    int cap[] = {46, 30, 25};
    shortcuts[0] = create_shortcut(2, passed, "I passed the Exam!");
    shortcuts[1] = create_shortcut(3, cap, "Get some cappuccino!");
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    ssize_t n;
    int fd;
    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannoot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }
    while (1) {
        n = read(fd, &ev, sizeof ev);
        if (ev.type == 1 && ev.value == 1) check_shortcuts(shortcuts, 2, ev.code);
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}