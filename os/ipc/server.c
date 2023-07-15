#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>

int main()
{
  int conn_socket = 0;
  int data_socket = 0;

  struct sockaddr_un sock_name;

  memset(&sock_name, 0, sizeof(struct sockaddr_un));
  sock_name.sun_family = AF_UNIX;
  memcpy(sock_name.sun_path, "/tmp/Demo", 12);

  if (conn_socket = socket(AF_UNIX, SOCK_STREAM, 0) < 0)
  {
    perror("Socket creation failed\n");
    return EXIT_FAILURE;
  }

  if (bind(conn_socket, (struct sockaddr*)&sock_name, sizeof(struct sockaddr_un)) < 0)
  {
    perror("Socket bind failed\n");
    return EXIT_FAILURE;
  }

  if (listen(conn_socket, 5) < 0)
  {
    perror("listen failed\n");
    return EXIT_FAILURE;
  }

  while(1)
  {
    data_socket = accept(conn_socket, (struct sockaddr *)&sock_name, 0);
    if (data_socket < 0)
    {
      perror("accept failure\n");
      return EXIT_FAILURE;
    }

    printf("waiting at accept\n");
  }

  printf("END: server socket will not reach here\n");
  
}
