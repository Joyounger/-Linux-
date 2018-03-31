#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

//server ���ȴ���һ���׽��֣������󶨵�һ�����֣��ٴ���һ���������У���ʼ���ܿͻ�������
int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	
	// 2 ɾ����ǰ���׽��֣�Ϊ����������һ��δ�������׽���
	// unlink("server_socket");
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// 3 �����׽���
	server_address.sin_family = AF_INET;	
	server_address.sin_port = htons(9734);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof server_address;
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
	
	// 4 ����һ�����У���ʼ�ȴ��ͻ���������
	listen(server_sockfd, 5);
	while(1) 
	{
		char ch;		
		printf("server waiting\n");
		
	// 5 ����һ������
		client_len = sizeof client_address;
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, (socklen_t *)&client_len);
		
	// 6 ��client_sockfd�׼����ϵĿͻ����ж�д����
		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		close(client_sockfd);
	}
	
}