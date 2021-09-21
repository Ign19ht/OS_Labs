#include <stdio.h>
#include <pthread.h>

int count = 0;
const int MAX = 1000;
int array[1000];
int consumer_sleep = 0;
int producer_sleep = 0;

void *consumer(void *arg) {
    while (1) {
        printf("Consumer: %d\n", count);
        if (count == 0) consumer_sleep = 1;
        if (consumer_sleep == 0) {
            for (int i = count; i < MAX - 1; i++)
                array[i] = array[i +  1];
            count--;
            if (count == MAX - 1) {
                producer_sleep = 0;
            }
        }
    }
}

void *producer(void *arg) {
    while (1) {
        printf("Producer: %d\n", count);
        if (count == MAX) producer_sleep = 1;
        if (producer_sleep == 0) {
            array[count] = 1;
            count++;
            if (count == 1) {
                consumer_sleep = 0;
            }
        }
    }
}

int main() {
    pthread_t thread_producer;
    pthread_t thread_consumer;
    pthread_create(&thread_consumer, NULL, consumer, NULL);
    pthread_create(&thread_producer, NULL, producer, NULL);
    pthread_exit(NULL);
    return 0;
}


