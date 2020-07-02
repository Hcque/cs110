#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

static const unsigned int kNumAgents = 10;
static const unsigned int kNumTickets = 250;

static void ticketAgent(size_t id, unsigned int& remains, mutex& ticketLock) {
    while (1) {
        ticketLock.lock();
        if (remains == 0) break;
        remains--;
        ticketLock.unlock();
        cout << "agent # " << id << "sold a ticket , remains: " 
        << remains << endl;
    }
    ticketLock.unlock();
    cout << "agent # " << id << "all done !" << endl;
}

int main() {
    unsigned int remains = kNumTickets;
    mutex ticketLock;
    thread agents[kNumAgents];
    for (size_t i = 0; i < kNumAgents; i++) {
        agents[i] = thread(ticketAgent, 100+i, ref(remains), ref(ticketLock));
    }
    for (thread& agent : agents) {
        agent.join();
    }
    cout << "End of the business!" << endl;
    return 0;
}
