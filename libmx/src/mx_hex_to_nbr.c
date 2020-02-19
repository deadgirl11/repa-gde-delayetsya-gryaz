#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	int i = 0;
	int j;
	int c = 0;
	unsigned long sum = 0;
	while(hex[i] != '\0'){
		i++;
	}
	i = i - 1;
	for(j = 0; hex[j] != '\0';j++){
		if(hex[j] > 64 && hex[j] < 71){
			c = hex[j] - 55; 
		}
		if(hex[j] > 96 && hex[j] < 103){
			c = hex[j] - 87;
		}
		if(hex[j] > 48 && hex[j] < 58){
			c = hex[j] - 48;
		}
	sum += c * mx_pow(16, i);
	i--;
	}
	return sum;
}
