#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <stdio.h>

int main()
{	int socketHandle;

	//create socket

	if((socketHandle=socket(AF_INET, SOCK_STREAM, IPPROTO_IP))<0)
	{	cloase(socketHandle);
		perror("socket");
	}

	int iSocketOption = 0;
	int iSocketOptionLen = sizeof(int);

	struct linger SocketOptionLinger;
	int iSocketOptionLingerLen = sizeof(struct linger);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_NODELAY, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_NODELAY = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_MAXSEG, (char*)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_MAXSEG = &d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_CORK, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TC_CORK = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_KEEPIDLE, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_KEEPIDLE = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_KEEPINVL, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_KEEPINVL = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_KEEPCNT, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_KEEPCNT = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_SYNCNT,(char *)&iSocketOptioon, &iSocketOptionLen);
	print("Socket TCP_SYNCNT = %d\n", iSocketOption);

	getsockopt(socketHandle, IPPROTO_TCP, TCP_LINGER2, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket TCP_LINGER2 = %d\n", iSocketOption);

	getsockopt(socketHandle, SOL_SOCKET, SO_REUSEADDR, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_REUSEADDR = %d\n", iSocketOption);

	getsockopt(socketHandle, SOL_SOCKET, SO_ERROR, (char*)&iSocketoption, &iSocketOptionLen);
	printf("Socket SO_ERROR = %d\n", iSocketOption);

	getsockopt(socketHandle, SOL_SOCKET, SO_BROADCAST, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_BROADCAST = %d\n", iSocketOption);

	getsockopt(socketHandle SOL_SOCKET, SO_KEEPALIVE, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_KEEPALIVE = %D\N", iSocketOption);

	getsockopt(socketHandle SOL_SOCKET, SO_SNDBUF, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_SNDBUF = %d\n", iSocketOption);

	getsockopt(socketHandle SOL_SOCKET, SO_RCVBUF, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_RCVBUF = %d\n", iSocketOption);

	getsockopt(socketHandle SOL_SOCKET, SO_LINGER, (char *)&iSocketOption, &iSocketOptionLen);
	printf("Socket SO_LINGER = %d time = %d\n:, SocketOptionLinger.l_onoff, SocketOptionLinger.l_linger);

	getsockopt(socketHandle, SOL_SOCKET, SO_RCVLOWAT, (char *)&iSocketOption, iSocketOptionLen);
	printf("Socket SO_RCVLOWAT = %d\n", iSocketoption);
}
