#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 3490 /* Server的端口 */
#define MAXDATASIZE 100 /*一次可以读的最大字节数 */
int main(int argc, char *argv[])
{
	int sockfd, numbytes, sin_size;
	char buf[MAXDATASIZE] = "Hello, world!";
	struct hostent *he; /* 主机信息 */
	struct sockaddr_in their_addr; /* 对方地址信息 */
	if (argc != 2) {
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}
	/* get the host info */
	if ((he=gethostbyname(argv[1])) == NULL) {
		herror("gethostbyname");
		exit(1);
	}
	if ((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1) {
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT); /* short, NBO */
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8); /* 其余部分设成0 */
	numbytes = sendto(sockfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&their_addr,sizeof(their_addr));
	if (numbytes == -1) {
		perror("sendto");
		exit(1);
	}
	printf("Send: %s\n",buf);
	sleep(1);
	numbytes = recvfrom(sockfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&their_addr, &sin_size);
	if (numbytes == -1) {
		perror("recvfrom");
		exit(1);
	}
	buf[numbytes] = '\0';
	printf("Received: %s\n",buf);
	close(sockfd);
	return 0;
}
