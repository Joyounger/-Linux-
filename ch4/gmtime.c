#include <stdio.h>
#include <time.h>


int main()
{
	const time_t now_unix = time((time_t*) 0);
	
	struct tm* now_human;
	now_human = gmtime(&now_unix);
	printf("year--%d\n", now_human->tm_year + 1900);
	printf("month--%d\n", now_human->tm_mon + 1);
	printf("day--%d\n", now_human->tm_mday);
	
	printf("hour--%d\n", now_human->tm_hour);
	printf("min--%d\n", now_human->tm_min);
	printf("sec--%d\n", now_human->tm_sec);
	
	return 0;
}
