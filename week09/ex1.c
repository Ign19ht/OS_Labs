#include <stdio.h>

typedef struct page{
    int reference;
    int counter;
}Page;

const int NUMBER_BITS = 31;

void print_pages(Page *pages, int n) {
    for (int i = 0; i < n; i++) printf("i = %3d id = %3d %d\n", i, (pages + i)->reference, (pages + i)->counter);
}

void aging(Page *pages, int n) {
    for (int i = 0; i < n; i++) (pages + i)->counter >>= 1;
}

Page* check_hit(Page *pages, int n, int reference) {
    for (int i = 0; i < n; i++) {
        if ((pages + i)->reference == reference) return pages + i;
    }
    return NULL;
}

Page* find_oldest(Page *pages, int n) {
    Page *oldest = pages;
    for (int i = 0; i < n; i++) {
        if ((pages + i)->counter < oldest->counter) {
            oldest = pages + i;
        }
        if ((pages + i)->reference == 0) return pages + i;
    }
    return oldest;
}

int main(void) {
    FILE *file = fopen("week09\\input.txt", "r");
    printf("Print the number of pages:");
    int n;
    scanf("%d", &n);
    Page pages[n];
    for (int i = 0; i < n; i++) {
        pages[i].reference = 0;
        pages[i].counter = 0;
    }
    if (file == NULL) {
        printf("There is no input file\n");
        return -1;
    }
    int number_of_hits = 0;
    int number_of_misses = 0;
    while (!feof(file)) {
        print_pages(pages, n);
        int current_reference;
        fscanf(file, "%d", &current_reference);
        printf("current page number %d\n\n", current_reference);
        aging(pages, n);
        Page *current_page = check_hit(pages, n, current_reference);
        if (current_page == NULL) {
            number_of_misses++;
            current_page = find_oldest(pages, n);
            current_page->reference = current_reference;
            current_page->counter = 1 << (NUMBER_BITS - 1);
        } else {
            number_of_hits++;
            current_page->counter |= 1 << (NUMBER_BITS - 1);
        }
    }
    float ratio = (float)number_of_hits / number_of_misses;
    printf("hit = %d miss = %d ratio = %f\n", number_of_hits, number_of_misses, ratio);
}