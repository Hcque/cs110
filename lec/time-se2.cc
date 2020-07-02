/*
 * relies on raw socket descriptors and the write system call to 
 * respond to the connectig client.
 */

 #include <iostream>
 #include <ctime>    // for time, gettime, strftime
 #include <sys/socket.h>    // for socket, bind, listener, etc.
 #include <climits>     // for USHRT_MAX
 #include <cstring>     // for strlen
 #include <unistd.h>    // for write
using namespace std;

static const short kDefaultPort = 12345;
static const int kWrongArgumentCount = 1;
static const int kServerStartFailure = 2;
static void publishTime(int client) {
    time_t rawtime;
    time(&rawtime);
    struct tm *ptm = gmtime(&rawtime);
    char timestr[128];
    strftime(timestr, sizeof(timestr), "%c\n", ptm);
    sockbuf sb(client);
    iosockstream ss(&sb);
    ss << timestr << endl;
    sleep 2;
    size_t numBytesWritten = 0;
    size_t numBytesToWrite = strlen(timestr);
    while (numBytesToWritten < numBytesToWrite) {
        numBytesWritten += write(client, timestr + numBytesWritten, numBytesToWrite - numBytesWritten);

    }
    close(client);
}

int createServerSocket(unsigned short port, int backlog) {
    it s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) return kServerSocketFailure;
    if (setsockopt(s, SOL_SOCKET, SOREUSEADDR, &kReuseAddresses, sizeof(int)) < 0) {
        close(s);
        return kServerSocketFailure;
}



int main(int argc, char *argv[]) {
    int server = createServerSocket(12345);
    while (1) {
        int client = accept(server, NULL, NULL);
        publishTime(client);
    }
    return 0;
}
