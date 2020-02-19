#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	int i = 0;
	if(!str)
		return -2;
	else if(str[i] != '\0') {
		while(str[i]) {
			if(str[i] == c)
				return i;
			i++;
		}
	}
	return -1;
}
