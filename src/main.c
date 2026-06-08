#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int status;
  struct addrinfo req;
  struct addrinfo *res, *p;
  char ipstr[INET6_ADDRSTRLEN];

  if (argc != 2) {
    fprintf(stderr, "usage: showip hostname\n");
    return 1;
  }

  memset(&req, 0, sizeof req);
  req.ai_family = AF_UNSPEC;
  req.ai_socktype = SOCK_STREAM;
  req.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(argv[1], NULL, &req, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 1;
  }

  printf("IP addresses for %s:\n", argv[1]);
  for (p = res; p != NULL; p = p->ai_next) {
    char *ipver;
    void *addr;
    struct sockaddr_in *ipv4;
    struct sockaddr_in6 *ipv6;
    
    if (p->ai_family == AF_INET) {
      ipv4 = (struct sockaddr_in *)p->ai_addr;
      addr = &(ipv4->sin_addr);
      ipver = "IPv4";
    } else {
      ipv6 = (struct sockaddr_in6 *)p->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipver = "IPv6";
    }

    inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
    printf(" %s: %s\n", ipver, ipstr);
  }

  freeaddrinfo(res);
  return 0;
}
