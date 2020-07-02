#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;


static const size_t kNumPhilosophers = 5;
static const size_t kNumForks = kNumPhilosophers;
static const size_t kNumMeals = 3;

static void think(size_t id) {
    cout << id << " starts thinking " << endl;
    sleep(rand() % 10  * 0.1);
    cout << id << " thinking done " << endl;
}

static void eat(size_t id, mutex& left, mutex& right) {
    left.lock();
    right.lock();
    cout << id << " starts eating am.. " << endl;
    sleep(rand() % 10  * 0.1);
    cout << id << " all done eating " << endl;
    left.unlock();
    right.unlock();
}

static void philosopher(size_t id, mutex& left, mutex& right) {
    for (size_t i = 0; i < 3; i++) {
        think(id);
        eat(id, left, right);
    }
}

int main(int argc, char *argv[]) {
    mutex forks[5];
    thread philosophers[5];
    for (size_t i = 0; i < 5; i++) {
        mutex left = forks[i];
        mutex right = forks[(i+1) % 5];
        philosophers[i] = thread(philosopher, i, ref(left), ref(right));

    }
    for (thread &p : philosophers) p.join();
    return 0;
}

