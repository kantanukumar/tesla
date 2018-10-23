#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> /* sockaddr_in */

#include <stdio.h>
#include <string.h>

/* Handler */
#include <signal.h>

#define RECV_DATA_SIZE  10000

void SIGINT_Handler(int sig)
{
	/* block for sometime */
	signal(sig, SIG_IGN);

	printf("\nHandled the signal %d successfully\n", sig);
	/* re-enable the handler */
	signal(SIGINT, SIGINT_Handler);
}

int main()
{
	int sock_fd;
	struct sockaddr_in server;

	char send_data[48];
	char recv_data[RECV_DATA_SIZE];

	char *p = memset(send_data, '\0', RECV_DATA_SIZE);
	memset(recv_data, '\0', RECV_DATA_SIZE);

	printf("Addr of send_data=%p, p=%p size=%lu\n", send_data, p, sizeof(send_data));

	/* install a signal handler */
	signal(SIGINT, SIGINT_Handler);

	/* Create socket */
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	if(sock_fd < 0)
  {
		printf("Scoket create error");
    return 1;
	}

	/* fill the server details */
//	server.sin_addr.s_addr = inet_addr("216.58.196.110"); //google
	server.sin_addr.s_addr = inet_addr("98.138.253.109"); //yahoo
//	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	//while(1)
	{
	  /* Connect to remote server */
  	if(connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
	  {
      perror("connecting to server address failed\n");
  	  return 1;	
	  }

		printf("sending data in every 1 seconds...\n");
	  memset(send_data, '\0', 48);

  	/* Send some data */
	  strncpy(send_data, "GET / HTTP/1.1\r\n\r\n", sizeof(send_data));

    if(send(sock_fd, send_data, 48, 0) < 0)
	  {
	    perror("sending data to server failed");
	  }
    printf("Data sent successfully...\n");
	
  	/* Receive some data */
  	if(recv(sock_fd, recv_data, RECV_DATA_SIZE, 0) < 0 )
  	{
  	  perror("Recv failed...");
  	}
  	else
  	{
  	  printf("Data:\n%s\n", recv_data);
  	}
    memset(recv_data, '\0', RECV_DATA_SIZE);
		printf("sleep 1 seconds...\n");
		sleep(1);
	}

	printf("press anykey to exit\n");
	getchar();
}
