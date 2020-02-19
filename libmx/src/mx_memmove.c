#include"libmx.h"

void *mx_memmove(void *to, const void *from, size_t numBytes) {
    char *cto = (char *)to;
    char *cfrom = (char *)from;
    char *temp = mx_strnew(numBytes);

    for(unsigned long i = 0; i < numBytes; i++)
        temp[i] = cfrom[i];
    for(unsigned long i = 0; i < numBytes; i++)
        cto[i] = temp[i];
    free(temp);
    return to;
}
