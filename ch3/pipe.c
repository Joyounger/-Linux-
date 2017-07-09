 #include <unistd.h> 
 #include <stdio.h>
#define INPUT 0 
#define OUTPUT 1 

void main() { 
	int file_descriptors[2]; 
	/*�����ӽ��̺� */ 
	pid_t pid; 
	char buf[256]; 
	int returned_count; 
	
	/*���������ܵ�*/ 
	pipe(file_descriptors); 
	
	/*�����ӽ���*/ 
	if((pid = fork()) == -1) { 
	printf("Error in fork/n"); 
	exit(1); 
	} 
	
	/*ִ���ӽ���*/ 
	if(pid == 0) { 
		printf("in the spawned (child) process.../n"); 
		/*�ӽ����򸸽���д���ݣ��رչܵ��Ķ���*/ 
		close(file_descriptors[INPUT]); 
		write(file_descriptors[OUTPUT], "test data", strlen("test data")); 
	exit(0); 
	} else { 
		/*ִ�и�����*/ 
		printf("in the spawning (parent) process.../n"); 
		/*�����̴ӹܵ���ȡ�ӽ���д�����ݣ��رչܵ���д��*/ 
		close(file_descriptors[OUTPUT]); 
		returned_count = read(file_descriptors[INPUT], buf, sizeof(buf)); 
		printf("%d bytes of data received from spawned process: %s/n", 
		returned_count, buf); 
	} 
} 