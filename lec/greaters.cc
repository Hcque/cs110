 /* File: greets.cc
  * ---------------
  * More shop examples of c++ thread
  */

#include <thread>
#include <iostream>
#include <cstdlib>
using namespace std;

static void greet(size_t id) {
    for (size_t i = 0; i < id; i++) {
        cout << "Greeter # " << id << "says hello" << endl;
        struct timespec ts = {
            0, random() % 100000000
        };
        nanosleep(&ts, NULL);
    }
    cout << "Greeter $ " << id << "has issuesd" 
    << "so they go home!" <<  endl;
        
}
static const size_t kNumGreeters = 6;
int main(int argc, char *argv[]) {
    cout << "welcome to greetland" << endl;
    thread greeters[kNumGreeters];
    for (size_t i = 0; i < kNumGreeters; i++) {
        greeters[i] = thread(greet, i+1);
    }
    for (thread &greeter : greeters) {
        greeter.join();
    }
    cout << "all done" << endl;
    return 0;
}

