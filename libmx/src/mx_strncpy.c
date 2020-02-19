#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    if (src && len > 0) {
        while (src[i] && len != 0) {
            dst[i] = src[i];
            i++;
            len--;
        }
    }
    dst[i] = '\0';
    return dst;
}
