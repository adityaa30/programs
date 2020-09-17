#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#define BUFFER_SIZE 1024
#define PORT 8080 

using namespace std;

inline void LogError(string message) {
    cout << message << '\n';
    exit(0);
}

void StartChatting(int socketFd) {
    string message;
    char buffer[BUFFER_SIZE];

    while(true) {
        // Read received message
        memset(buffer, 0, sizeof(buffer));
        read(socketFd , buffer, sizeof(buffer));
        message = string(buffer);
        cout << "Received: " << message << '\n';
        
        // Send message
        message = "";
        cout << "Send: ";
        getline(cin, message); 
    	send(socketFd , message.c_str(), message.length(), 0); 
    }
}

int main(int argc, char const *argv[]) { 
	int serverSocketFd, connectedSocket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
	
	// Creating socket file descriptor 
	if ((serverSocketFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
        LogError("Socket failed.");
    else cout << "Socket successfully created.\n";
	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(serverSocketFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
        LogError("setsockopt failed");

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 
	
	// Forcefully attaching socket to the port 8080 
	if (bind(serverSocketFd, (struct sockaddr *) &address, sizeof(address)) < 0)
        LogError("Binding failed");
    else cout << "Binding successfull\n"; 

	if (listen(serverSocketFd, 3) < 0)
        LogError("Listen failed");
    else cout << "Listen successfull\n";
    
    connectedSocket = accept(serverSocketFd, (struct sockaddr *) &address, (socklen_t*) &addrlen);
	if (connectedSocket < 0) LogError("Error in accepting connections");
    else cout << "Successfully accepted connection\n"; 

    StartChatting(connectedSocket);
	return 0; 
} 
