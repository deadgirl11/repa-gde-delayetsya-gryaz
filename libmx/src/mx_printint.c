#include "libmx.h"

void mx_printint(int n){
	long int m = n;
	int j = 0; int c = 0;
	if(n == 0)
		mx_printchar('0');
	if(m < 0){
		m = -m;
		mx_printchar('-');
	}
	for(long i = m; i > 0; i /= 10){
		c++;
	}
	char rev[c];
	for(long i = m; i > 0; i /= 10){
		j++;
		rev[j] = i % 10 + 48;
	}
	for(int i = j; i > 0; i--){
		mx_printchar(rev[i]);
	}
}
