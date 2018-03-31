#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

//client
int main()
{
	//1 
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';
	
	// 2 为客户创建一个套接字
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	
	// 3 根据服务器的情况给套接字命名
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);
	
	// 4 将客户端套接字连接到服务器端套接字
	result = connect(sockfd, (struct sockaddr *)&address, len);
	
	if (result == -1)
	{
		perror("oops: client1");
		exit(1);
	}
	
	// 5 现在可以通过套接字进行读写操作了
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);;
	close(sockfd);
	exit(0);
}

