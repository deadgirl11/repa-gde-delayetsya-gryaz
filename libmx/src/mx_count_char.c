#include "libmx.h"

int mx_count_char(char *str, char c) {
    int count = 0;

    while (*str) {
        if (*str == c) {
            count++;
        }
        str++;
    }
    return count;
}
