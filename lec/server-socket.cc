/**
 * File: server-socket.cc
 * ----------------------
 * Presents the implementation of the createServerSocket function as
 * described in server-socket.h
 */

#include <unistd.h>     // for close
#include <sys/socket.h>     // for socket, bind, accept, listen, etc.
#include <arpa/inet.h>     // for htonl, htons, etc.
#include <cstring>     // memset

static const int kResultAddresses = 1;
int createServerSocket(unsigned short port, int backlog) {
    int s = socket(AF_IN
}
