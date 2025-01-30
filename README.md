# **Basic Redis Implementation in C**

## **Overview**

This project is a basic implementation of Redis, developed to deepen understanding of systems programming, network communication, and socket programming. It features core elements like a simple in-memory key-value store, command parsing, client handling with multiplexing, and a graceful shutdown mechanism. The project includes a server component and a client component to communicate with the server, resembling the structure of Redis commands like `SET`, `GET`, and `DEL`.

## **Features**

- **Key-Value Store**: Set, get, and delete key-value pairs in an in-memory store.
- **Multiplexing**: Efficiently handle multiple client connections using the `select()` system call.
- **Command Parsing**: Supports basic Redis commands such as `SET`, `GET`, and `DEL`.
- **Graceful Shutdown**: A special `NUKE` command to gracefully shut down the server.
- **User-Friendly Prompt**: Displays a prompt for client interactions similar to the Redis CLI.

---

## **Folder Structure**

```bash
basic-redis-implementation/
├── include/
│   ├── client_handler.h
│   ├── key_value_store.h
│   └── server.h
├── src/
│   ├── client_handler.c
│   ├── key_value_store.c
│   ├── main.c
│   └── server.c
├── build/
│   ├── main.o
│   ├── key_value_store.o
│   ├── client_handler.o
│   └── server.o
├── Makefile
├── README.md
├── .gitignore
└── LICENSE
```

### **Explanation of Folder Structure**

1. **`include/`**: Contains header files for the server, key-value store, and client handler.
2. **`src/`**: Contains the source code files for the main program, key-value store functionality, server logic, and client handler logic.
3. **`build/`**: Contains the compiled object files.
4. **`Makefile`**: Defines how the project is compiled and linked.
5. **`README.md`**: This file, containing the documentation for the project.
6. **`.gitignore`**: Specifies files to ignore in Git.
7. **`LICENSE`**: The license for this project, if applicable.

---

## **Detailed Flow of Operations**

### **1. Server Setup**
- The server starts by binding to a specified port and IP address.
- Listens for incoming connections from clients.
- Uses `select()` for handling multiple clients.

### **2. Client Connection**
- Clients connect by specifying the server's IP and port.
- Communication is established through sockets.

### **3. Handling Commands**
- Commands like `SET`, `GET`, `DEL`, and `NUKE` are parsed.
- Key-value operations are performed accordingly.

### **4. Key-Value Store**
- **SET**: Stores a key-value pair in memory.
- **GET**: Retrieves the value associated with a key.
- **DEL**: Deletes a key-value pair.

### **5. Graceful Shutdown**
- The `NUKE` command shuts down the server safely.

### **6. Multiplexing**
- The server uses `select()` to efficiently manage multiple clients.

---

## **Detailed File Descriptions**

### **1. `main.c`**
```c
#include "server.h"

int main() {
    start_server();  // Starts the server
    return 0;
}
```

### **2. `server.c`**
```c
#include "server.h"

void start_server() {
    // Initialize server, bind socket, listen, and handle clients using select().
}
```

### **3. `client_handler.c`**
```c
#include "client_handler.h"

void handle_client(int client_socket) {
    // Parse the command and call functions from key_value_store.c
}
```

### **4. `key_value_store.c`**
```c
#include "key_value_store.h"

void set_key_value(char *key, char *value) {
    // Store key-value pair in memory
}

char *get_value(char *key) {
    // Retrieve value for the given key
}

void delete_key(char *key) {
    // Delete the key-value pair
}
```

---

## **Use Case Flow**

### **1. Start the Server**
```bash
./server
```

### **2. Connect a Client**
```bash
./client
```

### **3. Interact with the Server**
```bash
SET key value
GET key
DEL key
NUKE
```

### **4. Graceful Shutdown**
- The `NUKE` command shuts down the server.

---

## **How to Build and Run**

### **Prerequisites**
- GCC compiler
- Make (for easy builds)

### **Steps to Build**

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd basic-redis-implementation
   ```

2. Run `make` to build the project:
   ```bash
   make
   ```

3. Run the server:
   ```bash
   ./server
   ```

4. Run the client in another terminal:
   ```bash
   ./client
   ```

5. Use commands to interact (`SET`, `GET`, `DEL`, `NUKE`).

---

## Socials 

X - https://x.com/ritikpaltech/

## **Licensing**

This project is licensed under the MIT License.

