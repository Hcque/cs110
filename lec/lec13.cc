#include <iostream>
#include <unistd.h> // for close, write
#include <sys/socket.h>
#include <arpa/inet.h> // for htonl, htons, etc
/*
static void publishTime(int client) {
    time_t rawtime;
    time(&rawtime);
    struct tm *ptm = gmtime(&rawtime);
        

}*/




int main(int argc, char *argv[]) {
    int server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(15536);

    bind(server, (struct sockaddr *)&address, sizeof(address));

    listen(server, 5);
    
    char timestr[12] = {'a', 'b', 'c'};
    int client;
    while (1) {
        client = accept(server, NULL, NULL);

        write(client, timestr, sizeof(timestr));        

    }
    close(client);
    return 0;

}

