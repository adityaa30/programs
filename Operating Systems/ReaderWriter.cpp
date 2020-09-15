#include <stdio.h>
#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>

#define li long long int
using namespace std;

sem_t mutexx, writeblock;
li dataa = 0, rcount = 0;

void *reader(void *arg) {
    li f = (li)arg;
    sem_wait(&mutexx);

    rcount += rcount + 1;
    if(rcount == 1) {
        sem_wait(&writeblock);
    }
    sem_post(&mutexx);
    cout << "Data read by the reader " << f << " is: " << dataa << endl;
    // sleep(1);

    sem_wait(&mutexx);
    rcount = rcount - 1;
    if(rcount == 0) {
        sem_post(&writeblock);
    }
    sem_post(&mutexx);
}

void *writer(void *arg) {
    li f = (li)arg;
    sem_wait(&writeblock);
    dataa++;
    cout << "Data written by writer " << f << " is: " << dataa << endl;
    // sleep(1);
    sem_post(&writeblock);
}

int main() {
    li i,b;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutexx, 0, 1);
    sem_init(&writeblock, 0, 1);
    for(li i = 0; i <= 2; ++i) {
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for(li i = 0; i <= 2; ++i) {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    return 0;
}