#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "key_value_store.h"
#include "server.h"
#include "client_handler.h"

#define PORT 6379
#define HOST "127.0.0.1"

int main() {
    int server_fd = start_server(PORT);
    printf("Server started on %s:%d\n", HOST, PORT);
    
    while (1) {
        handle_client(server_fd);
    }
    
    close(server_fd);
    return 0;
}
