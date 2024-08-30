#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_B = PTHREAD_MUTEX_INITIALIZER;

// Thread function A
void *threadA_proc(void *dt)
{
    cout << "Thread A waiting to get ResourceA" << endl;
    pthread_mutex_lock(&mutex_A);
    cout << "Thread A got ResourceA" << endl;

    sleep(1);

    cout << "Thread A waiting to get ResourceB" << endl;
    pthread_mutex_lock(&mutex_B);
    cout << "Thread A got ResourceB" << endl;

    pthread_mutex_unlock(&mutex_B);
    pthread_mutex_unlock(&mutex_A);
    return nullptr;
}

// Thread function B
// void *threadB_proc(void *dt)
// {
//     cout << "Thread B waiting to get ResourceA" << endl;
//     pthread_mutex_lock(&mutex_A);
//     cout << "Thread B got ResourceA" << endl;

//     sleep(1);

//     cout << "Thread B waiting to get ResourceB" << endl;
//     pthread_mutex_lock(&mutex_B);
//     cout << "Thread B got ResourceB" << endl;

//     pthread_mutex_unlock(&mutex_B);
//     pthread_mutex_unlock(&mutex_A);
//     return nullptr;
// }

void *threadB_proc(void *dt)
{
    cout << "Thread B waiting to get ResourceB" << endl;
    pthread_mutex_lock(&mutex_B);
    cout << "Thread B got ResourceB" << endl;

    sleep(1);

    cout << "Thread B waiting to get ResourceA" << endl;
    pthread_mutex_lock(&mutex_A);
    cout << "Thread B got ResourceA" << endl;

    pthread_mutex_unlock(&mutex_A);
    pthread_mutex_unlock(&mutex_B);
    return nullptr;
}
int main()
{
    pthread_t tidA, tidB;

    // Create two threads
    pthread_create(&tidA, NULL, threadA_proc, NULL);
    pthread_create(&tidB, NULL, threadB_proc, NULL);

    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    cout << "Exit" << endl;

    return 0;
}
