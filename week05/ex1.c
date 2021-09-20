#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Hello from myThread#%d\n", *(int*)arg);
    pthread_exit(NULL);
}

int main(void){
    int n;
    printf("Enter N=");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_function, &i)) {
            printf("ERROR IN CREATING myThread#%d!\n", i);
            pthread_exit(NULL);
            return 1;
        } else {
            printf("Thread#%d created!\n", i);
        }
        pthread_join(thread, NULL);
        printf("Thread#%d exits!\n", i);
    }
    return 0;
}

