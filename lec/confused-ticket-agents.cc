#include <iostream>
#include <thread>
using namespace std;

static const unsigned int kNumAgents = 10;
static const unsigned int kNumTickets = 250;

static void ticketAgent(size_t id, unsigned int& remains) {
    while (remains > 0) {
        //nanosleep(1);
        remains--;
        cout << "agent # " << id << "sold a ticket , remains: " 
        << remains << endl;
    }
    cout << "agent # " << id << " done !" << endl;
}

int main() {
    unsigned int remains = kNumTickets;
    thread agents[kNumAgents];
    for (size_t i = 0; i < kNumAgents; i++) {
        agents[i] = thread(ticketAgent, 100+i, ref(remains));
    }
    for (thread& agent : agents) {
        agent.join();
    }
    cout << "End of the business!" << endl;
    return 0;
}
