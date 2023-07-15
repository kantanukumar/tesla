#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

main()
{

  printf("This is server program\n");

  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd <= 0)
  {
    perror("Socket returned error");
    return -1;
  }

  
  

return 0;
}

