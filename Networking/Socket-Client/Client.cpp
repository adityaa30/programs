#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
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
        // Send message
        message = "";
        cout << "Send: ";
        getline(cin, message); 
        send(socketFd , message.c_str(), message.length(), 0);

        // Read received message
        memset(buffer, 0, sizeof(buffer));
        read(socketFd , buffer, sizeof(buffer));
        message = string(buffer);
        cout << "Received: " << message << '\n';
   }
}

int main(int argc, char const *argv[]) 
{ 
	int clientSocketFd = 0; 
	struct sockaddr_in serv_addr; 

	
    if ((clientSocketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        LogError("Socket creation error.");
    else cout << "Socket created.\n"; 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
        LogError("Invalid address / Address not supported ");

	if (connect(clientSocketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        LogError("Connection failed");
    else cout << "Successfully connected.\n";
    
    StartChatting(clientSocketFd);
	return 0; 
} 
