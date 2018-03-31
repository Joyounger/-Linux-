#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

//server 首先创建一个套接字，将它绑定到一个名字，再创建一个监听队列，开始接受客户的连接
int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	
	// 2 删除以前的套接字，为服务器创建一个未命名的套接字
	// unlink("server_socket");
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// 3 命名套接字
	server_address.sin_family = AF_INET;	
	server_address.sin_port = htons(9734);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof server_address;
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
	
	// 4 创建一个队列，开始等待客户进行连接
	listen(server_sockfd, 5);
	while(1) 
	{
		char ch;		
		printf("server waiting\n");
		
	// 5 接受一个队列
		client_len = sizeof client_address;
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, (socklen_t *)&client_len);
		
	// 6 对client_sockfd套件字上的客户进行读写操作
		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		close(client_sockfd);
	}
	
}