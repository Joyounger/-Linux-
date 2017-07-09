#include <fcntl.h>
//#include <sys/stat.h>
#include <stdlib.h> 


int main()
{
	open("myfile", O_CREAT, S_IRUSR | S_IXOTH);
	
	exit(0);
	
}

