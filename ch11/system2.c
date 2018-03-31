#include <stdlib.h>
#include <stdio.h>

int main() 
{
	printf("running ps with system\n");
	system("ps ax &");
	printf("Done");
	
	exit(0);
}