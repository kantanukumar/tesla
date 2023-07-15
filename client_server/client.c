// socket related
#include <sys/types.h> 
#include <sys/socket.h>

//printf warning
#include <stdio.h>

#include <arpa/inet.h> /* sockaddr_in */

main()
{
	int sock_fd=0;
	printf("This is client program\n");

	//create a socket now
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket fd is %d\n", sock_fd);

	//connects to server
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = 20000;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(sock_fd, (struct sockaddr *) &server_addr, 8);

	printf("after connect\n");

	printf("client completed\n");
return 0;
}
