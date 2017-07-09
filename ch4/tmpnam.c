#include <stdio.h>
#include <stdlib.h>

//警告： the use of `tmpnam' is dangerous, better use `mkstemp'
int main()
{
	char tmpname[L_tmpnam];
	char* filename;
	FILE* tmpfp;
	
	//filename = tmpnam(tmpname);
	tmpfp = tmpfile();
	
	//printf("temp file name is %s\n", filename);
	if (tmpfp) {
		printf("open temp file ok\n");
	} else {
		perror("tmpfile");
	}
	
	exit(0);
}
