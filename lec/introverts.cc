/* ----------------------
 * Very simpe example basic threads functionality.
 * for c++11 thread package.
 */

#include <iostream>
#include <thread>
using namespace std;

static void recharge() {
    cout << "I recharged as the time alone" << endl; 
}

static const size_t kNumIntro = 6;
int main(int argc, char *argv[]) {
    cout << "lets hetre from" << kNumIntro << "intros" << endl;
    
    thread introverts[kNumIntro];
    for (thread &introvert : introverts) {
        introvert = thread(recharge);
    }
    for (thread &introvert : introverts) {
        introvert.join();
    }
    return 0;
}




