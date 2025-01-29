#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "key_value_store.h"
#include "client_handler.h"

#define MAX_BUFFER_SIZE 1024

void handle_client(int server_fd) {
    int new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        return;
    }
    
    read(new_socket, buffer, MAX_BUFFER_SIZE);
    printf("Received: %s\n", buffer);

    if (strncmp(buffer, "SET", 3) == 0) {
        char *key = strtok(buffer + 4, " ");
        char *value = strtok(NULL, " ");
        set_key_value(key, value);
        send(new_socket, "OK\n", 3, 0);
    } 
    else if (strncmp(buffer, "GET", 3) == 0) {
        char *key = strtok(buffer + 4, " ");
        char *value = get_value(key);
        if (value) {
            send(new_socket, value, strlen(value), 0);
        } else {
            send(new_socket, "NOT FOUND\n", 10, 0);
        }
    } 
    else if (strncmp(buffer, "DEL", 3) == 0) {
        char *key = strtok(buffer + 4, " ");
        delete_key(key);
        send(new_socket, "OK\n", 3, 0);
    } 
    else if (strncmp(buffer, "NUKE", 4) == 0) {
        send(new_socket, "Shutting down server...\n", 24, 0);
        close(new_socket);
        exit(0);
    }
    
    close(new_socket);
}
