#include <stdio.h>

char *mx_strchr(const char *s, int c) {
    if((c > 225) || (c < 0)) {
        return NULL;
    }
    for(; *s != '\0'; s++) {
        if(*s == c) {
            return (char *) s;
        }
    }
    return NULL;      
}
