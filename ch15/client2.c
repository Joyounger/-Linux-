#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
	struct sockaddr_in address;
	int result;
	char ch = 'A';
	
	// 2 Ϊ�ͻ�����һ���׽���
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// 3 ���ݷ�������������׽�������
	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);
	
	// 4 ���ͻ����׽������ӵ����������׽���
	result = connect(sockfd, (struct sockaddr *)&address, len);
	
	if (result == -1)
	{
		perror("oops: client1");
		exit(1);
	}
	
	// 5 ���ڿ���ͨ���׽��ֽ��ж�д������
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);;
	close(sockfd);
	exit(0);
}

