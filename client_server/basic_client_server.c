/*
* Objective: Runs a server in always accept mode and return a character
*            on every client request.
*
*/


#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> /* sockaddr_in */

int main(int argc, char **argv)
{
	printf("Hello, World\n");

	// socket
	int server_sockfd = 0;
	int status = 0;
	struct sockaddr_in server;  
	struct sockaddr_in client;  

	server_sockfd = socket(PF_INET, SOCK_STREAM, 0);

	if(server_sockfd < 0)
	{
		perror("Server socket creation failed\n");
	}

	/* Fill the details to bind */
  	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
  	server.sin_port = htons(20000);

	status = bind(server_sockfd, (struct sockaddr *)&server, sizeof(server));

	if(status < 0)
	{
		perror("Binding to socket failed");
		return 1;
  	}

	/* Listen to connection */
	status = listen(server_sockfd, 5);
	if(status < 0)
	{
		perror("Listening on socket failed");
		return 1;
  	}

  	while(1)
  	{
		printf("Waiting for client\n");
		int client_len = sizeof(struct sockaddr_in);
		// status = accept(server_sockfd, (struct sockaddr *)&client, &client_len);

    	status = accept4(server_sockfd, (struct sockaddr *)&client, &client_len, SOCK_NONBLOCK);

    	if(status < 0)
		{
			perror("accept failed\n");
   		}
		else
    	{
			printf("Some data on socket\n");
    	}
  	}

  	close(server_sockfd);

//This is for client
#if 0
	/* Load the server address */
  	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
  	server.sin_port = htons(10000);
#endif
 
	return 0;
}
