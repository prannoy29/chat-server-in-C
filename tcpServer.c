#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void main(){

	int socket_server;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;
	char buffer[1024];

	socket_server = socket(AF_INET, SOCK_STREAM, 0);
	printf("Server created.\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(socket_server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("Bind to Port number %d.\n", 4455);

	listen(socket_server, 5);
	printf("Server open for connections...\n");

	newSocket = accept(socket_server, (struct sockaddr*)&newAddr, &addr_size);

	strcpy(buffer, "Hello");
	send(newSocket, buffer, strlen(buffer), 0);
	printf("[+]Closing the connection.\n");


