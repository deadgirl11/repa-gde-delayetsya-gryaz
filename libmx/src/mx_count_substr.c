#include "libmx.h"

int mx_count_substr(const char *str,const  char *sub) {
	int count = 0;
	const char * temp = str;
	if(str == NULL || sub == NULL)
		return -1;
	while((temp = mx_strstr(temp,sub)) != '\0') {
		count++;
		temp++;
		}
	return count;
}
