#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#define MYPORT 3490 /* 监听端口 */
void main()
{
	int sockfd; /* 数据端口 */
	struct sockaddr_in my_addr; /* 自身的地址信息 */
	struct sockaddr_in their_addr; /* 连接对方的地址信息 */
	int sin_size, retval;
	char buf[128];
	char *clientip;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT); /* 网络字节顺序 */
	my_addr.sin_addr.s_addr = INADDR_ANY; /* 自动填本机IP */
	bzero(&(my_addr.sin_zero), 8); /* 其余部分置0 */
	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1) {
		perror("bind");
		exit(1);
	}
/* 主循环 */
	while(1) { 
		retval = recvfrom(sockfd, buf, 128, 0, (struct sockaddr *)&their_addr, &sin_size);
		clientip = inet_ntoa(their_addr.sin_addr);
		printf("Received datagram from %s:receive %s \n",clientip,buf);
		if (retval == 0) {
			perror ("rcvfrom");
			close(sockfd);
			break;
		}
		retval = sendto(sockfd, buf, 128, 0, (struct sockaddr *)&their_addr, sin_size);
	}
}
