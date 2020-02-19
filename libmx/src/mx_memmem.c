#include "libmx.h"

static int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        ++s1;
        ++s2;
    }
    return 0;
}

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const char *b = big;
    const char *l = little;

    if (big_len < little_len || !big_len || !little_len) {
        return NULL;
    }
    if (little_len == 1) {
        return mx_memchr(big, (int) *l, big_len);
    }
    size_t i = 0;
    while (i < big_len - little_len + 1) {
        if (mx_strncmp(b, l, little_len) == 0) {
            return (void *)b;
        }
        b++;
        i++;
    }
    return NULL;
}
